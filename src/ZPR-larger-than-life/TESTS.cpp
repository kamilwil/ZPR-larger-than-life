#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include "game.hpp"
#include "cell.hpp"
#include "change.hpp"
#include "rules.hpp"


BOOST_AUTO_TEST_SUITE (CellSuite)
BOOST_AUTO_TEST_CASE (testCellConstruct)
{
    BOOST_CHECK (Cell(1,2,3).coords == std::make_pair(1,2));
    BOOST_CHECK (Cell(1,2,3).state == 3);

}
BOOST_AUTO_TEST_CASE (testSetGetConstruct)
{
    BOOST_CHECK (Cell(1,2,3).setCoords(4,5).coords == std::make_pair(4,5));
    BOOST_CHECK (Cell(1,2,3).coords == Cell::getCoords);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE (StateSuite)

BOOST_AUTO_TEST_CASE (testStateConstruct)
{
    std::set<Cell> test_set1;
    test_set1.insert(Cell(1,2,3));
    std::set<Cell> test_set2;
    test_set2.insert(Cell(4,5,6));
    BOOST_CHECK (State(test_set1, test_set2).getActiveCells() == test_set1);
    BOOST_CHECK (State(test_set1, test_set2).getInactiveCells()== test_set2);

}

BOOST_AUTO_TEST_CASE (testAddingCells)
{
    std::set<Cell> test_set1;
    std::set<Cell> test_set2;
    State state_t = State(test_set1, test_set2, 0);
    state_t.addActiveCell(Cell(1,2,3));
    BOOST_CHECK (state_t.getActiveCells().size() == 1);

}

BOOST_AUTO_TEST_CASE (testRemovingCells)
{
    std::set<Cell> test_set1;
    std::set<Cell> test_set2;
    test_set2.insert(Cell(1,2,3));
    test_set2.removeInactiveCell(Cell(1,2,19));
    State state_t = State(test_set1, test_set2, 0);
    BOOST_CHECK (change_t.getInactiveCells().size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE (ChangeSuite)

BOOST_AUTO_TEST_CASE (testChangeConstructor)
{
    std::list<Cell> test_list1;
    std::list<Cell> test_list2;
    test_list1.push_back(Cell(1,2,3));
    test_list2.push_back(Cell(4,5,6));
    BOOST_CHECK (Change(test_list1, test_list2, 0).getToBirth == test_list1);
    BOOST_CHECK (Change(test_list1, test_list2, 0).getToBirth == test_list2);
}

BOOST_AUTO_TEST_CASE (testAddingCells)
{
    std::list<Cell> test_list1;
    std::list<Cell> test_list2;
    Change change_t = Change(test_set1, test_set2, 0);
    change_t.addToBirth(Cell(1,2,3));
    BOOST_CHECK (state_t.getToBirth().size() == 1);
}