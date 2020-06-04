//
// Created by shahar on 19/05/2020.
//
#include "Paramedic.hpp"   //24/5
#include "ParamedicCommander.hpp"

Soldier* ParamedicCommander::copy(int player_number){
    Soldier *temp=new ParamedicCommander(player_number);
    temp->initial_health_points=this->initial_health_points;
    temp->father=this->father;
    temp->its_max_health_points=this->its_max_health_points;
    return temp;
}
void ParamedicCommander::attack_or_cure(std::vector<std::vector<Soldier*>> board,std::pair<int,int> source){
    std::pair<int, int> placeParamedic = source;
    Paramedic::attack_or_cure(board,source);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++){
            Soldier *s=board[i][j];
//            if((source.first==i && (source.second=j+1||source.second==j-1))||(source.first==j && (source.second==i+1||source.second==i-1))){
//                //this soldier is next to the Paramedic
//                s->initial_health_points=s->its_max_health_points;
//
//            }
            bool b = (dynamic_cast<Paramedic*>(s) != nullptr);
            if(b && s->father==1){   //Checks if each soldier is a paramedic
                std::pair<int,int> source_of_a_paramedic=std::pair<int,int>(i,j);
                s->attack_or_cure( board,source_of_a_paramedic);
            }
        }

    }


}