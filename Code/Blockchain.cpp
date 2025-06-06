#include <iostream>
#include <fstream>

#include "#libBlockchain.h"

using namespace std;


void Blockchain::writeClientNode(ClientNode* currentNode, string path) {
	ofstream out;
	out.open(savefile, ios_base::app);
	Client* currentClient = currentNode->data;
	out << currentClient->get_id() << 'i' << endl;
	out << currentClient->get_name() << 'n' << endl;
	out << currentClient->get_type() << 't' << endl;
	for (int i = 0; i < currentClient->get_max_n_wallets(); i++) {
		Wallet* wal = currentClient->get_wallet_at(i);
		out << wal->id << 'w' << endl;
		out << wal->balance << 'b' << endl;
	}
	out << endl;

	if (currentNode->left != nullptr)
		writeClientNode(currentNode->left, path);
	if (currentNode->right != nullptr)
		writeClientNode(currentNode->right, path);
}

Blockchain::Blockchain(string path) {
	savefile = path;

	ifstream in;
	in.open(savefile);
	if (in.is_open()) {
		string s = "";

		Client* lastClient = nullptr;
		string setup_id = "";
		string setup_name = "";

		Wallet* lastWallet = nullptr;
		string setup_wallet_id = "-";

		while (getline(in, s)) {
			if (s.size() < 1) {
				cout << lastClient->get_name() << '\t' << lastClient->get_max_n_wallets() << endl;
				this->addClient(lastClient);
				continue;
			}

			char si = s.back();	// string identifier
			s.pop_back();
			switch (si)
			{
			case 'i':		// client id
				setup_id = s;
				break;
			case 'n':		// client name
				setup_name = s;
				break;
			case 't':		// client type
				if (s == "s") {
					lastClient = new StandardClient(setup_id, setup_name);
				}
				else if (s == "p") {
					lastClient = new PlatinumClient(setup_id, setup_name);
				}
				else if (s == "g") {
					lastClient = new GoldClient(setup_id, setup_name);
				}
				break;
			case 'w':		// wallet id
				setup_wallet_id = s;
				break;
			case 'b':		// wallet balance + creation of wallet
				lastWallet = new Wallet(setup_wallet_id, stod(s), "-");
				lastClient->addWallet(lastWallet);
				break;
			default:
				break;
			}
		}
	}
}
void Blockchain::addClient(Client* client) {
	clients.insert(client);
}
bool Blockchain::processTransaction(Transaction* tx) {
	if (tx->amount <= 0 || tx->commission <= 0) {
		return false;
	}
	if (clients.find(tx->senderWalletId) != nullptr &&
		(tx->amount > clients.find(tx->senderWalletId)->getMaxTransactionLimit())) {
		return false;
	}

	switch (tx->type)
	{
	case TxType::TRANSFER:
		if (tx->senderWalletId != tx->recipientWalletId &&
			clients.find(tx->recipientWalletId) != nullptr) {
			transactions.addTransaction(tx);
			return true;
		}
		else {
			return false;
		}
		break;
	case TxType::DEPOSIT:
		if (tx->senderWalletId == tx->recipientWalletId) {
			transactions.addTransaction(tx);
			return true;
		}
		else {
			return false;
		}
		break;
	case TxType::WITHDRAWAL:
		if (tx->senderWalletId == tx->recipientWalletId) {
			transactions.addTransaction(tx);
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		cout << "ERROR" << endl;
		return false;
		break;
	}
	return false;
}
void Blockchain::displayClients() {
	clients.displayInOrder();
}
void Blockchain::displayTransactions() {
	transactions.displayTransactions();
}
Blockchain::~Blockchain() {
	ofstream out;
	out.open(savefile);
	if (out.is_open()) {
		writeClientNode(clients.root, savefile);
	}
	out.close();
}
