#include <iostream>

#include "#libEntity.h"
#include "#libEntityVec.h"

using namespace std;

void EntityVec::addEntity(Entity* entity){
    cout << "Adding new entity..." << endl;
    ents.push_back(entity);
}

bool EntityVec::removeEntity(string id){
    for (size_t i = 0; i < ents.size(); ++i) {
        if (ents[i]->id == id) {
            delete ents[i];
            ents.erase(ents.begin() + i);
            cout << "Entity " << id << " was removed." << endl;
            return true;
        }
    }
    cout << "Entity " << id << " not found." << endl;
    return false;
}   

Entity* EntityVec::getEntity(string id) {
    for (size_t i = 0; i < ents.size(); ++i) {
        Entity* currentEntity = ents[i];
        if (currentEntity->id == id) {
            cout << "Entity found: " << currentEntity->id << endl;
            return currentEntity;
        }
    }
    cout << "Entity with ID " << id << " not found." << endl;
    return nullptr;
}

vector<Entity*>& EntityVec::getAllEntities(){
    return ents;
}