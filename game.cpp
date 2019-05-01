//game.hpp

#ifndef GAME_HPP

#include <map>
#include <unordered_set>
#include "cell.hpp"



class Game{

    std::map<int,int> rules;
    std::unordered_set<Change> changes;
    State state;

public:
    const int GAME_LENGTH;
    const int BOARD_SIZE;

    Game(int length,int size,std::map<int,int> rulings,std::unordered_set<Change> changes, State state);


    std::map<int,int> getRules(){}
    std::unordered_set<Change> getChanges(){}
    State getState(){}
    int getGameLength(){}
    int getBoardSize(){}

    void setRules(std::map<int,int> rules){}
    void setChanges(std::unordered_set<Change> changes){}
    void setState(State state){}

    void updateState(Change change,int direction){}
    void generateChanges(){}

    int sendChanges(Change change,int it){}

    void receiveRules(){}
    void receiveStartingPosition(){}
    void receiveTask(){}


}

