#pragma once
#include "#libTransact.h"
using namespace std;


class TransactionList;

class TransactionNode{

    private:
        Transaction* data;
        TransactionNode* prev;
        TransactionNode* next;
        friend class TransactionList;
    public:
        TransactionNode(Transaction*);
        ~TransactionNode();
};