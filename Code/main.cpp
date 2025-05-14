#include <iostream>

#include "#libEntity.h"
#include "#libEntityVec.h"

// #include "#libTransact.h"
// #include "#libWallet.h"
// #include "#libClient.h"

// #include "#libStandartCl.h"
// #include "#libGoldCl.h"
// #include "#libPlatinumCl.h"

// #include "#libClientNode.h"
// #include "#libClientBTS.h"

// #include "#libTransactNode.h"
// #include "#libTransactList.h"

// #include "#libBlockchain.h"


using namespace std;

int main() {

    EntityVec vect;

    Entity* ent1 = new Entity("123");
    vect.addEntity(ent1);
    
    Entity* ent2 = new Entity("234");
    vect.addEntity(ent2);

    vect.getEntity("123");
    vect.getEntity("666");

    vect.getAllEntities(); //not print, but not error - good. navernoe dalshe prigoditsa

    vect.removeEntity("123"); 
    vect.removeEntity("555");


    return 0;
}