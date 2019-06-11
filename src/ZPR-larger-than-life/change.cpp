#include <boost/python.hpp>
#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"
#include <list>

//! Klasa Change prezentujaca odpowiednie zmiany komorek pomiedzy dwoma iteracjami
//! Pola klasy:
//! std::list<Cell> toShift - lista komorek ktore w tej iteracji zmniejszana swoj stan
//! std::list<Cell> toBirth - lista komorek ktore w tej iteracji sie "rodza" (ustawiaja swoj stan na maksymalny)


    //! Konstruktor dwuelementowy klasy Change przyjmujacy analogiczne parametry co pola klasy
    Change::Change(std::list<Cell> toshifts, std::list<Cell> tobirths){
        toShift = toshifts;
        toBirth = tobirths;
    }
    //! Konstruktor domyslny
    Change::Change() = default;
    //! Destruktor domyslny
    Change::~Change() = default;

    std::list<Cell> Change::getToShift(){return toShift;}
    std::list<Cell> Change::getToBirth(){return toBirth;}

    void Change::setToShift(std::list<Cell> toshifted){toShift = toshifted;}
    void Change::setToBirth(std::list<Cell> tobirthed){toBirth = tobirthed;}

    //! Pomocnicza funkcja umozliwiajaca dostawianie obiektow typu Cell do pola toShift
    //! Przyjmowane argumenty:
    //! Cell toshifted - komorka ktora ma byc dodana do pola ToShift
    void Change::addToShift(Cell toshifted){toShift.push_back(toshifted);}
    //! Pomocnicza funkcja umozliwiajaca dostawianie obiektow typu Cell do pola toBirth
    //! Przyjmowane argumenty:
    //! Cell tosbirthed - komorka ktora ma byc dodana do pola ToBirth
    void Change::addToBirth(Cell tobirthed){toShift.push_back(tobirthed);}


BOOST_PYTHON_MODULE ( libchange )
{
    boost::python::class_<Change>("Change", boost::python::init<std::list<Cell>, std::list<Cell> >())
        .def( "getToShift", &Change::getToShift)
        .def( "getToBirth", &Change::getToBirth)
        ;
}
