#pragma once

#include "#libEntity.h"

using namespace std;

enum class TxType {
    TRANSFER,    // Perevod
    DEPOSIT,     // Vnesenie nal
    WITHDRAWAL  // Snyatie nal
};

class Transaction : public Entity {
private:
    string senderWalletId;
    string recipientWalletId;
    double amount;
    TxType type;
    double commission;
    friend class Blockchain;
    friend class TransactionNode;
public:
    Transaction(string id, string senderWalletId, string recipientWalletId, double amount, TxType type, double commission);
    string get_id();
    string getDetails();
    char get_type() {
        switch (type)
        {
        case TxType::TRANSFER:
            return 't';
            break;
        case TxType::DEPOSIT:
            return 'd';
            break;
        case TxType::WITHDRAWAL:
            return 'w';
            break;
        default:
            break;
        }
    };
};
