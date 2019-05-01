//game.hpp

#include <map>
#include <set>
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"




    Game::Game()=default;
    Game::~Game()=default;

    Game::Game(int length,int size,std::map<int,int> rulings,std::set<Change> changes, State state){}


    std::map<int,int> Game::getRules(){return rules;}
    std::set<Change> Game::getChanges(){return changes;}
    State Game::getState(){return state;}
    int Game::getGameLength(){return 1;}
    int Game::getBoardSize(){return 1;}

    void Game::setRules(std::map<int,int> rules){}
    void Game::setChanges(std::set<Change> changes){}
    void Game::setState(State state){}

    void Game::updateState(Change change,int direction){}
    void Game::generateChanges(){}

    int Game::sendChanges(Change change,int it){return 1;}

    void Game::receiveRules(){}
    void Game::receiveStartingPosition(){}
    void Game::receiveTask(){}




