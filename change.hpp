//Change.hpp
#ifndef CHANGE_HPP

#include <unordered_set>
#include <iterator>
#include "cell.hpp"

class Change{

    std::unordered_set<Cell> toShift;
    std::unordered_set<Cell> toBirth;

public:
    Change(std::unordered_set<Cell>, std::unordered_set<Cell>);

    std::unordered_set<Cell> getToShift();
    std::unordered_set<Cell> getToBirth();
    void setToShift(std::unordered_set<Cell>);
    void setToBirth(std::unordered_set<Cell>);

    void addToShift(std::unordered_set<Cell>);
    void addToBirth(std::unordered_set<Cell>);


}


#endif