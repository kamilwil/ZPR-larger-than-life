
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

    
friend bool operator == (const Cell &compared_cell, const Cell &compared_cell_other) {              //overloading operator required for finding objects

    if (compared_cell_other.coords == compared_cell.coords)
        return true;
    else
        return false;
    }

friend bool operator < (const Cell &compared_cell, const Cell &compared_cell_other){                //overloading operator required for sorting objects
    
    if (compared_cell.coords.first < compared_cell_other.coords.first)
        return true;
    else if (compared_cell.coords.first > compared_cell_other.coords.first)
        return false;
    else if (compared_cell.coords.second < compared_cell_other.coords.second)
        return true;
    else
        return false;   
    }



    

