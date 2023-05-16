#ifndef Team2_HPP
#define Team2_HPP
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


const double temp2=100000;
class Team2{
    std::vector <TrainedNinja * >  team2_trained_ninjas;
    std::vector <Cowboy * > team2_cowboy_ninjas;
    std::vector <YoungNinja * >team2_young_ninjas;
    std::vector <OldNinja * > team2_old_ninjas;
   
    double min=temp2;

    Character _leader;  
    Character *_leader2;

    public:
    Team2(Character * leader):_leader(*leader),_leader2(nullptr){
        //    if(_leader.getName()==leader->getName()){
          //  std::__throw_runtime_error("Error: Leader already exists in the team");
       // }
        
         
        if(typeid(*leader)==typeid(Cowboy)){
            Cowboy* leader_temp2 = dynamic_cast<Cowboy*>(leader);
            team2_cowboy_ninjas.push_back(leader_temp2);
        }

        else if (typeid(*leader)==typeid(TrainedNinja)){
            TrainedNinja* leader_temp2 = dynamic_cast<TrainedNinja*>(leader);
             team2_trained_ninjas.push_back(leader_temp2);
        }

        else if (typeid(*leader)==typeid(YoungNinja)){
            YoungNinja* leader_temp2 = dynamic_cast<YoungNinja*>(leader);
           team2_young_ninjas.push_back(leader_temp2);
        }

        else{
        OldNinja* leader_temp2= dynamic_cast<OldNinja*>(leader);
             team2_old_ninjas.push_back(leader_temp2);
        }


        }
    

    void add(Character *charac);
    

    void print();

    ~Team2();

    int stillAlive();


    bool attack(Team2 *other);




};

#endif