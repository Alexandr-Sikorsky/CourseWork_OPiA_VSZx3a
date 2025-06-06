#pragma once

#include <string>
#include "#libTypesClient.h"
#include "#libClientBST.h"
#include "#libTransactList.h"

class Blockchain { 
private:
	string savefile;
	ClientBST clients;
	TransactionList transactions;

	void writeClientNode(ClientNode* currentNode, string path);

public:
	Blockchain(string path = "t.txt");
	void addClient(Client* client);
	bool processTransaction(Transaction* tx);
	void displayClients();
	void displayTransactions();
	~Blockchain();
};
