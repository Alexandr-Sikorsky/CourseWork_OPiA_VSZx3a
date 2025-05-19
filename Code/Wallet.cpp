#include <iostream>

#include "#libWallet.h"
#include <string>

using namespace std;

Wallet::Wallet (string id, double balance, string owner_id):
    Entity(id){
        this->balance = balance;
        this->owner_id = owner_id;
}

// Wallet::Wallet (const Wallet &wal):
//     Entity(wal){
//         this->balance = wal.balance;
//         this->owner_id = wal.owner_id;
// }

void Wallet::deposit (double amount){
    if (amount > 0) {
        this->balance += amount;
    }
    else{
        cout<<"Incorrect amount of deposit"<<endl;
    }
}

bool Wallet::withdraw (double amount){
    if (amount > 0 && this->balance >= amount) {
        this->balance -= amount;
        return true; // uspeshnoe snyatie
    }
    cout<<"Error withdraw"<<endl;
    return false; // nedostatochno sredstv ili nevernya summa
}

double Wallet::get_balance(){
    return balance; //this->---?
}

string Wallet::get_id(){
    return id;
}