#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"
#include <list>




    Change::Change(std::list<Cell> toshifts, std::list<Cell> tobirths){
        toShift = toshifts;
        toBirth = tobirths;
    }
    Change::Change() = default;
    Change::~Change() = default;

    std::list<Cell> Change::getToShift(){return toShift;}
    std::list<Cell> Change::getToBirth(){return toBirth;}

    void Change::setToShift(std::list<Cell> toshifted){toShift = toshifted;}
    void Change::setToBirth(std::list<Cell> tobirthed){toBirth = tobirthed;}

    void Change::addToShift(Cell toshifted){toShift.push_back(toshifted);}
    void Change::addToBirth(Cell tobirthed){toShift.push_back(tobirthed);}




