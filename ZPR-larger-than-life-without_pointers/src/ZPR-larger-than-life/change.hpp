//Change.hpp
#ifndef CHANGE_HPP
#define CHANGE_HPP

#include "cell.hpp"
#include <list>
#include <iterator>


class Change{

    std::list<Cell> toShift;
    std::list<Cell> toBirth;

public:
    Change();
    ~Change();
    Change(std::list<Cell>, std::list<Cell>);

    std::list<Cell> getToShift();
    std::list<Cell> getToBirth();
    void setToShift(std::list<Cell>);
    void setToBirth(std::list<Cell>);

    void addToShift(Cell);
    void addToBirth(Cell);

};


#endif
