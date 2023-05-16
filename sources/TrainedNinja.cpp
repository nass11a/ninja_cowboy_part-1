 #include "TrainedNinja.hpp"

 bool TrainedNinja::slash(Character *other){
      if(!other->isAlive() || !this->isAlive()){
            std::__throw_runtime_error("Error: Character is already dead");
        }
        if(this==other){
            throw std::runtime_error("Error: Character cannot slash itself");
          }
        
            //distance between other and this, if it's less than one meter
            //then other is hit
            if(this->getLocation().distance(other->getLocation())<1){
                other->hit(slash_hitpoints);
                return true;
            }
            else{
                return false;
            }
            other->hit(tweenty);
            return true;

    }
  bool TrainedNinja::move(Character* other) {
    Point current_location = this->getLocation();
    double x = current_location.getX();
    double y = current_location.getY();
    double new_x, new_y;
    if (x < other->getLocation().getX()) {
        new_x = x + speed;  // move right
    } else {
        new_x = x - speed;  // move left
    }
    if (y < other->getLocation().getY()) {
        new_y = y + speed;  // move up
    } else {
        new_y = y - speed;  // move down
    }
    Point new_location(new_x, new_y);
    setlocation(new_location);
    return true;
}


    string TrainedNinja::print(){
        string tal="";
        cout << "OldNinja " << getName() << " is at (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
        return tal;
    }

    double TrainedNinja::getspeed() const{
        return speed;
    }