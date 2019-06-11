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

    friend bool operator == (const Cell &compared_cell, const Cell &compared_cell_other)             //overloading operator for Cell findings
    friend bool operator < (const Cell &compared_cell, const Cell &compared_cell_other)             //overloading operator for Cell sorting

};

#endif
