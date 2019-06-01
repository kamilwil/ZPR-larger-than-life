//Cell.cpp
#include "cell.hpp"
#include <pair>

    Cell::Cell() = default;
    Cell::~Cell() = default;
    Cell::Cell(int x, int y, int st){
        coords = std::make_pair(x,y);
        state = st;
    }
        
    void Cell::setCoords(x,y){coords.first = x; coords.second = y;}
    std::pair<int,int> Cell::getCoords(){return coords;}
    int Cell::getXcoord(void){return coords.first;}
    int Cell::getYcoord(void){return coords.second;}
    void Cell::setXcoord(int x){x_coord = x;}
    void Cell::setYcoord(int y){y_coord = y;}
    void Cell::setState(int st){state = st;}


bool Cell::operator< (const Cell &compared_cell) const                //przeciazamy operator potrzebny dla std::set do sortowania obiektow
{
    if (cell.coords.first < compared_cell.cords.first)
        return 1;
    else if (cell.coords.first > compared_cell.cords.first)
        return 0;
    else if (cell.coords.second < compared_cell.cords.second)
        return 1;
    else
        return 0;  
}
    

