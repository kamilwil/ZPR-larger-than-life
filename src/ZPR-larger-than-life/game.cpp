//game.hpp

#include <map>
#include <set>
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"




    Game::Game()=default;
    Game::~Game()=default;

    Game::Game(std::map<int,int> rulings,std::set<Change*> change_list, State status){
        rules = rulings;
        changes = change_list;
        state = status;
    }


    std::map<int,int> Game::getRules(){return rules;}
    std::set<Change> Game::getChanges(){return changes;}
    State Game::getState(){return state;}

    void Game::setRules(std::map<int,int> rulings){rules = rulings;}
    void Game::setChanges(std::set<Change> change_list){changes = change_list; }
    void Game::setState(State status){state = status;}

    void Game::updateState(Change change,int direction){}
    void Game::generateChanges(){}

    int Game::sendChanges(Change change,int it){return 1;}

    void Game::receiveRules(){}
    void Game::receiveStartingPosition(){}
    void Game::receiveTask(){}




