#include <iostream>
#include <cstdio>
#include <cstring>

#include "#libTransact.h"

using namespace std;

Transaction::Transaction(string id, string senderWalletId, string recipientWalletId, double amount, TxType type, double commission):
    Entity(id){
        this->senderWalletId=senderWalletId;
        this->recipientWalletId=recipientWalletId;
        this->amount=amount;
        this->type=type;
        this->commission=commission;
    }
string Transaction::get_id(){
	return this->id;
}

string Transaction::getDetails(){
    return "Transaction ID: " + id + 
            "\nSender Wallet ID: " + senderWalletId + 
            "\nReceiver Wallet ID: " + recipientWalletId + 
            "\nAmount: " + to_string(amount) + 
            "\nType: " + (type == TxType::TRANSFER ? "TRANSFER" : "DEPOSIT") + 
            "\nCommission: " + to_string(commission);
}