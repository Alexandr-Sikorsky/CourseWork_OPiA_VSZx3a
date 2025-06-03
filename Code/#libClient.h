#pragma once

#include "#libClient.h"

using namespace std;


class GoldClient : public Client {
public:
	GoldClient(string id, string name) : Client(id, name) { };
	virtual double calculateCommission(double amount) { return amount * 0.01; };
	virtual double getMaxTransactionLimit() { return 10000; };
	virtual string getBenefits() { return "Priority processing, low fees"; };
};
class PlatinumClient : public Client {
public:
	PlatinumClient(string id, string name) : Client(id, name) { };
	virtual double calculateCommission(double amount) { return amount * 0.02; };
	virtual double getMaxTransactionLimit() { return 5000; };
	virtual string getBenefits() { return "Bonus rewards, moderate fees"; };
};
class StandardClient: public Client {
public:
	StandardClient(string id, string name) : Client(id, name) { };
	virtual double calculateCommission(double amount) { return amount * 0.05; };
	virtual double getMaxTransactionLimit() { return 1000; };
	virtual string getBenefits() { return "Standard access"; };
};
