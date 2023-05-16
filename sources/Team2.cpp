 #include "Team2.hpp"

 void Team2::add(Character *charac){
        if (team2_old_ninjas.size() + team2_cowboy_ninjas.size() +  team2_trained_ninjas.size() + team2_young_ninjas.size() == 10) {
        throw std::runtime_error("Team is already full");
    }
        if(charac->distance(&_leader)<min){
            min=charac->distance(&_leader);
            _leader2=charac;
        }
         if(charac->getincluded() == true){
        throw std::runtime_error("Character is already in a team");
    }
        if(typeid(*charac)==typeid(Cowboy)){
            Cowboy* leader_temp2 = dynamic_cast<Cowboy*>(charac);
            team2_cowboy_ninjas.push_back(leader_temp2);
            leader_temp2->setincluded(true);
        }

        else if (typeid(*charac)==typeid(TrainedNinja)){
            TrainedNinja* leader_temp2 = dynamic_cast<TrainedNinja*>(charac);
             team2_trained_ninjas.push_back(leader_temp2);
            leader_temp2->setincluded(true);
        }

        else if (typeid(*charac)==typeid(YoungNinja)){
            //cout << "sssssssss" << endl;
            YoungNinja* leader_temp2 = dynamic_cast<YoungNinja*>(charac);
            team2_young_ninjas.push_back(leader_temp2);
            leader_temp2->setincluded(true);
        }

        else{
        OldNinja* leader_temp2= dynamic_cast<OldNinja*>(charac);
             team2_old_ninjas.push_back(leader_temp2);
                leader_temp2->setincluded(true);
        }

    }



void Team2::print(){
    cout << "Team2 Leader: " << _leader.getName() << endl;
    for (std::vector<Character*>::size_type i = 0; i < team2_cowboy_ninjas.size(); i++)
    {
        team2_cowboy_ninjas[i]->print();
    }   
       for (std::vector<Character*>::size_type i = 0; i < team2_old_ninjas.size(); i++)
    {
        team2_old_ninjas[i]->print();
    }
         for (std::vector<Character*>::size_type i = 0; i < team2_young_ninjas.size(); i++)
    {
        team2_young_ninjas[i]->print();
    }

    for (std::vector<Character*>::size_type i = 0; i <  team2_trained_ninjas.size(); i++)
        {
             team2_trained_ninjas[i]->print();


        }
        
    }

