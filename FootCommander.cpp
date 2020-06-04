//
// Created by shahar on 19/05/2020.
//
#include <cmath>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"


Soldier* FootCommander::copy(int player_number){
    Soldier *temp=new FootCommander(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
void  FootCommander::attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source) {
//    Soldier *s; // saves the closest soldier
//    int min_distance=1000;
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; j < board[i].size(); j++) {
//            int distance= sqrt(pow(source.first-i, 2)+ pow(source.second-j, 2));
//            if( distance<min_distance){
//                min_distance= distance;
//                s=board[i][j];
//            }
//        }
//    }
//    s->initial_health_points=s->initial_health_points-this->damage_per_activity;
    FootSoldier::attack_or_cure(board,source);
    //closest to this FootCommander
    Soldier *s;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            s=board[i][j];

            bool b = (dynamic_cast<FootSoldier*>(s) != nullptr);
            if(b && s->father==1){   //Checks if each soldier is a paramedic
                std::pair<int,int> source_of_a_Foot=std::pair<int,int>(i,j);
                s-> attack_or_cure( board,source_of_a_Foot);
            }
        }

    }





}