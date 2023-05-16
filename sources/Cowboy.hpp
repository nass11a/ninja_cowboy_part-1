#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "iostream"
#include "string"
#include "Point.hpp"
#include "Character.hpp"
//#include "OldNinja.hpp"
using namespace std;
namespace ariel{

}

const int MAX_BULLETS = 6;
const int hitpoints_num2 = 110;
//class OldNinja;

class Cowboy:public Character{
    
    double bullet_numbers;
    //double hitpoints;
    bool alive;
 
    public:
    
    Cowboy(string name, Point &loc):Character(std::move(name),loc),alive(true),bullet_numbers(MAX_BULLETS){
        //bullet_numbers=6;
        this->sethitpoints(hitpoints_num2);
        //alive=true;
    }

      bool shoot(Character * other);
      string print();

      bool reload();
    bool hasboolets();

    double bulletsnum();
};

#endif