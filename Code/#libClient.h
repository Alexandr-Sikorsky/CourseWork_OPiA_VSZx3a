#pragma once

#include "#libEntity.h"
//#include "#libEntityVec.h"
#include "#libWallet.h"
#include <string>
#include <vector>

using namespace std;

enum ClientType {
	CLIENTTYPE_NONE,
	CLIENTTYPE_STANDARD,
	CLIENTTYPE_PLATINUM,
	CLIENTTYPE_GOLD
};

class Client : public Entity {
protected:
	string name;
	ClientType type;
	//EntityVec wallets;
	vector<Wallet*> vWallets;

public:
	Client(string id, string name);
	void addWallet(Wallet* wallet);
	double getTotalBalance();
	virtual double calculateCommission(double amount) = 0;
	virtual double getMaxTransactionLimit() = 0;
	virtual string getBenefits() = 0;	// added, as every client type has this function
	string get_id() { return id; };
	string get_name() { return name; };
	char get_type() {
		switch (type)
		{
		case CLIENTTYPE_STANDARD:
			return 's';
			break;
		case CLIENTTYPE_PLATINUM:
			return 'p';
			break;
		case CLIENTTYPE_GOLD:
			return 'g';
			break;
		default:
			return 'n';
			break;
		}
	}
	Wallet* get_wallet_at(int n) { return vWallets[n]; }
	int get_max_n_wallets() { return vWallets.size(); }
	~Client() { };
};
