#pragma once

#include "#libClientBST.h"
#include "#libTransactList.h"

class Blockchain { 
public:
	ClientBST clients;
	TransactionList transactions;

	Blockchain();
	void addClient(Client* client);
	bool processTransaction(Transaction* tx);
	void displayClients();
	void displayTransactions();
	~Blockchain();
};