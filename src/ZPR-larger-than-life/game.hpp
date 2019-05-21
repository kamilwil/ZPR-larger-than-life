//game.hpp

#ifndef GAME_HPP
#define GAME_HPP

#include <map>
#include <set>
#include "change.hpp"
#include "state.hpp"


class Game{

    std::map<int,int> rules;
    std::set<Change*> changes;
    State* state;

public:
    Game();
    ~Game();
    const static int GAME_LENGTH=100;
    const static int BOARD_SIZE=100;

    Game(std::map<int,int>,std::set<Change*>,State);

    std::map<int,int> getRules();
    std::set<Change*> getChanges();
    State getState();
    
    void setRules(std::map<int,int>);
    void setChanges(std::set<Change*>);
    void setState(State*);

    void updateState(Change*,int);
    void generateChanges();

    int sendChanges(Change*,int);

    void receiveRules();
    void receiveStartingPosition();
    void receiveTask();


};


#endif
