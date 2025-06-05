#pragma once

#include "#libClientBST.h"
#include "#libTransactList.h"

class Blockchain { 
private:
	ClientBST clients;
	TransactionList transactions;
public:
	Blockchain();
	void addClient(Client* client);
	bool processTransaction(Transaction* tx);
	void displayClients();
	void displayTransactions();
	~Blockchain();
};
