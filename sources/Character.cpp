#include "Character.hpp"

    Character::~Character(){}

    bool  Character::isAlive(){
        if(_hitpoints <= 0){
            alive=false;
        }
        return alive;
    }
    bool Character::getincluded(){
        return included_;
    }
    void Character::setincluded(bool included){
        included_=included;
    }
    bool  Character::move(Character *other){
        //Point temo_loc=other->getLocation();
       // _loc.moveTowards(temo_loc,(1,1));

        return true;
    }
    Point  Character::getLocation()const{
        return _loc;
    }
    string  Character::getName(){
        return _name;
    }
    string  Character::print(){
        string t="";
       return t;
    }
    void  Character::hit(double hitpoints){
        if(hitpoints<0){
            throw std::invalid_argument("Error: negative value!");
        }
        _hitpoints -= hitpoints;
    }
  //  double  Character::distance( Character* other){
   //     return _loc.distance(other->getLocation());
    //}
    double Character::distance(const Character* other) const {
    return _loc.distance(other->getLocation());
}

    void  Character::setlocation(Point loc){
        _loc=loc;
    }
    double  Character::gethitpoints(){
        return _hitpoints;
    }
    void  Character::sethitpoints(double hitpoints){
        _hitpoints=hitpoints;
    }