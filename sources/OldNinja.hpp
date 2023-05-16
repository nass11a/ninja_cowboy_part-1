#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Cowboy.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;

//class Cowboy;

const int tweenty1 =20;
const int speed_num1= 8;
const int hitpoints_num1 =150;
const int slash_hitpoints1 = 40;

class OldNinja:public Character{
    double speed;
    //double hitpoints;
    bool alive;

    public:
    OldNinja(string name, Point &loc):Character(std::move(name),loc),speed(speed_num1),alive(true){
      //  speed=speed_num;
        this->sethitpoints(hitpoints_num1);
       // alive=true;
    }
    bool slash(Character *other);
    bool move(Character *other);

    string print();

    double getspeed() const;

};

#endif