#include <iostream>

#include "#libEntity.h"
#include <string>

using namespace std;

Entity::Entity(){
    this->id = "";
}
Entity::Entity(string id){
    this->id = id;
}
Entity::Entity(const Entity &str){
    this->id = str.id;
}
Entity::~Entity(){}