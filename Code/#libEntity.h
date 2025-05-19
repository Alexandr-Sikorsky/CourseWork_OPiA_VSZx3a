#pragma once

using namespace std;

class Entity{
    public:
        string id;
    public:
        //Entity();
        Entity(string id);
        //Entity(const Entity &str);
        virtual ~Entity(); //common virtual (opredelyaem v basovom classe)
        virtual string get_id() = 0; //clear virtual (opredelyaem v drugom classe)
};