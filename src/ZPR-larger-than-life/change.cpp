#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"




    Change::Change(std::set<Cell> toshifts, std::set<Cell> tobirths){}
    Change::Change()=default;
    Change::~Change()=default;

    std::set<Cell> Change::getToShift(){return toShift;}
    std::set<Cell> Change::getToBirth(){return toBirth;}

    void Change::setToShift(std::set<Cell> toshifted){}
    void Change::setToBirth(std::set<Cell> tobirthed){}

    void Change::addToShift(std::set<Cell> toshifted){}
    void Change::addToBirth(std::set<Cell> tobirthed){}




