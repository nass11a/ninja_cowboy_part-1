 #include "Team.hpp"

 void Team::add(Character *charac){
     if (_team_OldNinja.size() + _team_Cowboy.size() + _team_TrainedNinja.size() + _team_YoungNinja.size() == 10) {
        throw std::runtime_error("Team is already full");
    }
    if(charac->getincluded() == true){
        throw std::runtime_error("Character is already in a team");
    }
        if(charac->distance(&_leader)<min){
            min=charac->distance(&_leader);
            _leader2=charac;
        }
        if(typeid(*charac)==typeid(Cowboy)){
            Cowboy* leader_temp = dynamic_cast<Cowboy*>(charac);
            _team_Cowboy.push_back(leader_temp);
            leader_temp->setincluded(true);
        }

        else if (typeid(*charac)==typeid(TrainedNinja)){
            TrainedNinja* leader_temp = dynamic_cast<TrainedNinja*>(charac);
            _team_TrainedNinja.push_back(leader_temp);
            leader_temp->setincluded(true);
        }

        else if (typeid(*charac)==typeid(YoungNinja)){
            //cout << "sssssssss" << endl;
            YoungNinja* leader_temp = dynamic_cast<YoungNinja*>(charac);
            _team_YoungNinja.push_back(leader_temp);
            leader_temp->setincluded(true);
        }

        else{
        OldNinja* leader_temp= dynamic_cast<OldNinja*>(charac);
             _team_OldNinja.push_back(leader_temp);
                leader_temp->setincluded(true);
        }

    }



void Team::print(){
    cout << "Team Leader: " << _leader.getName() << endl;
    for (std::vector<Character*>::size_type i = 0; i < _team_Cowboy.size(); i++)
    {
        _team_Cowboy[i]->print();
    }   
       for (std::vector<Character*>::size_type i = 0; i < _team_OldNinja.size(); i++)
    {
        _team_OldNinja[i]->print();
    }
         for (std::vector<Character*>::size_type i = 0; i < _team_YoungNinja.size(); i++)
    {
        _team_YoungNinja[i]->print();
    }

    for (std::vector<Character*>::size_type i = 0; i < _team_TrainedNinja.size(); i++)
        {
            _team_TrainedNinja[i]->print();


        }
        
    }

