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
    int getState();
    std::pair<int,int> getCoords();
    void setXcoord(int);
    void setYcoord(int);
    void setState(int);
    void setCoords(int, int);
   friend bool operator == (const Cell &compared_cell, const Cell &compared_cell_other)               //przeciazamy operator potrzebny do znajdowania celli
{
    if (compared_cell_other.coords == compared_cell.coords)
        return true;
    else
        return false;

}
    bool operator < (const Cell &);
    
};

#endif
