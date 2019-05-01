//Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP

class Cell{
    int x_coord;
    int y_coord;
    int state;

public:
    Cell(int, int, int);
    int getXcoord();
    int getYcoord();
    void setXcoord(int);
    void setYcoord(int);
    void setState(int);
};

#endif