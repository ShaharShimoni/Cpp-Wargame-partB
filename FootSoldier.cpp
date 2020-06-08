//
// Created by shahar on 19/05/2020.
//

#include "FootSoldier.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"

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
// std::cout<<"in attack"<<std::endl;

    int number_player=this->player_number;
    double min_distance=1000;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          //  std::cout<<"in attack"<<std::endl;

            //Soldier *temp=board[i][j];

              if(board[i][j] ) {
                //  if(typeid(*board[i][j])== typeid(Sniper) ||typeid(*board[i][j])!= typeid(Paramedic)||typeid(*board[i][j])!= typeid(FootSoldier)) {
                      double distance = sqrt(
                              (source.first - i) * (source.first - i) + (source.second - j) * (source.second - j));
//                     std::cout << "distance=" << distance << " " << "between" << number_player << "-"
//                            << board[i][j]->initial_health_points << std::endl;
                      if (distance < min_distance && board[i][j]->player_number != number_player && board[i][j]->initial_health_points>0) {

                          min_distance = distance;
                          s = board[i][j];
                      }
                      else
                      if(distance == min_distance && board[i][j]->player_number != number_player ){
                          if(source.first==i || source.second==j) {
                             // std::cout << "yes=" << std::endl;
                              min_distance = distance;
                              s = board[i][j];
                          }
                      }
                  }
             // }
        }
    }
    if(this->father==0){
        this->damage_per_activity=20;
    }
    // std::cout<<"damage"<<this->damage_per_activity<<std::endl;
    if(min_distance!=1000)
    s->initial_health_points=s->initial_health_points-this->damage_per_activity;
   // std::cout<<"points now="<<s->initial_health_points<<std::endl;
   if(min_distance!=1000)
    if(s->initial_health_points<=0){   //25/5
        s=0;
    }

}