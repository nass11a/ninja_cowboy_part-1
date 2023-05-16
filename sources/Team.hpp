#ifndef TEAM_HPP
#define TEAM_HPP
#include "iostream"
#include "string"
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
using namespace std;


const double temp=100000;
class Team{
    std::vector <TrainedNinja * > _team_TrainedNinja;
    std::vector <Cowboy * > _team_Cowboy;
    std::vector <YoungNinja * > _team_YoungNinja;
    std::vector <OldNinja * > _team_OldNinja;
    double min=temp;

    Character _leader;  
    Character *_leader2;

    public:
    
    Team(Character * leader):_leader(*leader),_leader2(nullptr){
        cout<< leader->getName()<<endl;
        cout << _leader.getName()<<endl;
        //if(_leader.getName()==leader->getName()){
          //  std::__throw_runtime_error("Error: Leader already exists in the team");
        //}
        
        if(typeid(*leader)==typeid(Cowboy)){
            Cowboy* leader_temp = dynamic_cast<Cowboy*>(leader);
            _team_Cowboy.push_back(leader_temp);
        }

        else if (typeid(*leader)==typeid(TrainedNinja)){
            TrainedNinja* leader_temp = dynamic_cast<TrainedNinja*>(leader);
            _team_TrainedNinja.push_back(leader_temp);
        }

        else if (typeid(*leader)==typeid(YoungNinja)){
            YoungNinja* leader_temp = dynamic_cast<YoungNinja*>(leader);
            _team_YoungNinja.push_back(leader_temp);
        }

        else{
        OldNinja* leader_temp= dynamic_cast<OldNinja*>(leader);
             _team_OldNinja.push_back(leader_temp);
        }


        }
    

    void add(Character *charac);


    void print();

    ~Team();

    int stillAlive();


    bool attack(Team *other);




};

#endif