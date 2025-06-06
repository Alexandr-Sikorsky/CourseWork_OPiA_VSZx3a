#pragma once

#include "#libClientNode.h"

class ClientBST {
private:
	ClientNode* root;

	void insertNode(ClientNode *&current, Client* client);
	ClientNode* removeNode(ClientNode*& current, string id);
	ClientNode* findNode(ClientNode *current, string id);
	void showTree(const ClientNode* current);

	friend class Blockchain;

public:
	ClientBST() { root = nullptr; };
	void insert(Client* client) { insertNode(root, client); };
	bool remove(string id);
	Client* find(string id);
	void displayInOrder() { return showTree(root); };
	~ClientBST() {};
};
