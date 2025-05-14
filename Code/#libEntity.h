#pragma once

using namespace std;

class Entity{
    public:
        string id;
    public:
        Entity();
        Entity(string id);
        Entity(const Entity &str);
        virtual ~Entity();
        virtual string get_id(){};
};