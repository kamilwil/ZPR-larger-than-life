#include <boost/python.hpp>
#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"
#include <list>

//! Class Change representing changes of the cells between two iterations
//! Fields:
//! std::list<Cell> toShift - list of cells for their size to be decreased in current iteration
//! std::list<Cell> toBirth - list of cells to be born in the current iteration_


    //! Change Constructor with arguments similar to the fields of the class
    Change::Change(const std::list<Cell>& toshifts, const std::list<Cell>& tobirths){
        toShift = toshifts;
        toBirth = tobirths;
    }
    //! Default Change constructor
    Change::Change() = default;
    //! Default Change destructor
    Change::~Change() = default;

    std::list<Cell> Change::getToShift(){return toShift;}
    std::list<Cell> Change::getToBirth(){return toBirth;}

    void Change::setToShift(const std::list<Cell>& toshifted){toShift = toshifted;}
    void Change::setToBirth(const std::list<Cell>& tobirthed){toBirth = tobirthed;}

    //! Function allowing to insert cell into toShift field
    //! Inputs:
    //! Cell toshifted - cell to be added
    //! Outputs:
    //! none(void)
    void Change::addToShift(Cell toshifted){toShift.push_back(toshifted);}
    //! Function allowing to insert cell into toBirth field
    //! Inputs:
    //! Cell tobirthed - cell to be added
    //! Outputs:
    //! none(void)
    void Change::addToBirth(Cell tobirthed){toShift.push_back(tobirthed);}


BOOST_PYTHON_MODULE ( libchange )
{
    boost::python::class_<Change>("Change", boost::python::init<std::list<Cell>, std::list<Cell> >())
        .def( "getToShift", &Change::getToShift)
        .def( "getToBirth", &Change::getToBirth)
        ;
}
