//
// Created by shahar on 19/05/2020.
//
#pragma once
#include "Soldier.hpp"
class Paramedic:public Soldier{
private:
    int health_per_activity;
public:
    Paramedic(){
        this->initial_health_points=100;
        this->health_per_activity=50;
        this->father=1;
    }
    Paramedic(int player_number){
        this->initial_health_points=100;
        this->its_max_health_points=100;
        this->health_per_activity=50;
        this->player_number=player_number;
        this->father=1;
    }
    void attack_or_cure(std::vector<std::vector<Soldier*>> board,std::pair<int,int> source);
    Soldier* copy(int player_number);
};
