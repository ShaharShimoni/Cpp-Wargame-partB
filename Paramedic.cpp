//
// Created by shahar on 19/05/2020.
//

#include "Paramedic.hpp"
#include <iostream>
Soldier* Paramedic::copy(int player_number){
    Soldier *temp=new Paramedic(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
void Paramedic::attack_or_cure (std::vector<std::vector<Soldier*>> board,std::pair<int,int> source) { //next to him
    //std::cout<<"in attack"<<std::endl;

    std::pair<int, int> placeParamedic = source;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++){
            Soldier *s=board[i][j];

            if((source.first==i && (source.second==j+1||source.second==j-1))||(source.first==j && (source.second==i+1||source.second==i-1))){
                if(s)
                if(s->player_number==this->player_number) {
                    //this soldier is next to the Paramedic
                    std::cout << "in attack" << std::endl;
                    s->initial_health_points = s->its_max_health_points;
                    std::cout << "in2 attack" << std::endl;
                }

            }
        }

    }
    std::cout << "ecd of" << std::endl;



}