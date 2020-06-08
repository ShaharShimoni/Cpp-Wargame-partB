//
// Created by shahar on 19/05/2020.
//

#include "Board.hpp"
using namespace WarGame;
using namespace std;
#include <iostream>
#include "Sniper.hpp"   //4/6
#include "FootSoldier.hpp"

#include "Paramedic.hpp"



Soldier*& Board::operator[](std::pair<int,int> location){
    Soldier *&s=this->board[location.first][location.second];
    return s;
}

Soldier* Board::operator[](std::pair<int,int> location) const{
         Soldier* s=this->board[location.first][location.second];
         return s;
}

std::pair<int,int> Board::actual_move(uint player_number, std::pair<int,int> source, MoveDIR direction){

    std::pair<int,int> new_source;
    new_source.first=source.first;
    new_source.second=source.second;
    switch(direction) {
        case Up :
            new_source.first=source.first+1;
            break;
        case Down :
            new_source.first=source.first-1;
            break;
        case Left :
            new_source.second=source.second-1;
            break;
        case Right :
            new_source.second=source.second+1;
            break;
    }


    return new_source;

}

void Board::printboard() {
    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board[i].size(); j++) {
            if (this->board[i][j])  //!=NULL

                cout <<"   "<<this->board[i][j]->player_number <<" "<< this->board[i][j]->initial_health_points<<"  " ;
            else
                cout << "  ------  " ;

        }
        cout<<"     "<<endl;

    }
    cout<<"   "<<endl;
    cout<<"   "<<endl;

    cout<<"   "<<endl;
    cout<<"   "<<endl;

}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){//our actual move //finifsh it !
   // cout<<"source "<<source.first <<source.second<<endl;
    if(source.first>=board.size()|| source.second>=board[0].size()){
        throw exception();
    }

    // cout<<"in move"<<endl;
    Soldier* s=this->board[source.first][source.second];    //The soldier we need to move
 //   cout<<"before    "<<s<<endl;

    if(s== NULL ){     //There is no soldier in this place
        throw exception();
    }
//    if(typeid(*s)!= typeid(Sniper) &&
//       typeid(*s)!= typeid(Paramedic)&&
//       typeid(*s)!= typeid(FootSoldier)){     //There is no soldier in this place
//        throw exception();
//    }
    if(s->player_number!=player_number){    //The soldier doesnt belong to the player

        throw exception();
    }
   // cout<<"source.size= "<<board.size() << source.first<<endl;
  //  cout<<"board.size= "<<board[0].size() << source.second<<endl;


   // cout<<"before actual "<<source.first <<source.second<<endl;

    std::pair<int,int> new_source=actual_move(player_number,  source, direction);
    //cout<<"after actual new source "<<new_source.first <<new_source.second<<endl;
    if(new_source.first>=this->board.size() || new_source.second>=board[0].size()){
        throw exception();
    }
    if(this->board[new_source.first][new_source.second]){  //another soldier is in this place
        throw exception();
    }
    ////// move to new_source and then -delete from old source (add a copy for each soldier)

    Soldier *t=this->board[source.first][source.second]->copy(player_number);  //deep copy
    this->board[source.first][source.second]=0;  //no more at this point
    this->board[new_source.first][new_source.second]=t;
    //cout<<"before attack "<< typeid(*t).name()<<endl;

    t->attack_or_cure(this->board,new_source);  //22/5
   // cout<<"after attack "<<endl;



}
bool Board::has_soldiers(uint player_number) const{   //pass on all soldiers to see if they are of player_numer ?

    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board[i].size(); j++) {

            if (this->board[i][j]) { //!=NULL
               // cout << "not null" << endl;
                if (this->board[i][j]->player_number == player_number && this->board[i][j]->initial_health_points > 0) {
                    //  cout << "soldier in has soldierr player==" << player_number << " "
                    //   << this->board[i][j]->initial_health_points << endl;
                    return true;
                }
            }
        }
    }

    return false;
}