//State.hpp

#ifndef STATE_HPP
#define STATE_HPP
#include <set>
#include <iterator>
#include "cell.hpp"



class State{
    std::set<Cell> active_cells;
    std::set<Cell> inactive_cells;
    int it_number;
public:
    State();
    ~State();
    State(std::set<Cell>, std::set<Cell, int);

//    void changeIteration(int);
    void addActiveCell(Cell);
    void removeActiveCell(Cell);
    void addInactiveCell(Cell);
    void removeInactiveCell(Cell);

    std::set<Cell>  get_activeCells();
    std::set<Cell>  get_inactiveCells();
    int getItNumber();
    void setActiveCells(std::set<Cell>);
    void setInactiveCells(std::set<Cell>);
    void setItNumber(int it);
};








#endif