Team::~Team(){
    for (std::vector<Character*>::size_type i = 0; i < _team_Cowboy.size(); i++)
    {
       delete _team_Cowboy[i];
    }   
       for (std::vector<Character*>::size_type i = 0; i < _team_OldNinja.size(); i++)
    {
        delete _team_OldNinja[i];
    }
         for (std::vector<Character*>::size_type i = 0; i < _team_YoungNinja.size(); i++)
    {
        delete _team_YoungNinja[i];
    }

    for (std::vector<Character*>::size_type i = 0; i < _team_TrainedNinja.size(); i++)
        {
         delete _team_TrainedNinja[i];


        }
}

    int Team::stillAlive(){
        int count=0;
          for (std::vector<Character*>::size_type i = 0; i < _team_Cowboy.size(); i++){
                if(_team_Cowboy[i]->isAlive()){
                    count++;
                }
          }

        for (std::vector<Character*>::size_type i = 0; i < _team_OldNinja.size(); i++){
                if(_team_OldNinja[i]->isAlive()){
                    count++;
                }
          }

        for (std::vector<Character*>::size_type i = 0; i < _team_TrainedNinja.size(); i++){
                if(_team_TrainedNinja[i]->isAlive()){
                    count++;
                }
          }
         for (std::vector<Character*>::size_type i = 0; i < _team_YoungNinja.size(); i++){
                if(_team_YoungNinja[i]->isAlive()){
                    count++;
                }
          }  


       return count;
    }


    bool Team::attack(Team *other){
      if(other==nullptr){
            throw  std::invalid_argument("Team is null");
            }

        if(this->stillAlive()==0 || other->stillAlive()==0){
            return false;
        }
        


        if(_leader.isAlive()){
            Character * minDistance_character;
            double min=TMP_MAX;
             for (std::vector<Character*>::size_type i = 0; i < other->_team_Cowboy.size(); i++){
                if(other->_team_Cowboy[i]->isAlive()){
                   double temp= _leader.distance(other->_team_Cowboy[i]);

                    if(temp<min){
                        min=temp;
                        minDistance_character=other->_team_Cowboy[i];
                    }
                }
          }

             for (std::vector<Character*>::size_type i = 0; i < other->_team_OldNinja.size(); i++){
                if(other->_team_OldNinja[i]->isAlive()){
                   double temp= _leader.distance(other->_team_OldNinja[i]);

                    if(temp<min){
                        min=temp;
                        minDistance_character= other->_team_OldNinja[i];
                    }
                }
          }


              for (std::vector<Character*>::size_type i = 0; i <  other->_team_YoungNinja.size(); i++){
                if( other->_team_YoungNinja[i]->isAlive()){
                    cout << "ss" << endl;
                   double temp= _leader.distance( other->_team_YoungNinja[i]);

                    if(temp<min){
                        min=temp;
                        minDistance_character= other->_team_YoungNinja[i];
                    }
                }
          }



            for (std::vector<Character*>::size_type i = 0; i <  other->_team_TrainedNinja.size(); i++){
                if( other->_team_TrainedNinja[i]->isAlive()){
                   double temp= _leader.distance( other->_team_TrainedNinja[i]);

                    if(temp<min){
                        min=temp;
                        minDistance_character= other->_team_TrainedNinja[i];
                    }
                }
          }




////////////////////////////////////////////////
             for (std::vector<Character*>::size_type i = 0; i < _team_Cowboy.size(); i++){
                Cowboy* cowboy_temp = dynamic_cast<Cowboy*>(_team_Cowboy[i]);

                if(cowboy_temp ->isAlive() && cowboy_temp->hasboolets()){
                    cowboy_temp->shoot(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                if(cowboy_temp ->isAlive() && !cowboy_temp->hasboolets()){
                    cowboy_temp->reload();
                }
        }

           for (std::vector<Character*>::size_type i = 0; i < _team_TrainedNinja.size(); i++){
                TrainedNinja* TrainedNinja_temp = dynamic_cast<TrainedNinja*>(_team_TrainedNinja[i]);

                if(TrainedNinja_temp ->isAlive() && TrainedNinja_temp->distance(minDistance_character) < 1){
                   TrainedNinja_temp->slash(minDistance_character);
                       if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                       }
                 
                   
                 }

                else {
                    TrainedNinja_temp->move(minDistance_character);
                }
            }

             for (std::vector<Character*>::size_type i = 0; i < _team_OldNinja.size(); i++){
                OldNinja* OldNinja_temp = dynamic_cast<OldNinja*>(_team_OldNinja[i]);

                if(OldNinja_temp ->isAlive() && OldNinja_temp->distance(minDistance_character) < 1){
                   OldNinja_temp->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    OldNinja_temp->move(minDistance_character);
                }
            }


             for (std::vector<Character*>::size_type i = 0; i < _team_YoungNinja.size(); i++){
                YoungNinja* YoungNinja_temp = dynamic_cast<YoungNinja*>(_team_YoungNinja[i]);
                    cout << "saaaaaaaaaaaaaaaaaas" << endl;
                    cout << YoungNinja_temp->distance(minDistance_character) << endl;
                if(YoungNinja_temp ->isAlive() && YoungNinja_temp->distance(minDistance_character) < 1){
                   YoungNinja_temp->slash(minDistance_character);
                    if(minDistance_character->gethitpoints() <= 0){
                           minDistance_character->alive=false;
                    }
                 }

                else {
                    YoungNinja_temp->move(minDistance_character);
                }
            }

        return true;
    }

            return false;
   

    }