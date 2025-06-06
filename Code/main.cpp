#include <iostream>

#include "#libEntity.h"
// #include "#libEntityVec.h"

#include "#libWallet.h"
#include "#libTransact.h"
#include "#libClient.h"
#include "#libTypesClient.h"

#include "#libClientNode.h"
#include "#libClientBST.h"

#include "#libTransactNode.h"
#include "#libTransactList.h"

#include "#libBlockchain.h"

using namespace std;

void TestClient(Client* p) {
    cout << "id: " << p->get_id() << '\t' << "Name: " << p->get_name() << endl;
    cout << "Commision (1000): " << p->calculateCommission(1000) << endl;
    cout << "Max transaction: " << p->getMaxTransactionLimit() << endl;
    cout << p->getBenefits() << endl;
}

int main() {

    ////PROVERKA ENTITY i ENTITYVEC

    //EntityVec vect;


    //takie operacii nevozmozshni dlya abstractnih classov!!!

    // Entity* ent1 = new Entity("123");
    // vect.addEntity(ent1);

    // Entity* ent2 = new Entity("234");
    // vect.addEntity(ent2);


    // vect.getEntity("123");
    // vect.getEntity("666");

    // vect.getAllEntities(); //not print, but not error - good. navernoe dalshe prigoditsa

    // vect.removeEntity("123"); 
    // vect.removeEntity("555");

    //PROVERKA WALLET

    //cout << "--------------------------------------------------------------------------" << endl;

    Wallet zerowal("000000", 5000, "66666");

    zerowal.withdraw(47777);
    zerowal.deposit(-90);

    cout << "Balance of zerowal: " << zerowal.get_balance() << endl;
    zerowal.deposit(90);
    zerowal.withdraw(81);
    cout << "New balance of zerowal: " << zerowal.get_balance() << endl;
    cout << "ID of zerowal: " << zerowal.get_id() << endl;

    cout << "--------------------------------------------------------------------------" << endl;
    // CLIENT'S TESTS
    GoldClient carl("10001", "Carlinno");
    TestClient(&carl);
    StandardClient kiril("10002", "Kirl");
    TestClient(&kiril);
    PlatinumClient PL("10003", "Polly");
    TestClient(&PL);

    cout << "--------------------------------------------------------------------------" << endl;
     //TRANSACT's tests
    Wallet onewal("000001", 9000, "77777");

    Transaction* tr1 = new Transaction("tr_1", zerowal.get_id(), onewal.get_id(), 560, TxType::TRANSFER, 56);
    cout << "INFO ABOUT TRANSACTION: " << tr1->getDetails() << endl;


    cout << "--------------------------------------------------------------------------" << endl;
    //TR LISTS
    TransactionList trsp1;

    Transaction* tr2 = new Transaction("tr_2", onewal.get_id(), "CASH", 600, TxType::DEPOSIT, 6);
    trsp1.addTransaction(tr1);
    trsp1.addTransaction(tr2);
    trsp1.displayTransactions();
    bool exist = trsp1.removeTransaction("tr_1");
    if (exist) {
        cout << "\ntr1 deleted!\n";
    }
    else {
        cout << "\ntr1 not defined!\n";
    }
    trsp1.displayTransactions();


    cout << "--------------------------------------------------------------------------" << endl;
    // CLIENT TREE'S TESTS
    ClientBST cTree;
    GoldClient clients[17] = {
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

    Wallet Awal1("90001", 10000, "-");
    clients[0].addWallet(&Awal1);
    Wallet Awal2("90002", 1600, "-");
    clients[1].addWallet(&Awal2);
    Wallet Awal3("90003", 99, "-");
    clients[2].addWallet(&Awal3);
    Wallet Awal4("90004", 2300, "-");
    clients[3].addWallet(&Awal4);

    for (int i = 0; i < 17; i++) {
        cTree.insert(&clients[i]);
    }
    cTree.displayInOrder();

    cout << cTree.remove("10914") << ":\n";
    cout << endl;
    cout << cTree.remove("10014") << ":\n";
    cTree.displayInOrder();
    cout << cTree.remove("10014") << ":\n";

    cout << endl;
    cout << cTree.remove("10052") << ":\n";
    cTree.displayInOrder();

    cout << endl;
    cout << cTree.remove("10024") << ":\n";
    cTree.displayInOrder();

    cout << endl;
    cout << cTree.remove("10234") << ":\n";
    cTree.displayInOrder();

    cout << endl;
    cout << cTree.remove("10053") << ":\n";
    cTree.displayInOrder();

    cout << "--------------------------------------------------------------------------" << endl;

    {
        Blockchain bc;
        for (int i = 0; i < 17; i++) {
            bc.addClient(&clients[i]);
        }
        Transaction* tr1 = new Transaction("101", Awal1.get_id(), Awal2.get_id(), 100, TxType::TRANSFER, 10);
        Transaction* tr2 = new Transaction("102", Awal2.get_id(), Awal3.get_id(), 1000, TxType::TRANSFER, 100);
        Transaction* tr3 = new Transaction("103", Awal3.get_id(), Awal3.get_id(), 100, TxType::DEPOSIT, 10);
        Transaction* tr4 = new Transaction("104", Awal4.get_id(), Awal4.get_id(), 100, TxType::WITHDRAWAL, 10);
        bc.processTransaction(tr1);
        bc.processTransaction(tr2);
        bc.processTransaction(tr3);
        bc.processTransaction(tr4);
        //bc.displayClients();
    }

    return 0;
}
