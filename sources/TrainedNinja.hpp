#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;


//class YountNinja;

const int tweenty = 20;
const int speed_num = 12;
const int hitpoints_num = 120;
const int slash_hitpoints = 40;

class TrainedNinja:public Character{
    double speed;
    //double hitpoints;
    bool alive;

    public:
    TrainedNinja(string name,const Point& loc) : Character(std::move(name), std::move(loc)), speed(speed_num), alive(true) {
  // Constructor implementation

       // speed=speed_num;
        this->sethitpoints(hitpoints_num);
        //alive=true;
    }
    bool slash(Character *other);
    
    bool move(Character *other);

    string print();

    double getspeed() const;
};

#endif