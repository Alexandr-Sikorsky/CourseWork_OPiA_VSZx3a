#pragma once
#include "#libTransact.h"
using namespace std;


class TransactionList;

class TransactionNode{

    public:
        Transaction* data;
        TransactionNode* prev;
        TransactionNode* next;

    public:
        TransactionNode(Transaction*);
        ~TransactionNode();
};