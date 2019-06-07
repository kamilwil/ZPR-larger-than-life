//Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP
#include <utility>

class Cell{
    std::pair<int,int> coords;
    int state;

public:
    Cell();
    ~Cell();
    Cell(int, int, int);
    int getXcoord();
    int getYcoord();
    std::pair<int,int> getCoords();
    void setXcoord(int);
    void setYcoord(int);
    void setState(int);
    void setCoords(int, int);
    bool operator== (const Cell &compared_cell);
    bool operator < (const Cell &compared_cell);
    
};

#endif
