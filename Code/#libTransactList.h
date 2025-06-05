#pragma once

#include "#libTransactNode.h"

using namespace std;

class TransactionList{

    private:
        TransactionNode* head;
        TransactionNode* tail;
        int size;

    public:
        TransactionList();
        ~TransactionList();

        void addTransaction(Transaction* tx);
        bool removeTransaction(string id);  
        Transaction* getTransaction(string id);  
        void displayTransactions(); 
};