//
// Created by shahar on 19/05/2020.


#include "FootSoldier.hpp"
#pragma once
#include "Soldier.hpp"
class FootCommander:public FootSoldier{
private:
     //int initial_health_points;
     int damage_per_activity;
public:
    FootCommander(){
         this->initial_health_points=150;
         this->damage_per_activity=20;
         this->father=0;
     }
    FootCommander(int player_number){
        this->initial_health_points=150;
        this->its_max_health_points=150;
        this->damage_per_activity=20;
        this->player_number=player_number;
        this->father=0;
    }
    void attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source);
     Soldier* copy(int player_number);
};