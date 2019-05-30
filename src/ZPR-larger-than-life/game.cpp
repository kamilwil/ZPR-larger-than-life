//game.hpp

#include <set>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"
#include <map>
#include <pair>
#include <iterator>
#include <algorithm>  // min,max (da sie bez tego ale jest czytelniej niz konstrukcja a ? b : c )
#include <cmath>     //sqrt, floor, ceil



Game::Game()=default;
Game::~Game()=default;


Game::Game(Rules rulings,std::set<Change*> change_list, State status){
    rules = rulings;
    changes = change_list;
    state = status;
}

void Game::includeCellInfluence(std::map<std::pair<int, int>, int>* influence_map, Cell* current_cell){

    // Niby zrobione, ale nie wiem czy jest cos zle ze wskaznikami do influence_map
    // Generalnie kwestia jest taka, ze chcemy miec kazda funkcje do jednej rzeczy
    // Stad wlasnie ta pokraczna funkcja ktora dostaje wskaznik na mape
    // Wskaznik, bo nie chcemy zeby kompilator nam robil jej kopie
    // Mandatory disclaimer: sprawdzic czy nie jestem noga ze wskaznikow
    // No i poniewaz funkcja ta pobiera wskaznik na rzeczywisty obiekt i go edytuje to nie musi nic zwracac
    // I czy poprawnie sa zapisane warunki dla enumow
    
    
    current_x = current_cell->coords.first;
    current_y = current_cell->coords.second;
    min_x = min(0, current_x);
    max_x = max(BOARD_SIZE-1, current_x);        
    min_y = min(0, current_y);
    max_y = max(BOARD_SIZE-1, current_y);   
    
    
        
    if (rules.neighboorhood == NeighbourhoodType::MOORE){
        for (auto x_offset = max(-rules.range, -current_x) ; x_offset <= min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = max(-rules.range, -current_y) ; y_offset <= min(rules.range, BOARD_SIZE-1-current_y); ++y_offset) {
                 to_find = std::make_pair(current_x + x_offset , current_y + y_offset);
                 finder = (*influence_map).find(to_find)
                 if finder == (*influence_map).end(){           // nie ma takiego klucza https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
                     (*influence_map).insert(std::pair<to_find, 1);
                 }
                 else{                                       // jest taki klucz
                     (*influence_map)[to_find] += 1;
                 }
             }
    }
    else if (rules.neighboorhood == NeighbourhoodType::NEUM){
        for (auto x_offset = max(-rules.range, -current_x) ; x_offset <= min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -abs(rules.range - abs(x_offset)); y_offset <= abs(rules.range - abs(x_offset)); ++y_offset) {
                 to_find = std::make_pair(i,j);
                 finder = (*influence_map).find(to_find)
                 if finder == (*influence_map).end(){           // nie ma takiego klucza https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
                     (*influence_map).insert(std::pair<to_find, 1);
                 }
                 else{                                       // jest taki klucz
                     (*influence_map)[to_find] += 1;
                 }
             }        
        
    }
    else if (rules.neighboorhood == NeighbourhoodType::CIRC){
        for (auto x_offset = max(-rules.range, -current_x) ; x_offset <= min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -floor(sqrt((rules.range + 0.5)^2 - x_offset^2)); y_offset <= floor(sqrt((rules.range + 0.5)^2 - x_offset^2)); ++y_offset) {  
                 to_find = std::make_pair(i,j);
                 finder = (*influence_map).find(to_find)
                 if finder == (*influence_map).end(){           // nie ma takiego klucza https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
                     (*influence_map).insert(std::pair<to_find, 1);
                 }
                 else{                                       // jest taki klucz
                     (*influence_map)[to_find] += 1;
                 }
             }        
        
    }                 
}
    

std::map<std::pair<int, int>, int>* Game::generateInfluenceMap(){
        
    current_state = state; //niepotrzebne, ale na razie dla czytelnosci kodu sobie siedzi
    std::map<std::pair<int, int>, int> influenceMap;
        
    for(auto std::iterator<Cell*> it = state.active_cells.begin(); it != state.active_cells.end();){
        Game::includeCellInfluence(influenceMap, it);            
            
    }
               
}

    

    Rules Game::getRules(){return rules;}
    std::deque<Change*> Game::getChanges(){return changes;}
    State Game::getState(){return state;}

    void Game::setRules(Rules rulings){rules = rulings;}
    void Game::setChanges(std::deque<Change*> change_list){changes = change_list;}
    void Game::setState(State status){state = status;}

    void Game::updateState(Change change,int direction){}
    void Game::generateChanges(){
        State current_position = state;
        
        for (int i = 0; i < GAME_LENGTH; ++i){
            
        }
        
    }

    int Game::sendChanges(Change change,int it){return 1;}

    void Game::receiveRules(){}
    void Game::receiveStartingPosition(){} //changes[0] = starting_pos
    void Game::receiveTask(){}




