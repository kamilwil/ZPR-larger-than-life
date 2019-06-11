//Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP
#include <utility>

class Cell{
    std::pair<int,int> coords_;
    int state_;

public:
    
    Cell();
    ~Cell();
    Cell(int, int, int);
    int getXcoord();
    int getYcoord();
    int getState();
    std::pair<int,int> getCoords();
    void setXcoord(int);
    void setYcoord(int);
    void setState(int);
    void setCoords(int, int);

friend bool operator == (const Cell &compared_cell, const Cell &compared_cell_other) {              //overloading operator required for finding objects

    if (compared_cell_other.coords_ == compared_cell.coords_)
        return true;
    else
        return false;
    }

friend bool operator < (const Cell &compared_cell, const Cell &compared_cell_other){                //overloading operator required for sorting objects
    
    if (compared_cell.coords_.first < compared_cell_other.coords_.first)
        return true;
    else if (compared_cell.coords_.first > compared_cell_other.coords_.first)
        return false;
    else if (compared_cell.coords_.second < compared_cell_other.coords_.second)
        return true;
    else
        return false;   
    }


};

#endif
