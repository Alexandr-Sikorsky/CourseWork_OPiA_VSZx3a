#pragma once
#include "#libClient.h"

using namespace std;

class ClientNode {
private:
	Client* data;
	ClientNode* left;
	ClientNode* right;
	friend class ClientBST;
public:
	ClientNode(Client* data) { this->data = data; left = nullptr; right = nullptr; };
	~ClientNode() { left = nullptr; right = nullptr; };
};
