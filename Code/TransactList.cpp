#include <iostream>

#include "#libTransactList.h"

using namespace std;

TransactionList::TransactionList(): 
    head(nullptr), tail(nullptr), size(0) {}

TransactionList::~TransactionList() {
    TransactionNode* current = head;
    while (current) {
        TransactionNode* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}

void TransactionList::addTransaction(Transaction* tx) {
    TransactionNode* newNode = new TransactionNode(tx);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

bool TransactionList::removeTransaction(string id) {
    TransactionNode* current = head;
    while (current) {
        if (current->data->get_id() == id) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

Transaction* TransactionList::getTransaction(string id) {
    TransactionNode* current = head;
    while (current) {
        if (current->data->get_id() == id) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void TransactionList::displayTransactions(){
    TransactionNode* current = head;
    while (current) {
        std::cout << current->data->getDetails() << endl << "---------------------------------------------------" << endl;
        current = current->next;
    }
}
