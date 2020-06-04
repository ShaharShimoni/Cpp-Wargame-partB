//
// Created by shahar on 19/05/2020.
//
#include <iostream> // 25/5
using namespace std;
#include "SniperCommander.hpp"
//#include "Sniper.hpp"


Soldier* SniperCommander::copy(int player_number){
    Soldier *temp=new SniperCommander(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
    void  SniperCommander::attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source) {

    cout<<"in sniper commander"<<endl;
      //  std::pair<int, int> placeSniper = source;
//        int max=0;
//        Soldier *s;  //save the max one
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++)
//                if(board[i][i]->initial_health_points>max){
//                    max=board[i][i]->initial_health_points;
//                    s=board[i][i];
//
//                }
//        }
//        s->initial_health_points=s->initial_health_points-this->damage_per_activity;

         Sniper::attack_or_cure(board,source); //doing the father function
        //father function
        Soldier *s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++){
                s=board[i][j];

                bool b = (dynamic_cast<Sniper*>(s) != nullptr);
                if(b && s->father==1){   //Checks if each soldier is a paramedic
                    std::pair<int,int> source_of_a_Sniper=std::pair<int,int>(i,j);
                    s->attack_or_cure( board,source_of_a_Sniper);
                }
            }

        }



    }