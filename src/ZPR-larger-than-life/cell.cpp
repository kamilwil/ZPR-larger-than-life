//Cell.cpp
#include "cell.hpp"

    Cell::Cell() = default;
    Cell::~Cell() = default;
    Cell::Cell(int x, int y, int st){
        x_coord = x;
        y_coord = y;
        state = st;
    }
        
    int Cell::getXcoord(void){return x_coord;}
    int Cell::getYcoord(void){return y_coord;}
    void Cell::setXcoord(int x){x_coord = x;}
    void Cell::setYcoord(int y){y_coord = y;}
    void Cell::setState(int st){state = st;}
    

