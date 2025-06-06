#include <iostream>

#include "#libClientBST.h"


using namespace std;


void ClientBST::insertNode(ClientNode*& current, Client* client) {
	if (current == nullptr) {
		ClientNode* newNode = new ClientNode(client);
		current = newNode;
	}
	else if (client->get_id() < current->data->get_id()) {
		insertNode(current->left, client);
	}
	else if (client->get_id() > current->data->get_id()) {
		insertNode(current->right, client);
	}
	else {
		cout << "Client is already in the tree" << endl;
	}
}
ClientNode* ClientBST::removeNode(ClientNode*& current, string id) {
	if (current == nullptr) {
		return nullptr;
	}

	if (current->data->get_id() == id) {
		if (current->left == nullptr && current->right == nullptr) {
			delete current;
			return nullptr;
		}
		else if (current->left != nullptr && current->right == nullptr) {
			ClientNode* orphan = current->left;
			delete current;
			return orphan;
		}
		else if (current->right != nullptr && current->left == nullptr) {
			ClientNode* orphan = current->right;
			delete current;
			return orphan;
		}
		else {
			if (current->right->left == nullptr) {
				current->data = current->right->data;
				current->right = current->right->right;
			}
			else {
				ClientNode* lefmostNode = current->right;
				while (lefmostNode->left != nullptr) {
					lefmostNode = lefmostNode->left;
				}
				current->data = lefmostNode->data;
				removeNode(current->right, lefmostNode->data->get_id());
			}
			return current;
		}
	}
	else if (id < current->data->get_id() && current->left != nullptr) {
		current->left = removeNode(current->left, id);
		return current;
	}
	else if (id > current->data->get_id() && current->right != nullptr) {
		current->right = removeNode(current->right, id);
		return current;
	}
	else {
		cout << "No such node!" << endl;
		return current;
	}
	return current;
}
ClientNode* ClientBST::findNode(ClientNode* current, string id) {
	if (current == nullptr) {
		return nullptr;
	}
	else if (current->data->get_id() == id) {
		return current;
	}
	else if (id < current->data->get_id()) {
		return findNode(current->left, id);
	}
	else {
		return findNode(current->right, id);
	}
}
void ClientBST::showTree(const ClientNode* current) {
	if (current == nullptr)
		return;

	showTree(current->left);
	cout << current->data->get_id() << '\t' << current->data->get_name() << '\n';
	showTree(current->right);
}

bool ClientBST::remove(string id) {
	if (findNode(root, id) != nullptr) {
		removeNode(root, id);
		return true;
	}
	else {
		return false;
	}
}
Client* ClientBST::find(string id) {
	ClientNode* p = findNode(root, id);
	if (p != nullptr) {
		return p->data;
	}
	else {
		return NULL;
	}
}
