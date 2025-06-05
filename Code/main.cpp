#include <iostream>

#include "#libEntity.h"
#include "#libEntityVec.h"

#include "#libWallet.h"
// #include "#libTransact.h"
#include "#libClient.h"
#include "#libTypesClient.h"

#include "#libClientNode.h"
#include "#libClientBTS.h"

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

    cout << "--------------------------------------------------------------------------" << endl;
    // CLIENT TREE'S TESTS
    ClientBST cTree;
    StandardClient clients[17] ={
        {"10010", "A"},
        {"10018", "B"},
        {"10053", "DEAD_5"},
        {"10024", "DEAD_3"},
        {"10014", "DEAD_1"},
        {"10084", "F"},
        {"10234", "DEAD_4"},
        {"10113", "LEFT_CHILD_1"},

        {"10055", "K"},
        {"10034", "Z"},
        {"10052", "DEAD_2"},
        {"10099", "LEFT_CHILD_2"},
        {"10444", "RIGHT_CHILD_1"},
        {"10064", "P"},
        {"10513", "RIGHT_CHILD_2"},
        {"10070", "WWW"},

        { "10054", "NEW_53(4)" }
    };
    for (int i = 0; i < 17; i++) {
        cTree.insert(&clients[i]);
    }
    cTree.displayInOrder();

    cout << endl;
    cTree.remove("10014");
    cTree.displayInOrder();

    cout << endl;
    cTree.remove("10052");
    cTree.displayInOrder();

    cout << endl;
    cTree.remove("10024");
    cTree.displayInOrder();

    cout << endl;
    cTree.remove("10234");
    cTree.displayInOrder();

    cout << endl;
    cTree.remove("10053");
    cTree.displayInOrder();

    return 0;
}
