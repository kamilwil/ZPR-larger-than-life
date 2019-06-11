
#include "cell.hpp"
#include <utility>

/// Cell class representing a single cell on the board
/// Fields:
/// std::pair coords - coordinates of cell
/// int state - state of the cell

/// default Cell constructor    
Cell::Cell() = default;  
/// default Cell destructor
Cell::~Cell() = default;    
/// Constructor with arguments similar to the fields of the class        
Cell::Cell(int x, int y, int st){   
    coords = std::make_pair(x,y);
    state = st;
}
    
void Cell::setCoords(int x, int y){coords.first = x; coords.second = y;}   
std::pair<int,int> Cell::getCoords(){return coords;}
int Cell::getXcoord(void){return coords.first;}
int Cell::getYcoord(void){return coords.second;}
int Cell::getState(void){return state;}
void Cell::setXcoord(int x){coords.first = x;}
void Cell::setYcoord(int y){coords.second = y;}
void Cell::setState(int st){state = st;}

    




    

