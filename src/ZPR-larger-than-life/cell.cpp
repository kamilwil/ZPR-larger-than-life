//Cell.cpp
#include "cell.hpp"
#include <utility>

    Cell::Cell() = default;
    Cell::~Cell() = default;
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


bool Cell::operator < (const Cell &compared_cell)                //przeciazamy operator potrzebny dla std::set do sortowania obiektow
{
    if (coords.first < compared_cell.coords.first)
        return true;
    else if (coords.first > compared_cell.coords.first)
        return false;
    else if (coords.second < compared_cell.coords.second)
        return true;
    else
        return false;  
}




    

