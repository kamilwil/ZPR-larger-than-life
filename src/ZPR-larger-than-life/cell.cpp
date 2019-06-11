
#include "cell.hpp"
#include <utility>

/// Cell class representing a single cell on the board
/// Fields:
/// std::pair coords_ - coordinates of cell
/// int state_ - state of the cell

/// default Cell constructor    
Cell::Cell() = default;  
/// default Cell destructor
Cell::~Cell() = default;    
/// Constructor with arguments similar to the fields of the class        
Cell::Cell(int x, int y, int state){   
    coords_ = std::make_pair(x,y);
    state_ = state;
}
    
void Cell::setCoords(int x, int y){coords_.first = x; coords_.second = y;}   
std::pair<int,int> Cell::getCoords(){return coords_;}
int Cell::getXcoord(void){return coords_.first;}
int Cell::getYcoord(void){return coords_.second;}
int Cell::getState(void){return state_;}
void Cell::setXcoord(int x){coords_.first = x;}
void Cell::setYcoord(int y){coords_.second = y;}
void Cell::setState(int st){state_ = st;}

