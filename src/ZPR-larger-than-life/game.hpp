//game.hpp

#ifndef GAME_HPP
#define GAME_HPP

#include <set>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "change.hpp"
#include "state.hpp"
#include <map>
#include <utility>
#include <set>
#include "rules.hpp"



class Game{

    Rules rules;
    std::deque<Change> changes;
    State state;

public:
    Game();
    ~Game();
    Game(Rules,std::deque<Change>,State);


    const static int GAME_LENGTH=100;
    const static int BOARD_SIZE=100;

    

    Rules getRules();
    std::deque<Change> getChanges();
    State getState();
    
    void setRules(Rules);
    void setChanges(std::deque<Change>);
    void setState(State);

    void updateState(Change,int);
    void generateChanges();

    int sendChanges(Change,int);

    void receiveRules();
    void receiveStartingPosition();
    void receiveTask();

    void updateRecord(std::map<std::pair<int, int>, int>*, int, int);
    void includeCellInfluence(std::map<std::pair<int, int>, int>*, Cell);
    std::map<std::pair<int, int>, int> generateInfluenceMap();
    void generateChange(std::map<std::pair<int, int>, int>*);
    void implementChange (Change);
    void generateAllChanges();


};


#endif
