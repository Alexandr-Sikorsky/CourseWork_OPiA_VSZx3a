#pragma once

using namespace std;

class Entity{
    private:
        string id;
        friend class Transaction; 
        friend class Wallet; 
        friend class Client; 
    public:
        //Entity();
        Entity(string id); //!!!
        //Entity(const Entity &str);
        virtual ~Entity(); //common virtual (opredelyaem v basovom classe)
        virtual string get_id() = 0; //clear virtual (opredelyaem v drugom classe)
};