//game.hpp

#include <set>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>  // min,max (da sie bez tego ale jest czytelniej niz konstrukcja a ? b : c ; zgaduje za duzo pythona)
#include <cmath>     //sqrt, floor, ceil, pow

typedef std::map<std::pair<int,int>, int>::iterator findertype;

Game::Game()=default;
Game::~Game()=default;


Game::Game(Rules rulings, std::deque<Change*> change_list, State* status){
    rules = rulings;
    changes = change_list;
    state = status;
}

void Game::updateRecord(std::map<std::pair<int, int>, int>* influence_map, int x_index, int y_index){
    std::pair<int, int> to_find = std::make_pair(x_index, y_index);
    findertype finder = influence_map->find(to_find);
        
    if (finder == influence_map->end()){           // nie ma takiego klucza https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
        influence_map->insert(std::pair<std::pair<int,int>, int>(to_find, 1));
    }
    else{                                       // jest taki klucz
        (*influence_map)[to_find] += 1;
    }    
}

void Game::includeCellInfluence(std::map<std::pair<int, int>, int>* influence_map, Cell* current_cell){

    // Niby zrobione, ale nie wiem czy jest cos zle ze wskaznikami do influence_map
    // Generalnie kwestia jest taka, ze chcemy miec kazda funkcje do jednej rzeczy
    // Stad wlasnie ta pokraczna funkcja ktora dostaje wskaznik na mape
    // Wskaznik, bo nie chcemy zeby kompilator nam robil jej kopie
    // Mandatory disclaimer: sprawdzic czy nie jestem noga ze wskaznikow
    // No i poniewaz funkcja ta pobiera wskaznik na rzeczywisty obiekt i go edytuje to nie musi nic zwracac
    // I czy poprawnie sa zapisane warunki dla enumow
    
    
    int current_x = current_cell->getXcoord();
    int current_y = current_cell->getYcoord();
    int min_x = std::min(0, current_x);
    int max_x = std::max(BOARD_SIZE-1, current_x);        
    int min_y = std::min(0, current_y);
    int max_y = std::max(BOARD_SIZE-1, current_y);   
            
    if (rules.neighbourhood == NeighbourhoodType::MOORE){
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset){
             for (auto y_offset = std::max(-rules.range, -current_y) ; y_offset <= std::min(rules.range, BOARD_SIZE-1-current_y); ++y_offset) 
                updateRecord(influence_map, current_x + x_offset, current_y + y_offset);
    	}
    }
    
    else if (rules.neighbourhood == NeighbourhoodType::NEUM){
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset){
             for (auto y_offset = -abs(rules.range - abs(x_offset)); y_offset <= abs(rules.range - abs(x_offset)); ++y_offset) 
                 updateRecord(influence_map, current_x + x_offset, current_y + y_offset);     
        }
    }
        
    else if (rules.neighbourhood == NeighbourhoodType::CIRC){
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset){
             for (auto y_offset = -floor(sqrt(pow(rules.range + 0.5, 2) - pow(x_offset, 2))); y_offset <= floor(sqrt(pow(rules.range + 0.5, 2) - pow(x_offset, 2))); ++y_offset)
                 updateRecord(influence_map, current_x + x_offset, current_y + y_offset);            
        }
    }             
}
    
std::map<std::pair<int, int>, int> Game::generateInfluenceMap(){
        
    State* current_state = state; //niepotrzebne, ale na razie dla czytelnosci kodu sobie siedzi
    std::map<std::pair<int, int>, int> influence_map;
        
    for(auto std::set<Cell*>::iterator it = state->getActiveCells().begin(); it != state->getActiveCells().end(); ++it){
        includeCellInfluence(influence_map, *it);                
    }
    return influence_map;
}

    
void Game::generateChange(std::map<std::pair<int, int>, int> influence_map){
    Change change_i = new Change();
    for(auto std::map<std::pair<int, int>, int>::iterator it = influence_map.begin(); it != influence_map.end(); ++it){
        for (auto std::set<Cell*>::iterator it2 = state.active_cells; it2 != state.active_cells.end(); ++it2){
            if ((*it2)->std::pair<it->first, it->second>){                                  //jesli cell o takich wspolrzednych jest w active cellsach
                if ((it->second < rules.smin + 1 - rules.m) || (it->second  > rules.smax + 1 - rules.m)){                 //jesli nei jest spelniony warunek przezywalnosci
                    change_i.addToShift((*it2));
                    break;
                }                                                                           //jesli jest to nic nie robimy                
            }           
        }                                                                                
        if  ((it->second >= rules.bmin + 1 - rules.m) && (it->second  <= rules.bmax + 1 - rules.m))       //jseli jestesmy w tym miejscu to oznacza ze takiego cella nie ma
            change_i.addToBirth((*it2));                                      // i jesli chcemy go stworzyc to go tworzymy

    }
    changes.push_back(&change_i);
}

void Game::implementChange (Change* change){
    for (auto std::set<Cell*>::iterator it = change->to_birth.begin(); it != change->to_birth.end(); ++it){
        std::pair to_find = std::make_pair(x_index, y_index);
        std::pair<int, int>, int>* finder = (*influence_map).find(to_find);
        
    }
}
    

    Rules Game::getRules(){return rules;}
    std::deque<Change*> Game::getChanges(){return changes;}
    State Game::getState(){return state;}

    void Game::setRules(Rules rulings){rules = rulings;}
    void Game::setChanges(std::deque<Change*> change_list){changes = change_list;}
    void Game::setState(State status){state = status;}

    void Game::updateState(Change change,int direction){}

    void Game::generateAllChanges(){
        State current_position = state;
        
        for (int i = 0; i < GAME_LENGTH; ++i){
            std::map<std::pair<int, int>, int>* influence_map = generateInfluenceMap();
            generateChange(influence_map);
            implementChange(changes[i]);
        }
        
    }

    int Game::sendChanges(Change change,int it){return 1;}

    void Game::receiveRules(){}
    void Game::receiveStartingPosition(){} //changes[0] = starting_pos
    void Game::receiveTask(){}




