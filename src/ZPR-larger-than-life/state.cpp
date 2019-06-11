//State.cpp


#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"
#include <algorithm>



    // Implementacja publiczych destruktorow oraz konstruktorow
    State::State()=default;
    State::~State()=default;
    State::State(std::set<Cell> actives, std::set<Cell> inactives, int it){
        active_cells = actives;
        inactive_cells = inactives;
        it_number = it;
    }

//    void State::changeIteration(int i){}

    // Implementacja funkcji pomocniczych ultawiajacych na dzialanie na konterach w ramach klasy
    void State::addActiveCell(Cell cell){active_cells.insert(cell);}

    void State::removeActiveCell(Cell cell){

        active_cells.erase(cell);
    }
    void State::addInactiveCell(Cell cell){inactive_cells.insert(cell);}

    void State::removeInactiveCell(Cell cell){
        inactive_cells.erase(cell);          
    }

    // Implementacja getterow oraz setterow
    std::set<Cell> State::getActiveCells(){return active_cells;}
    std::set<Cell> State::getInactiveCells(){return inactive_cells;}
    int State::getItNumber(){return it_number;}
    void State::setActiveCells(std::set<Cell> actives){active_cells = actives;}
    void State::setInactiveCells(std::set<Cell> inactives){inactive_cells = inactives;}
    void State::setItNumber(int it){it_number = it;}





