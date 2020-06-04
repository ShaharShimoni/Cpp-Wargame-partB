//
// Created by shahar on 19/05/2020.
//

#include "FootSoldier.hpp"
#include <cmath>
#include <iostream>

Soldier* FootSoldier::copy(int player_number){
    Soldier *temp=new FootSoldier(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
void  FootSoldier::attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source) {  //The closest
    Soldier *s; // saves the closest soldier


    int number_player=this->player_number;
    int min_distance=1000;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout<<"in attack"<<std::endl;

            //Soldier *temp=board[i][j];
              int distance= sqrt(pow(source.first-i, 2)+ pow(source.second-j, 2));
              if(board[i][j])
              if( distance<min_distance && board[i][j]->player_number!=number_player){
                  min_distance= distance;
                  s=board[i][j];
              }
        }
    }
    s->initial_health_points=s->initial_health_points-this->damage_per_activity;
    std::cout<<"points now="<<s->initial_health_points<<std::endl;
    if(s->initial_health_points<=0){   //25/5
        s=0;
    }

}