Team2::~Team2(){
    for (std::vector<Character*>::size_type i = 0; i < team2_cowboy_ninjas.size(); i++)
    {
       delete team2_cowboy_ninjas[i];
    }   
       for (std::vector<Character*>::size_type i = 0; i < team2_old_ninjas.size(); i++)
    {
        delete team2_old_ninjas[i];
    }
         for (std::vector<Character*>::size_type i = 0; i < team2_young_ninjas.size(); i++)
    {
        delete team2_young_ninjas[i];
    }

    for (std::vector<Character*>::size_type i = 0; i <  team2_trained_ninjas.size(); i++)
        {
         delete  team2_trained_ninjas[i];


        }
}

    int Team2::stillAlive(){
        int count=0;
          for (std::vector<Character*>::size_type i = 0; i < team2_cowboy_ninjas.size(); i++){
                if(team2_cowboy_ninjas[i]->isAlive()){
                    count++;
                }
          }

        for (std::vector<Character*>::size_type i = 0; i < team2_old_ninjas.size(); i++){
                if(team2_old_ninjas[i]->isAlive()){
                    count++;
                }
          }

        for (std::vector<Character*>::size_type i = 0; i <  team2_trained_ninjas.size(); i++){
                if( team2_trained_ninjas[i]->isAlive()){
                    count++;
                }
          }
         for (std::vector<Character*>::size_type i = 0; i < team2_young_ninjas.size(); i++){
                if(team2_young_ninjas[i]->isAlive()){
                    count++;
                }
          }  


       return count;
    }


    bool Team2::attack(Team2 *other){
        if(other==nullptr){
            throw std::invalid_argument("Team is null");
            }

        if(this->stillAlive()==0 || other->stillAlive()==0){
            return false;
        }


        if(_leader.isAlive()){
            Character * minDistance_character;
            double min=TMP_MAX;
             for (std::vector<Character*>::size_type i = 0; i < other->team2_cowboy_ninjas.size(); i++){
                if(other->team2_cowboy_ninjas[i]->isAlive()){
                   double temp2= _leader.distance(other->team2_cowboy_ninjas[i]);

                    if(temp2<min){
                        min=temp2;
                        minDistance_character=other->team2_cowboy_ninjas[i];
                    }
                }
          }

             for (std::vector<Character*>::size_type i = 0; i < other->team2_old_ninjas.size(); i++){
                if(other->team2_old_ninjas[i]->isAlive()){
                   double temp2= _leader.distance(other->team2_old_ninjas[i]);

                    if(temp2<min){
                        min=temp2;
                        minDistance_character= other->team2_old_ninjas[i];
                    }
                }
          }


              for (std::vector<Character*>::size_type i = 0; i <  other->team2_young_ninjas.size(); i++){
                if( other->team2_young_ninjas[i]->isAlive()){
                    cout << "ss" << endl;
                   double temp2= _leader.distance(other->team2_young_ninjas[i]);

                    if(temp2<min){
                        min=temp2;
                        minDistance_character= other->team2_young_ninjas[i];
                    }
                }
          }



            for (std::vector<Character*>::size_type i = 0; i <  other-> team2_trained_ninjas.size(); i++){
                if( other-> team2_trained_ninjas[i]->isAlive()){
                   double temp2= _leader.distance(other-> team2_trained_ninjas[i]);

                    if(temp2<min){
                        min=temp2;
                        minDistance_character= other-> team2_trained_ninjas[i];
                    }
                }
          }




////////////////////////////////////////////////
             for (std::vector<Character*>::size_type i = 0; i < team2_cowboy_ninjas.size(); i++){
                Cowboy* cowboy_temp2 = dynamic_cast<Cowboy*>(team2_cowboy_ninjas[i]);

                if(cowboy_temp2 ->isAlive() && cowboy_temp2->hasboolets()){
                    cowboy_temp2->shoot(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                if(cowboy_temp2 ->isAlive() && !cowboy_temp2->hasboolets()){
                    cowboy_temp2->reload();
                }
        }

           for (std::vector<Character*>::size_type i = 0; i <  team2_trained_ninjas.size(); i++){
                TrainedNinja* TrainedNinja_temp2 = dynamic_cast<TrainedNinja*>( team2_trained_ninjas[i]);

                if(TrainedNinja_temp2 ->isAlive() && TrainedNinja_temp2->distance(minDistance_character) < 1){
                   TrainedNinja_temp2->slash(minDistance_character);
                       if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                       }
                 
                   
                 }

                else {
                    TrainedNinja_temp2->move(minDistance_character);
                }
            }

             for (std::vector<Character*>::size_type i = 0; i < team2_old_ninjas.size(); i++){
                OldNinja* OldNinja_temp2 = dynamic_cast<OldNinja*>(team2_old_ninjas[i]);

                if(OldNinja_temp2 ->isAlive() && OldNinja_temp2->distance(minDistance_character) < 1){
                   OldNinja_temp2->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    OldNinja_temp2->move(minDistance_character);
                }
            }


             for (std::vector<Character*>::size_type i = 0; i < team2_young_ninjas.size(); i++){
                YoungNinja* YoungNinja_temp2 = dynamic_cast<YoungNinja*>(team2_young_ninjas[i]);
                   
                    cout << YoungNinja_temp2->distance(minDistance_character) << endl;
                if(YoungNinja_temp2 ->isAlive() && YoungNinja_temp2->distance(minDistance_character) < 1){
                   YoungNinja_temp2->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    YoungNinja_temp2->move(minDistance_character);
                }
            }

        return true;
    }

            return false;
   

    }