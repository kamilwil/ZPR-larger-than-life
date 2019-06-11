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


    Cell& Cell::operator= (Cell& other){
        coords = other.coords;
        state = other.state;
        return *this;
    }

    Cell& Cell::operator= (Cell&& other){
        std::swap(coords, other.coords);
        std::swap(state, other.state);
        return *this;
    }

    




    

