#pragma once

#include "#libEntity.h"

using namespace std;

enum class TxType{
    TRANSFER,    // Perevod
    DEPOSIT,     // Vnesenie nal
    WITHDRAWAL  // Snyatie nal
};

class Transaction : public Entity{
    public:
        string senderWalletId;
        string recipientWalletId;
        double amount;
        TxType type;
        double commission;
    public:
        Transaction(string id, string senderWalletId, string recipientWalletId, double amount, TxType type, double commission);
        string get_id();
        string getDetails();
};