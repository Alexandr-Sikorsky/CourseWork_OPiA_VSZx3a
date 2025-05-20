#pragma once

#include "#libClient.h"

using namespace std;

class GoldClient : public Client {
public:
	GoldClient(string id, string name);
	double calculateCommission(double amount);
	double getMaxTransaction();
	string getBenefits();
}
