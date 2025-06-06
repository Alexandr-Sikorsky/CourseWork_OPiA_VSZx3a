#pragma once

#include <string>
#include "#libTypesClient.h"
#include "#libClientBST.h"
#include "#libTransactList.h"

class Blockchain { 
private:
	string savefileClients;
	string savefileTransactions;
	ClientBST clients;
	TransactionList transactions;

	void writeClientNode(ClientNode* currentNode, string path);
	void writeTransactionList(TransactionNode* currentNode, string path);

public:
	Blockchain(string cpath = "c.txt", string tpath = "t.txt");
	void addClient(Client* client);
	bool processTransaction(Transaction* tx);
	void displayClients();
	void displayTransactions();
	~Blockchain();
};
