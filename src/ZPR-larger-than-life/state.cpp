//State.cpp


#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"




    State::State()=default;
    State::~State()=default;
    State::State(std::set<Cell> actives, std::set<Cell> inactives, int it){}

    void State::changeIteration(int i){}
    void State::addActiveCell(Cell cell){}
    void State::removeActiveCell(Cell cell){}
    void State::addInactiveCell(Cell cell){}
    void State::removeInactiveCell(Cell cell){}

    std::set<Cell> State::get_activeCells(){return active_cells;}
    std::set<Cell> State::get_inactiveCells(){return inactive_cells;}
    int State::getItNumber(){return 1;}
    void State::setActiveCells(std::set<Cell> actives){}
    void State::setInactiveCells(std::set<Cell> inactives){}
    void State::setItNumber(int it){}





