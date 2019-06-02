//game.hpp

#ifndef GAME_HPP
#define GAME_HPP

#include <set>
#include <map>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "change.hpp"
#include "state.hpp"


enum class NeighbourhoodType {MOORE, NEUM, CIRC };

struct Rules {
    NeighbourhoodType neighbourhood;
    int range;
    int states;
    int smin;
    int smax;
    int bmin;
    int bmax;
    int m;
};

class Game{

    Rules rules;
    std::deque<Change*> changes;
    State* state;

public:
    Game();
    ~Game();
    const static int GAME_LENGTH=100;
    const static int BOARD_SIZE=100;

    Game(Rules,std::deque<Change*>,State*);

    Rules getRules();
    std::deque<Change*> getChanges();
    State* getState();
    
    void setRules(Rules);
    void setChanges(std::deque<Change*>);
    void setState(State*);

    void updateRecord(std::map<std::pair<int, int>, int>*, int, int);
    void includeCellInfluence(std::map<std::pair<int, int>, int>*, Cell*);
    std::map<std::pair<int, int>, int> generateInfluenceMap();
    void generateChange(std::map<std::pair<int, int>, int>);

    void implementChange (Change*);

    void updateState(Change,int);
    void generateAllChanges();

    int sendChanges(Change,int);

    void receiveRules();
    void receiveStartingPosition();
    void receiveTask();


};


#endif
