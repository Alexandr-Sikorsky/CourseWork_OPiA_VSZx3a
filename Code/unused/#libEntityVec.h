#pragma once

#include <vector>
#include "#libEntity.h"


using namespace std;

class EntityVec{
    public:
        vector<Entity*> ents;
    public:
        void addEntity(Entity* entity);
        bool removeEntity(string id);
        Entity* getEntity(string id);
        vector<Entity*>& getAllEntities();
};