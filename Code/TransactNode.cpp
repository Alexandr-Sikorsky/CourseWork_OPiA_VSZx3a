#include <iostream>

#include "#libTransactNode.h"

using namespace std;

TransactionNode::TransactionNode(Transaction* tx):
    data(tx), prev(nullptr), next(nullptr){};


TransactionNode::~TransactionNode(){};