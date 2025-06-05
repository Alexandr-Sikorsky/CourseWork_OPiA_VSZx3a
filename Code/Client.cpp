#include <iostream>

#include "#libClient.h"
#include <string>

using namespace std;

Client::Client(string id, string name):
	Entity(id) {
	this->name = name;
}
void Client::addWallet(Wallet* wallet) {
	vWallets.push_back(wallet);
}
double Client::getTotalBalance() {
	double total_balance = 0.0;
	for (int i = 0; i < vWallets.size(); i++) {
		total_balance += vWallets.at(i)->get_balance();
	}
	return total_balance;
}
