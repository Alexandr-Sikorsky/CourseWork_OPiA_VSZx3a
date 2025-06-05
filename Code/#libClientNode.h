#pragma once
#include "#libClient.h"

using namespace std;

class ClientNode {
public:
	Client* data;
	ClientNode* left;
	ClientNode* right;

	ClientNode(Client* data) { this->data = data; left = nullptr; right = nullptr; };
	~ClientNode() { left = nullptr; right = nullptr; };
};
