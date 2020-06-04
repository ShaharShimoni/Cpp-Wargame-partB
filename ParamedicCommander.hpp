//
// Created by shahar on 19/05/2020.
//
#include "Soldier.hpp"
#include "Paramedic.hpp"

class ParamedicCommander:public Paramedic{
private:
    // int initial_health_points;
    int health_per_activity;
public:
    ParamedicCommander(){
        this->initial_health_points=200;
        this->health_per_activity=100;
        this->father=0;
    }
    ParamedicCommander(int player_number){
        this->initial_health_points=200;
        this->its_max_health_points=200;
        this->health_per_activity=100;
        this->player_number=player_number;
        this->father=0;

    }
    void attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source);
    Soldier* copy(int player_number);
};