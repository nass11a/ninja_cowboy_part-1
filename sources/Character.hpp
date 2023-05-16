#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "iostream"
#include "string"
#include "Point.hpp"

using namespace std;
namespace ariel{

}

class Character{
  
    public:
    string _name;
    Point _loc;
    double _hitpoints;
    bool alive;
    bool included_;

    Character(string name,const Point &loc):_name(std::move(name)),_loc(loc){
        _hitpoints=100;
        alive=true;
        included_=false;
    }
    virtual ~Character();
    bool isAlive();
    bool move(Character *other);
    Point getLocation()const;
    string getName();
    string print();
    void hit(double hitpoints);
    double distance(const Character *other) const;
    void setlocation(Point loc);
    double gethitpoints();
    void sethitpoints(double hitpoints);
    bool getincluded();
    void setincluded(bool included);
};


#endif