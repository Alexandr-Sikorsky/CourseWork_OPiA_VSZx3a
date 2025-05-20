#include <iostream>

#include "#libTypesClient.h"

GoldClient::GoldClient(string id, string name):Client(id, name){
	std::cout << "0K\n";
}
double GoldClient::calculateCommission(double amount) {
	return 1.0;
}
double GoldClient::getMaxTransaction() {
	return 1000;
}
string GoldClient::getBenefits() {
	return "Prior processing, low commission";
}
