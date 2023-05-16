#ifndef YoungNinja_HPP
#define YoungNinja_HPP


#include "Character.hpp"
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;


const int tweenty_1 = 20;
const int speed_num_1 = 14;
const int hitpoints_num_1 = 100;
const int slash_hitpoints_1 = 40;

class YoungNinja:public Character{
    double speed;
    //double hitpoints;
    bool alive;
    public:
YoungNinja(string name, const Point& loc) : Character(std::move(name), loc), speed(speed_num_1), alive(true) {
  // Constructor implementation
  this->sethitpoints(hitpoints_num_1);
}

       bool slash(Character *other);
   // bool slash(TrainedNinja *other){
     //   return true;
    //}
    //bool move(Cowboy *other){
      //  return true;
    //}
    bool move(Character *other);
    //   double gethealth(){
      //  return 100;
    //}
    string print();
     //double gethitpoints(){
       // return hitpoints;
    //}
    double getspeed() const;
};

#endif