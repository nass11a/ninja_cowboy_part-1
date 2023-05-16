#ifndef POINT_HPP
#define POINT_HPP
#include "iostream"
#include "string"
#include <math.h>

using namespace std;
 namespace ariel{

 }

 class Point{
    double _dxi;
    double _dyi;

    public:
    Point(double dxi, double dyi):_dxi(dxi),_dyi(dyi){}
    Point(Point const &other):_dxi(other._dxi),_dyi(other._dyi){}
    double distance(const Point &other) const{
        double dx_temp = _dxi - other._dxi;
        double dy_temp = _dyi - other._dyi;
        return sqrt(dx_temp*dx_temp + dy_temp*dy_temp);
    
    }

  static Point moveTowards(const Point &source, const Point& dest, double distance) {
    if (distance < 0) {
        throw std::invalid_argument("Distance must be non-negative.");
    }

    double current_distance = source.distance(dest);

    if (current_distance <= distance) {
        // If current distance is less than or equal to the given distance,
        // the source point will reach the destination point by moving towards it
        return dest;
    }

    // Calculate the unit vector from source to dest
    double dx_temp = (dest._dxi - source._dxi) / current_distance;
    double dy_temp = (dest._dyi - source._dyi) / current_distance;

    // Move towards the destination point by the given distance
    double new_x = source._dxi + dx_temp * distance;
    double new_y = source._dyi + dy_temp * distance;
    return Point(new_x, new_y);
}


    static string print(){
        return "";
    }
    double getX() const{
        return _dxi;
    }
    double getY() const{
        return _dyi;
    }
    
 };

 

#endif
