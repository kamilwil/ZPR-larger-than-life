//game.hpp

#include <map>
#include <set>
#include "cell.hpp"
#include "change.hpp"

#include "state.hpp"



class Game{

    std::map<int,int> rules;
    std::set<Change> changes;
    State state;

public:
    Game::Game()=default;
    const int GAME_LENGTH=100;
    const int BOARD_SIZE=100;

    Game(int length,int size,std::map<int,int> rulings,std::set<Change> changes, State state){}


    std::map<int,int> getRules(){}
    std::set<Change> getChanges(){}
    State getState(){}
    int getGameLength(){return 1;}
    int getBoardSize(){return 1;}

    void setRules(std::map<int,int> rules){}
    void setChanges(std::set<Change> changes){}
    void setState(State state){}

    void updateState(Change change,int direction){}
    void generateChanges(){}

    int sendChanges(Change change,int it){return 1;}

    void receiveRules(){}
    void receiveStartingPosition(){}
    void receiveTask(){}


};

