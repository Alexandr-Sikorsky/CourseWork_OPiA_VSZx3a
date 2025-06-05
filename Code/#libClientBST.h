#pragma once

#include "#libClientNode.h"

class ClientBST {
public:
	ClientNode* root;

private:
	void insertNode(ClientNode *&current, Client* client);
	ClientNode* removeNode(ClientNode*& current, string id);
	ClientNode* findNode(ClientNode *current, string id);
	void showTree(const ClientNode* current);

public:
	ClientBST() { root = nullptr; };
	void insert(Client* client) { insertNode(root, client); };
	bool remove(string id) { removeNode(root, id); return false; };
	Client* find(string id) { return findNode(root, id)->data; };
	void displayInOrder() { return showTree(root); };
	~ClientBST() {};
};
