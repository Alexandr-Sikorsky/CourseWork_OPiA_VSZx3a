#pragma once

#include "#libEntity.h"

using namespace std;

enum class TxType{
    TRANSFER,    // �������
    DEPOSIT,     // �������� ��������
    WITHDRAWAL  // ������ ��������
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