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
    State(const std::set<Cell>&, const std::set<Cell>&, int);

    void addActiveCell(Cell);
    void removeActiveCell(Cell);
    void addInactiveCell(Cell);
    void removeInactiveCell(Cell);

    std::set<Cell>  getActiveCells();
    std::set<Cell>  getInactiveCells();
    int getItNumber();
    void setActiveCells(const std::set<Cell>&);
    void setInactiveCells(const std::set<Cell>&);
    void setItNumber(int it);
};








#endif
