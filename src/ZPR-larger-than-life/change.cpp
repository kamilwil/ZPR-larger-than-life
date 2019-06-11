// #include <boost/python.hpp>
#include <set>
#include <iterator>
#include "change.hpp"
#include "cell.hpp"
#include <list>

/// Class Change representing changes of the cells between two iterations
/// Fields:
/// std::list<Cell> to_shift_ - list of cells for their size to be decreased in current iteration
/// std::list<Cell> to_birth_ - list of cells to be born in the current iteration_


    /// Change Constructor with arguments similar to the fields of the class
    Change::Change(const std::list<Cell>& to_shift, const std::list<Cell>& to_birth){
        to_shift_ = to_shift;
        to_birth_ = to_birth;
    }
    /// Default Change constructor
    Change::Change() = default;
    /// Default Change destructor
    Change::~Change() = default;

    std::list<Cell> Change::getToShift(){return to_shift_;}
    std::list<Cell> Change::getToBirth(){return to_birth_;}

    void Change::setToShift(const std::list<Cell>& to_shift){to_shift_ = to_shift;}
    void Change::setToBirth(const std::list<Cell>& to_birth){to_birth_ = to_birth;}

    /// Function allowing to insert cell into to_shift_ field
    /// Inputs:
    /// Cell to_shift - cell to be added
    /// Outputs:
    /// none(void)
    void Change::addToShift(Cell to_shift){to_shift_.push_back(to_shift);}
    /// Function allowing to insert cell into to_birth_ field
    /// Inputs:
    /// Cell to_birth - cell to be added
    /// Outputs:
    /// none(void)
    void Change::addToBirth(Cell to_birth){to_shift_.push_back(to_birth);}


BOOST_PYTHON_MODULE ( libchange )
{
    boost::python::class_<Change>("Change", boost::python::init<std::list<Cell>, std::list<Cell> >())
        .def( "getToShift", &Change::getToShift)
        .def( "getToBirth", &Change::getToBirth)
        ;
}
