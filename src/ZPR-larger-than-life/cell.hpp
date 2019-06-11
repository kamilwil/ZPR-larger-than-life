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
    friend bool operator < (const Cell &compared_cell, const Cell &compared_cell_other){                //przeciazamy operator potrzebny dla std::set do sortowania obiektow
    if (compared_cell.coords.first < compared_cell_other.coords.first)
        return true;
    else if (compared_cell.coords.first > compared_cell_other.coords.first)
        return false;
    else if (compared_cell.coords.second < compared_cell_other.coords.second)
        return true;
    else
        return false;  
    
}
    Cell& operator= (const Cell&);
    Cell&& operator= (Cell&&);




};

#endif
