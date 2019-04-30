#include <unordered_set>
#include <iterator>
#include "cell.hpp"

class Change{

    std::unordered_set<Cell> toShift;
    std::unordered_set<Cell> toBirth;

public:
    Change(std::unordered_set<Cell> toshifts, std::unordered_set<Cell> tobirths){}

    std::unordered_set<Cell> getToShift(){}
    std::unordered_set<Cell> getToBirth(){}
    void setToShift(std::unordered_set<Cell> toshifted){}
    void setToBirth(std::unordered_set<Cell> tobirthed){}

    void addToShift(std::unordered_set<Cell> toshifted){}
    void addToBirth(std::unordered_set<Cell> tobirthed){}

}

