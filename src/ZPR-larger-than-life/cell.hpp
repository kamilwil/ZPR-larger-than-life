//Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP
#include <utility>

// Klasa Cell obslugujaca pojedyncze pole na planszy
class Cell{
    std::pair<int,int> coords;
    int state;

public:
    // Deklaracja publicznych konstruktorow i destruktora domyslnego
    Cell();
    ~Cell();
    Cell(int, int, int);
    // Deklaracja publicznych getterow oraz setterow
    int getXcoord();
    int getYcoord();
    int getState();
    std::pair<int,int> getCoords();
    void setXcoord(int);
    void setYcoord(int);
    void setState(int);
    void setCoords(int, int);

    // Operator == dla Cell, porównywane jest jedynie pole coords
   friend bool operator == (const Cell &compared_cell, const Cell &compared_cell_other)               // Przeciazamy operator potrzebny do funkcji find 
{
    if (compared_cell_other.coords == compared_cell.coords)
        return true;
    else
        return false;

}
    // Operator mniejszosci dla Cell, porównywane najpierw jest coords.first potem coords.second
    friend bool operator < (const Cell &compared_cell, const Cell &compared_cell_other){                //P rzeciazamy operator potrzebny dla std::set do sortowania obiektow
    if (compared_cell.coords.first < compared_cell_other.coords.first)
        return true;
    else if (compared_cell.coords.first > compared_cell_other.coords.first)
        return false;
    else if (compared_cell.coords.second < compared_cell_other.coords.second)
        return true;
    else
        return false;  
    
}
    Cell& operator= (Cell&);
    Cell& operator= (Cell&&);




};

#endif
