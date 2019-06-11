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


// Glowna klasa Game, zawiera informacje o zasadach, obecnym stanie planszy oraz liscie wszystkich zmian w obrebie gry
class Game{

    Rules rules;
    std::deque<Change> changes;
    State state;

public:
    // Deklaracja publicznych konstruktorow oraz destruktora
    Game();
    ~Game();
    Game(Rules,std::deque<Change>,State);

    // Definicja stalych: dlugosci gry oraz rozmiaru planszy
    const static int GAME_LENGTH=100;
    const static int BOARD_SIZE=100;

    // Deklaracja getterow oraz setterow
    Rules getRules();
    std::deque<Change> getChanges();
    State getState();
    
    void setRules(Rules);
    void setChanges(std::deque<Change>);
    void setState(State);

    // Deklaracja funkcji generujacych kolejne algorytmy 
    void updateState(Change,int);
    void generateChanges();
    void updateRecord(std::map<std::pair<int, int>, int>*, int, int);
    void includeCellInfluence(std::map<std::pair<int, int>, int>*, Cell);
    std::map<std::pair<int, int>, int> generateInfluenceMap();
    void generateChange(std::map<std::pair<int, int>, int>*);
    void implementChange (Change);
    void generateAllChanges();

    // Deklaracje funkcji do komunikacji z modulem pythonowym
    int sendChanges(Change,int);
    void receiveRules();
    void receiveStartingPosition();
    void receiveTask();


};


#endif
