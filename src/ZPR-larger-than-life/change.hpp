//Change.hpp
#ifndef CHANGE_HPP
#define CHANGE_HPP

#include "cell.hpp"
#include <set>
#include <iterator>


class Change{

    std::set<Cell*> toShift;
    std::set<Cell*> toBirth;

public:
    Change();
    ~Change();
    Change(std::set<Cell*>, std::set<Cell*>);

    std::set<Cell*> getToShift();
    std::set<Cell*> getToBirth();
    void setToShift(std::set<Cell*>);
    void setToBirth(std::set<Cell*>);

    void addToShift(Cell*);
    void addToBirth(Cell*);

};


#endif
