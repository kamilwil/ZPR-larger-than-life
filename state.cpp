//State.cpp

#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"
#include <algorithm>


/// State Class - representing the current state of the board
/// Fields:
/// std::set<Cell> active_cells_ - set of currently alive cells
/// std::set<Cell> inactive_cells_ - set of used-to-be alive cells
/// int it_number_ - number of game's iteration

    /// Default State constructor
    State::State()=default;
    /// Default State destructor
    State::~State()=default;
    
    /// Three-input constructor with fields similar to one in class
    State::State(const std::set<Cell>& active_cells, const std::set<Cell>& inactive_cells, int it_number){
        active_cells_ = active_cells;
        inactive_cells_ = inactive_cells;
        it_number_ = it_number;
    }
    
    /// Function adding a Cell to active_cells_
    /// Inputs:
    /// Cell cell - cell to be inserted
    /// Outputs:
    /// none(void)
    void State::addActiveCell(Cell cell){active_cells_.insert(cell);}

    /// Funkcja removing a Cell from active_cells_
    /// Inputs:
    /// Cell cell - cell to be erased
    /// Outputs:
    /// none(void)
    void State::removeActiveCell(Cell cell){
        active_cells_.erase(cell);
    }
    /// Function adding a Cell to inactive_cells_
    /// Inputs:
    /// Cell cell - cell to be inserted
    /// Outputs:
    /// none(void)
    void State::addInactiveCell(Cell cell){inactive_cells_.insert(cell);}

    /// Function removing a Cell from inactive_cells_
    /// Inputs:
    /// Cell cell - cell to be erased
    /// Outputs:
    /// none(void)
    void State::removeInactiveCell(Cell cell){
        inactive_cells_.erase(cell);          
    }

    std::set<Cell> State::getActiveCells(){return active_cells_;}
    std::set<Cell> State::getInactiveCells(){return inactive_cells_;}
    int State::getItNumber(){return it_number_;}
    void State::setActiveCells(const std::set<Cell>& active_cells){active_cells_ = active_cells;}
    void State::setInactiveCells(const std::set<Cell>& inactive_cells){inactive_cells_ = inactive_cells;}
    void State::setItNumber(int it){it_number_ = it;}





