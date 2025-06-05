#include <iostream>

#include "#libBlockchain.h"

using namespace std;

Blockchain::Blockchain() {

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

}
