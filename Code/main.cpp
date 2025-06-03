#include <iostream>

#include "#libEntity.h"
#include "#libEntityVec.h"

#include "#libWallet.h"
// #include "#libTransact.h"
#include "#libClient.h"
#include "#libTypesClient.h"

// #include "#libStandartCl.h"
// #include "#libGoldCl.h"
// #include "#libPlatinumCl.h"

// #include "#libClientNode.h"
// #include "#libClientBTS.h"

// #include "#libTransactNode.h"
// #include "#libTransactList.h"

// #include "#libBlockchain.h"


using namespace std;

void TestClient(Client* p) {
    cout << "id: " << p->id << '\t' << "Name: " << p->name << endl;
    cout << "Commision (1000): " << p->calculateCommission(1000) << endl;
    cout << "Max transaction: " << p->getMaxTransactionLimit() << endl;
    cout << p->getBenefits() << endl;
}

int main() {

    //PROVERKA ENTITY i ENTITYVEC

    EntityVec vect;


    //takie operacii nevozmozshni dlya abstractnih classov!!!

    // Entity* ent1 = new Entity("123");
    // vect.addEntity(ent1);
    
    // Entity* ent2 = new Entity("234");
    // vect.addEntity(ent2);


    vect.getEntity("123");
    vect.getEntity("666");

    vect.getAllEntities(); //not print, but not error - good. navernoe dalshe prigoditsa

    vect.removeEntity("123"); 
    vect.removeEntity("555");

    //PROVERKA WALLET

    cout<<"--------------------------------------------------------------------------"<<endl;

    Wallet zerowal("300012", 5000, "66666");

    zerowal.withdraw(47777);
    zerowal.deposit(-90);

    cout<<"Balance of zerowal: "<<zerowal.get_balance()<<endl;
    zerowal.deposit(90);
    zerowal.withdraw(81);
    cout<<"New balance of zerowal: "<<zerowal.get_balance()<<endl;
    cout<<"ID of zerowal: "<<zerowal.get_id()<<endl;

    cout << "--------------------------------------------------------------------------" << endl;
    // CLIENT'S TESTS
    GoldClient carl("10001", "Carlinno");
    TestClient(&carl);
    StandardClient kiril("10002", "Kirl");
    TestClient(&kiril);
    PlatinumClient PL("10003", "Polly");
    TestClient(&PL);
    return 0;
}
