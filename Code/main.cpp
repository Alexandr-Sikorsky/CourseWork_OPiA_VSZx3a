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

    //WALLET'S TESTS

    // cout << "--------------------------------------------------------------------------" << endl;

    // Wallet zerowal("000000", 5000, "66666");

    // zerowal.withdraw(47777);
    // zerowal.deposit(-90);

    // cout << "Balance of zerowal: " << zerowal.get_balance() << endl;
    // zerowal.deposit(90); //correct
    // zerowal.withdraw(81); //correct
    // cout << "New balance of zerowal: " << zerowal.get_balance() << endl;
    // cout << "ID of zerowal: " << zerowal.get_id() << endl;


    // cout << "--------------------------------------------------------------------------" << endl;
    // // CLIENT'S TESTS

    // StandardClient client("C100", "John Doe");
    // cout << "1)Client created - ID: " << client.get_id() 
    //      << ", Name: " << client.get_name() 
    //      << ", Type: " << client.get_type() << endl;
    
    // Wallet wallet1("W001", 1000, "-");
    // Wallet wallet2("W002", 2000, "-");
    
    // client.addWallet(&wallet1);
    // client.addWallet(&wallet2);
    
    // cout << "2)Wallets added - Count: " << client.get_max_n_wallets() 
    //      << ", Total balance: " << client.getTotalBalance() << endl;
    
    // try {
    //     Wallet* firstWallet = client.get_wallet_at(0);
    //     cout << "3)First wallet - ID: " << firstWallet->get_id() 
    //          << ", Balance: " << firstWallet->get_balance() << endl;
    // } catch (const out_of_range& e) {
    //     cout << "Error accessing wallet: " << e.what() << endl;
    // }
    
    // GoldClient emptyClient("C101", "Empty");
    // cout << "4)Empty client balance: " << emptyClient.getTotalBalance() << endl;

    // cout<<"5)";
    // StandardClient kiril("10002", "Kirl");
    // TestClient(&kiril);
    // PlatinumClient PL("10003", "Polly");
    // TestClient(&PL);
    // GoldClient carl("10001", "Carlinno");
    // TestClient(&carl);

    //cout << "--------------------------------------------------------------------------" << endl;
    //TRANSACTION'S TESTS
    // Wallet unowal("100001", 6000, "77771");
    // Wallet onewal("000001", 9000, "77777");

    // Transaction* tr1 = new Transaction("tr_1", unowal.get_id(), onewal.get_id(), 560, TxType::TRANSFER, 56);
    // // cout << "INFO ABOUT TRANSACTION: " << tr1->getDetails() << endl;


    // cout << "--------------------------------------------------------------------------" << endl;
    // //TRANSACTION_LIST'S TESTS
    // TransactionList trsp1;

    // Transaction* tr2 = new Transaction("tr_2", onewal.get_id(), onewal.get_id(), 600, TxType::DEPOSIT, 6);
    // trsp1.addTransaction(tr1);
    // trsp1.addTransaction(tr2);
    // trsp1.displayTransactions();
    // bool exist = trsp1.removeTransaction("tr_1");
    // if (exist) {
    //     cout << "\ntr1 deleted!\n";
    // }
    // else {
    //     cout << "\ntr1 not defined!\n";
    // }
    // trsp1.displayTransactions();


    // cout << "--------------------------------------------------------------------------" << endl;
    // CLIENT TREE'S TESTS

    ClientBST cTree;
    GoldClient clients[17] = {{"10010", "Client_A"},
    {"10018", "Client_B"},
    {"10053", "Client_C"},
    {"10024", "Client_D"},
    {"10014", "Client_E"},
    {"10084", "Client_F"},
    {"10234", "Client_G"},
    {"10113", "Client_H"},
    {"10055", "Client_I"},
    {"10034", "Client_J"},
    {"10052", "Client_K"},
    {"10099", "Client_L"},
    {"10444", "Client_M"},
    {"10064", "Client_N"},
    {"10513", "Client_O"},
    {"10070", "Client_P"},
    {"10054", "Client_Q"}
    };
    for (int i = 0; i < 17; i++) {
        cTree.insert(&clients[i]);
    }
    cTree.displayInOrder();

    cout << "--------------------------------------------------------------------------" << endl;
    // ClientBST cTree;
    // GoldClient clients[17] = {
    //     {"10010", "A"},
    //     {"10018", "B"},
    //     {"10053", "DEAD_5"},
    //     {"10024", "DEAD_3"},
    //     {"10014", "DEAD_1"},
    //     {"10084", "F"},
    //     {"10234", "DEAD_4"},
    //     {"10113", "LEFT_CHILD_1"},

    //     {"10055", "K"},
    //     {"10034", "Z"},
    //     {"10052", "DEAD_2"},
    //     {"10099", "LEFT_CHILD_2"},
    //     {"10444", "RIGHT_CHILD_1"},
    //     {"10064", "P"},
    //     {"10513", "RIGHT_CHILD_2"},
    //     {"10070", "WWW"},

    //     { "10054", "NEW_53(4)" }
    // };

    Wallet Awal1("90001", 10000, "-");
    clients[0].addWallet(&Awal1);
    Wallet Awal2("90002", 1600, "-");
    clients[1].addWallet(&Awal2);
    Wallet Awal3("90003", 99, "-");
    clients[2].addWallet(&Awal3);
    Wallet Awal4("90004", 2300, "-");
    clients[3].addWallet(&Awal4);

    // for (int i = 0; i < 17; i++) {
    //     cTree.insert(&clients[i]);
    // }
    // cTree.displayInOrder();

    // cout << cTree.remove("10914") << ":\n";
    // cout << endl;
    // cout << cTree.remove("10014") << ":\n";
    // cTree.displayInOrder();
    // cout << cTree.remove("10014") << ":\n";

    // cout << endl;
    // cout << cTree.remove("10052") << ":\n";
    // cTree.displayInOrder();

    // cout << endl;
    // cout << cTree.remove("10024") << ":\n";
    // cTree.displayInOrder();

    // cout << endl;
    // cout << cTree.remove("10234") << ":\n";
    // cTree.displayInOrder();

    // cout << endl;
    // cout << cTree.remove("10053") << ":\n";
    // cTree.displayInOrder();

    cout << "--------------------------------------------------------------------------" << endl;

    {
        Blockchain bc;
        for (int i = 0; i < 17; i++) {
            bc.addClient(&clients[i]);
        }
        Transaction* tr1 = new Transaction("101", Awal1.get_id(), Awal2.get_id(), 100, TxType::TRANSFER, 1);
        Transaction* tr2 = new Transaction("102", Awal3.get_id(), Awal3.get_id(), 100, TxType::DEPOSIT, 1);
        Transaction* tr3 = new Transaction("103", Awal4.get_id(), Awal4.get_id(), 100, TxType::WITHDRAWAL, 1);
        Transaction* tr4 = new Transaction("104", Awal1.get_id(), Awal2.get_id(), -3, TxType::TRANSFER, 3); //sum<0
        Transaction* tr5 = new Transaction("105", Awal1.get_id(), Awal4.get_id(), 578, TxType::TRANSFER, -77); //commission<0
        bc.processTransaction(tr1);
        bc.processTransaction(tr2);
        bc.processTransaction(tr3);
        bool result1 = bc.processTransaction(tr4);
        cout << "Amount of tr4 < 0: " << (result1 ? "Written to file" : "Writing to file cancelled") << endl;
        bool result2 = bc.processTransaction(tr5);
        cout << "Commission of tr5 < 0: " << (result2 ? "Written to file" : "Writing to file cancelled") << endl;
        bc.displayClients();
        cout<<"---------------------------------------------------"<<endl;
        bc.displayTransactions();
    }


    return 0;
}
