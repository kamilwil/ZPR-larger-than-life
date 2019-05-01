#include <unordered_set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"


Change::Change(std::unordered_set<Cell> toshifts, std::unordered_set<Cell> tobirths){}

std::unordered_set<Cell> Change::getToShift(){}
std::unordered_set<Cell> Change::getToBirth(){}

void Change::setToShift(std::unordered_set<Cell> toshifted){}
void Change::setToBirth(std::unordered_set<Cell> tobirthed){}

void Change::addToShift(std::unordered_set<Cell> toshifted){}
void Change::addToBirth(std::unordered_set<Cell> tobirthed){}



