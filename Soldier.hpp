//
// Created by shahar on 19/05/2020.
//
#include <vector>

#pragma once
class Soldier{
public:
     int father;
     int initial_health_points;
     int its_max_health_points;
     int player_number;
     virtual void attack_or_cure(std::vector<std::vector<Soldier*>> board,std::pair<int,int> source){}  //22/5
     virtual Soldier* copy(int player_number){};   //27/5


};