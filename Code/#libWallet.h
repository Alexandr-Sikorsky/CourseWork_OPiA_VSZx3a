#pragma once

#include "#libEntity.h"

using namespace std;

class Wallet: public Entity{

    private:
        //string id; !!!!!!!Oshibka kotoruyu pytalsya nayti minut 40 - 
        //ne pishite v konstruktore peremennyye, kotoryye nasleduyutsya
        double balance;
        string owner_id;
        friend class Transaction;
        friend class Blockchain;
    public:
        Wallet (string id, double balance, string owner_id);
        //Wallet(const Wallet &wal);
        void deposit (double amount);
        bool withdraw (double amount);
        double get_balance();
        string get_id();
};