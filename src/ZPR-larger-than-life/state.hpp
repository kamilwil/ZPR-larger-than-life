//State.hpp

#ifndef STATE_HPP
#define STATE_HPP
#include <set>
#include <iterator>
#include "cell.hpp"


// Klasa State, obslugujaca obecna pozycje planszy
class State{
    std::set<Cell> active_cells;
    std::set<Cell> inactive_cells;
    int it_number;
public:
    // Deklaracja publicznych konstruktorow i destruktorow
    State();
    ~State();
    State(std::set<Cell>, std::set<Cell>, int);

//    void changeIteration(int);

    // Deklaracja funkcji pomocniczych ulatwiajacych dzialanie na kontenerach zawartych w polach klasy
    void addActiveCell(Cell);
    void removeActiveCell(Cell);
    void addInactiveCell(Cell);
    void removeInactiveCell(Cell);

    // Deklaracja getterow oraz setterow
    std::set<Cell>  getActiveCells();
    std::set<Cell>  getInactiveCells();
    int getItNumber();
    void setActiveCells(std::set<Cell>);
    void setInactiveCells(std::set<Cell>);
    void setItNumber(int it);
};








#endif
