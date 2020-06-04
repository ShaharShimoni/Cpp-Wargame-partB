//
// Created by shahar on 19/05/2020.
//


//#include "Soldier.hpp"
#pragma once
#include "Sniper.hpp"

class SniperCommander:public Sniper{
private:
    // int initial_health_points;
    int damage_per_activity;

public:
    SniperCommander(){
        this->initial_health_points=120;
        this->damage_per_activity=100;
        this->father=0;
    }
    SniperCommander(int player_number){
        this->initial_health_points=120;
        this->its_max_health_points=120;
        this->damage_per_activity=100;
        this->player_number=player_number;
        this->father=0;

    }
    void attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source) ;
    Soldier* copy(int player_number);

//    void attack_or_cure () override{
//
//    }
};
