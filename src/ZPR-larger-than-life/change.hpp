//Change.hpp
#ifndef CHANGE_HPP
#define CHANGE_HPP

#include "cell.hpp"
#include <list>
#include <iterator>


// Klasa Change, przedstawiajaca zmiany pomiedzy dwoma kolejnymi iteracjami na planszy
class Change{
    std::list<Cell> toShift;
    std::list<Cell> toBirth;

public:
    // Deklaracja publicznych konstruktorow oraz destruktora
    Change();
    ~Change();
    Change(std::list<Cell>, std::list<Cell>);

    // Deklaracja getterow oraz setterow
    std::list<Cell> getToShift();
    std::list<Cell> getToBirth();
    void setToShift(std::list<Cell>);
    void setToBirth(std::list<Cell>);
    // Deklaracja funkcji pomocniczych ulatwiajacych manipulacje na kontenerach zawartych w polach klasy
    void addToShift(Cell);
    void addToBirth(Cell);

};


#endif
