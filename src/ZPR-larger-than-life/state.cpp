//State.cpp




#include <set>
#include <iterator>
#include "cell.hpp"
#include "state.hpp"
#include <algorithm>


//* Klasa obrazujaca obecny stan planszy
//* Wartosci pol:
//* std::set<Cell> active cells - kolekcja obecnie zywych komorek
//* std::set<Cell> inactive cells - kolekcja niegdys zywych komorek
//* int it_number - numer iteracji gry

    //* Konstruktor domyslny klasy State
    State::State()=default;
    //* Destruktor domyslny klasy State
    State::~State()=default;
    
    //* Konstruktor trojargumentowy klasy State o argumentach analogicznych do pol klasy
    State::State(std::set<Cell> actives, std::set<Cell> inactives, int it){
        active_cells = actives;
        inactive_cells = inactives;
        it_number = it;
    }
    
    //* Funkcja dodajaca aktywna komorke do active_cells
    //* Przyjmowane argumenty:
    //* Cell cell - komorka do wstawienia
    //* Zwracane wartosci:
    //* brak(void)
    void State::addActiveCell(Cell cell){active_cells.insert(cell);}

    //* Funkcja usuwajaca komorke z active_cells
    //* Przyjmowane argumenty:
    //* Cell cell - komorka do usuniecia
    //* Zwracane wartosci:
    //* brak(void)
    void State::removeActiveCell(Cell cell){
        active_cells.erase(cell);
    }
    //* Funkcja dodajaca komorke do inactive_cells
    //* Przyjmowane argumenty:
    //* Cell cell - komorka do wstawienia
    //* Zwracane wartosci:
    //* brak(void)
    void State::addInactiveCell(Cell cell){inactive_cells.insert(cell);}

    //* Funkcja usuwajaca komorke z inactive_cells
    //* Przyjmowane argumenty:
    //* Cell cell - komorka do usuniecia
    //* Zwracane wartosci:
    //* brak(void)
    void State::removeInactiveCell(Cell cell){
        inactive_cells.erase(cell);          
    }

    std::set<Cell> State::getActiveCells(){return active_cells;}
    std::set<Cell> State::getInactiveCells(){return inactive_cells;}
    int State::getItNumber(){return it_number;}
    void State::setActiveCells(std::set<Cell> actives){active_cells = actives;}
    void State::setInactiveCells(std::set<Cell> inactives){inactive_cells = inactives;}
    void State::setItNumber(int it){it_number = it;}





