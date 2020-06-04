//
// Created by shahar on 19/05/2020.
//
#pragma once
#include "Soldier.hpp"
class Sniper:public Soldier{
private:
     //int initial_health_points;
    int damage_per_activity;
public:
    Sniper(){
        this->initial_health_points=100;
        this->damage_per_activity=50;
        this->father=1;
    }
    Sniper(int player_number){
        this->initial_health_points=100;
        this->its_max_health_points=100;
        this->damage_per_activity=50;
        this->player_number=player_number;
        this->father=1;

    }
    void attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source);
    Soldier* copy(int player_number);

};

