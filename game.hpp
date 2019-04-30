//game.hpp

#ifndef GAME_HPP

#include <map>
#include <unordered_set>



class Game{

    std::map<int,int> rules;
    std::unordered_set<Change> changes;
    State state;

public:
    const int GAME_LENGTH;
    const int BOARD_SIZE;

    Game(int,int,std::map<int,int>,std::unordered_set<Change>,State);


    std::map<int,int> getRules();
    std::unordered_set<Change> getChanges();
    State getState();
    int getGameLength();
    int getBoardSize();
    
    void setRules(std::map<int,int>);
    void setChanges(std::unordered_set<Change>);
    void setState(State);

    void updateState(Change,int);
    void generateChanges();

    int sendChanges(Change,int);

    void receiveRules();
    void receiveStartingPosition();
    void receiveTask();


}











#endif