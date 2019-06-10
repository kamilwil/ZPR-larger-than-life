//State.cpp


#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"
#include <algorithm>




    State::State()=default;
    State::~State()=default;
    State::State(std::set<Cell> actives, std::set<Cell> inactives, int it){
        active_cells = actives;
        inactive_cells = inactives;
        it_number = it;
    }

//    void State::changeIteration(int i){}
    void State::addActiveCell(Cell cell){active_cells.insert(cell);}

    void State::removeActiveCell(Cell cell){
/*        for(auto std::iterator<Cell> it = active_cells.begin(); it != active_cells.end(); )
            if(*it == cell)
                it = active_cells.erase(it);
                break;
            else
                ++it;*/
        active_cells.erase(std::remove(active_cells.begin(),active_cells.end(), cell),active_cells.end());
    }
    void State::addInactiveCell(Cell cell){inactive_cells.insert(cell);}

    void State::removeInactiveCell(Cell cell){
        /*for(auto std:iterator<Cell> it = inactive_cells.begin(); it != inactive_cells.end(); )
            if(*it == cell)
                it = inactive_cells.erase(it);
                break;
            else
                ++it;      */
        inactive_cells.erase(std::remove(inactive_cells.begin(), inactive_cells.end(), cell), inactive_cells.end());          
    }

    std::set<Cell> State::getActiveCells(){return active_cells;}
    std::set<Cell> State::getInactiveCells(){return inactive_cells;}
    int State::getItNumber(){return it_number;}
    void State::setActiveCells(std::set<Cell> actives){active_cells = actives;}
    void State::setInactiveCells(std::set<Cell> inactives){inactive_cells = inactives;}
    void State::setItNumber(int it){it_number = it;}





