#pragma once

#include "#libEntity.h"
//#include "#libEntityVec.h"
#include "#libWallet.h"
#include <string>
#include <vector>

using namespace std;

class Client : public Entity {
protected:
	string name;
	//EntityVec wallets;
	vector<Wallet*> vWallets;

public:
	Client(string id, string name);
	void addWallet(Wallet* wallet);
	double getTotalBalance();
	virtual double calculateCommission(double amount) = 0;
	virtual double getMaxTransactionLimit() = 0;
	string get_id() { return id; };
	virtual ~Client() = 0;
};
