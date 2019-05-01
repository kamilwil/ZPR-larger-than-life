//State.hpp

#ifndef STATE_HPP
#define STATE_HPP
#include <set>
#include <unordered_set>
#include <iterator>


class State{
    std::unordered_set<Cell> active_cells;
    std::set<Cell> inactive_cells;
    int it_number;
public:

    State(std::unordered_set<Cell>, std::set<Cell>, int);

    void changeIteration(int);
    void addActiveCell(Cell);
    void removeActiveCell(Cell);
    void addInactiveCell(Cell);
    void removeInactiveCell(Cell);

    std::unordered_set<Cell> get_activeCells();
    std::set<Cell> get_inactiveCells();
    int getItNumber();
    void setActiveCells(std::unordered_set<Cell>);
    void setInactiveCells(std::set<Cell>);
    void setItNumber(int it);
}



















#endif