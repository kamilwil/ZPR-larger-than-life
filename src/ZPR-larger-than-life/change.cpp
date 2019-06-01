#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"




    Change::Change(std::set<Cell> toshifts, std::set<Cell> tobirths){
        toShift = toshifts;
        toBirth = tobirths;
    }
    Change::Change() = default;
    Change::~Change() = default;

    std::set<Cell> Change::getToShift(){return toShift;}
    std::set<Cell> Change::getToBirth(){return toBirth;}

    void Change::setToShift(std::set<Cell> toshifted){toShift = toshifted;}
    void Change::setToBirth(std::set<Cell> tobirthed){toBirth = tobirthed;}

    void Change::addToShift(Cell toshifted){toShift.insert(toshifted);}
    void Change::addToBirth(Cell tobirthed){toShift.insert(tobirthed);}




