//game.hpp

#include <map>
#include <set>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"




    Game::Game()=default;
    Game::~Game()=default;


    Game::Game(Rules rulings,std::set<Change*> change_list, State status){
        rules = rulings;
        changes = change_list;
        state = status;
    }


    Rules Game::getRules(){return rules;}
    std::deque<Change> Game::getChanges(){return changes;}
    State Game::getState(){return state;}

    void Game::setRules(Rules rulings){rules = rulings;}
    void Game::setChanges(std::set<Change> change_list){changes = change_list; }
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




