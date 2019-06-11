//State.cpp

#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"
#include <algorithm>


/// State Class - representing the current state of the board
/// Fields:
/// std::set<Cell> active cells - set of currently alive cells
/// std::set<Cell> inactive cells - set of used-to-be alive cells
/// int it_number - number of game's iteration

    /// Default State constructor
    State::State()=default;
    /// Default State destructor
    State::~State()=default;
    
    /// Three-input constructor with fields similar to one in class
    State::State(const std::set<Cell>& actives, const std::set<Cell>& inactives, int it){
        active_cells = actives;
        inactive_cells = inactives;
        it_number = it;
    }
    
    /// Function adding a Cell to active_cells
    /// Inputs:
    /// Cell cell - cell to be inserted
    /// Outputs:
    /// none(void)
    void State::addActiveCell(Cell cell){active_cells.insert(cell);}

    /// Funkcja removing a Cell from active_cells
    /// Inputs:
    /// Cell cell - cell to be erased
    /// Outputs:
    /// none(void)
    void State::removeActiveCell(Cell cell){
        active_cells.erase(cell);
    }
    /// Function adding a Cell to inactive_cells
    /// Inputs:
    /// Cell cell - cell to be inserted
    /// Outputs:
    /// none(void)
    void State::addInactiveCell(Cell cell){inactive_cells.insert(cell);}

    /// Function removing a Cell from inactive_cells
    /// Inputs:
    /// Cell cell - cell to be erased
    /// Outputs:
    /// none(void)
    void State::removeInactiveCell(Cell cell){
        inactive_cells.erase(cell);          
    }

    std::set<Cell> State::getActiveCells(){return active_cells;}
    std::set<Cell> State::getInactiveCells(){return inactive_cells;}
    int State::getItNumber(){return it_number;}
    void State::setActiveCells(const std::set<Cell>& actives){active_cells = actives;}
    void State::setInactiveCells(const std::set<Cell>& inactives){inactive_cells = inactives;}
    void State::setItNumber(int it){it_number = it;}





