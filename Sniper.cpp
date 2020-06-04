//
// Created by shahar on 19/05/2020.
//
#include <iostream> // 25/5
using namespace std;
#include "Sniper.hpp"

Soldier* Sniper::copy(int player_number){
    Soldier *temp=new Sniper(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
 void Sniper::attack_or_cure(std::vector<std::vector<Soldier*>> board,std::pair<int,int> source){  //on the strongest one
     int max=0;
     Soldier *s;
     for (int i = 0; i < board.size(); i++) {
         for (int j = 0; j < board[0].size(); j++) {
             if (board[i][j]) {
                 int b=board[i][j]->initial_health_points;
                // cout<<"b="<<b<<endl;
                 if (b > max && board[i][j]->player_number != this->player_number) {
                     max = b;
                     s = board[i][j];

                 }
             }
         }
     }

     s->initial_health_points=s->initial_health_points-this->damage_per_activity;
    // cout<<"points now="<<s->initial_health_points<<endl;
     if(s->initial_health_points<=0){   //25/5
         s=0;
     }
}