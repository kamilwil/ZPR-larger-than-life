//State.cpp

#include <set>
#include <unordered_set>
#include <iterator>
#include "cell.hpp"


class State{
    std::unordered_set<Cell> active_cells;
    std::set<Cell> inactive_cells;
    int it_number;
public:

    State(std::unordered_set<Cell> actives, std::set<Cell> inactives, int it){}

    void changeIteration(int i){}
    void addActiveCell(Cell cell){}
    void removeActiveCell(Cell cell){}
    void addInactiveCell(Cell cell){}
    void removeInactiveCell(Cell cell){}

    std::unordered_set<Cell> get_activeCells(){}
    std::set<Cell> get_inactiveCells(){}
    int getItNumber(){return 1;}
    void setActiveCells(std::unordered_set<Cell> actives){}
    void setInactiveCells(std::set<Cell> inactives){}
    void setItNumber(int it){}
};











#endif