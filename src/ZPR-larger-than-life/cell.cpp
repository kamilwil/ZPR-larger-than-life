
#include "cell.hpp"
#include <utility>

//! Klasa Cell obslugujaca pojedyncza pola planszy i przechowuje jej stan.
//! Pola klasy:
//! std::pair coords - przechowuje koordynaty danej komorki
//! int state - przechowuje stan (wartosc liczbowa) danej komorki

    
Cell::Cell() = default;             //!< Domyslny konstruktor klasy
Cell::~Cell() = default;            //!< Domyslny destruktor klasy
Cell::Cell(int x, int y, int st){   //!< Trojargumentowy konstruktor klasy przyjmujacy argumenty analogiczne do pol klasy
    coords = std::make_pair(x,y);
    state = st;
}
    
void Cell::setCoords(int x, int y){coords.first = x; coords.second = y;}   
std::pair<int,int> Cell::getCoords(){return coords;}
int Cell::getXcoord(void){return coords.first;}
int Cell::getYcoord(void){return coords.second;}
int Cell::getState(void){return state;}
void Cell::setXcoord(int x){coords.first = x;}
void Cell::setYcoord(int y){coords.second = y;}
void Cell::setState(int st){state = st;}

    




    

