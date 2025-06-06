#include <iostream>
#include <fstream>
#include <cmath>
#include "#libBlockchain.h"

using namespace std;

void Blockchain::writeClientNode(ClientNode* currentNode, string path) {
	ofstream out;
	out.open(savefileClients, ios_base::app);
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

	out.close();

	if (currentNode->left != nullptr)
		writeClientNode(currentNode->left, path);
	if (currentNode->right != nullptr)
		writeClientNode(currentNode->right, path);
}
void Blockchain::writeTransactionList(TransactionNode* currentNode, string path) {
	ofstream out;
	out.open(savefileTransactions, ios_base::app);

	if (currentNode != nullptr) {
		Transaction* currentTransact = currentNode->data;
		out << currentTransact->get_id() << 'i' << endl;
		out << currentTransact->senderWalletId << 's' << endl;
		out << currentTransact->recipientWalletId << 'r' << endl;
		out << currentTransact->amount << 'a' << endl;
		out << currentTransact->commission << 'c' << endl;
		out << currentTransact->get_type() << 't' << endl;
		out << endl;
	}

	out.close();

	if (currentNode != nullptr && currentNode->next != nullptr)
		writeTransactionList(currentNode->next, path);
}


Blockchain::Blockchain(string cpath, string tpath) {
	savefileClients = cpath;
	savefileTransactions = tpath;

	ifstream inc;
	inc.open(savefileClients);
	if (inc.is_open()) {
		string s = "";

		Client* lastClient = nullptr;
		string setup_id = "";
		string setup_name = "";

		Wallet* lastWallet = nullptr;
		string setup_wallet_id = "-";

		while (getline(inc, s)) {
			if (s.size() < 1) {
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

	ifstream intr;
	intr.open(savefileTransactions);
	if (intr.is_open()) {
		string s = "";

		string setup_id = "";
		string setup_sender_w_id = "";
		string setup_recipient_w_id = "";
		double setup_amount = 0.0;
		double setup_commission = 0.0;
		while (getline(intr, s)) {
			if (s.size() < 1) {
				continue;
			}

			char si = s.back();	// string identifier
			s.pop_back();
			switch (si)
			{
			case 'i':		// client id
				setup_id = s;
				break;
			case 's':		// sender wallet id
				setup_sender_w_id = s;
				break;
			case 'r':		// recipient wallet id
				setup_recipient_w_id = s;
				break;
			case 'a':		// amount
				setup_amount = stod(s);
				break;
			case 'c':		// commission
				setup_commission = stod(s);
				break;
			case 't':		// client type
				if (s == "t") {
					this->processTransaction(new Transaction(setup_id, setup_sender_w_id, setup_recipient_w_id, setup_amount, TxType::TRANSFER, setup_commission));
				}
				else if (s == "d") {
					this->processTransaction(new Transaction(setup_id, setup_sender_w_id, setup_recipient_w_id, setup_amount, TxType::DEPOSIT, setup_commission));
				}
				else if (s == "w") {
					this->processTransaction(new Transaction(setup_id, setup_sender_w_id, setup_recipient_w_id, setup_amount, TxType::WITHDRAWAL, setup_commission));
				}
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
		(tx->amount > clients.find(tx->senderWalletId)->getMaxTransactionLimit())){
		return false;
	}
	
    if (tx->commission <= 0) {
        return false;
    }

    if (tx->type != TxType::DEPOSIT && tx->commission >= tx->amount) {
        return false;
    }

		switch (tx->type)
	{
	case TxType::TRANSFER:
		if (tx->senderWalletId != tx->recipientWalletId) {
			Client* sender = nullptr;
			for (int i = 0; i < clients.root->data->get_max_n_wallets(); i++) {
				if (clients.root->data->get_wallet_at(i)->get_id() == tx->senderWalletId) {
					sender = clients.root->data;
					break;
				}
			}
			if (sender) {
				transactions.addTransaction(tx);
				ofstream out(savefileTransactions, ios::app);
				out << tx->get_id() << 'i' << endl
					<< tx->senderWalletId << 's' << endl
					<< tx->recipientWalletId << 'r' << endl
					<< tx->amount << 'a' << endl
					<< tx->commission << 'c' << endl
					<< static_cast<char>(tx->type) << 't' << endl << endl;
				out.close();
				
				return true;
				break;
        }
    }
	else{
    	return false;
    	break;}
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
	ofstream outc;
	outc.open(savefileClients);
	if (outc.is_open()) {
		writeClientNode(clients.root, savefileClients);
	}
	outc.close();

	ofstream outt;
	outt.open(savefileTransactions);
	if (outt.is_open()) {
		writeTransactionList(transactions.head, savefileTransactions);
	}
	outt.close();
}
