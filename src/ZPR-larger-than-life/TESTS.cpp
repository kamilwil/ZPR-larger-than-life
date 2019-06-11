#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include "game.hpp"
#include "cell.hpp"
#include "change.hpp"
#include "rules.hpp"


BOOST_AUTO_TEST_SUITE (CellSuite)
    
BOOST_AUTO_TEST_CASE (testCellConstruct){
    BOOST_CHECK (Cell(1,2,3).getCoords() == std::make_pair(1,2));
    BOOST_CHECK (Cell(1,2,3).getState() == 3);

}

BOOST_AUTO_TEST_CASE (overloadTest){
    BOOST_CHECK (Cell(1,2,3) == Cell(1,2,4));
    BOOST_CHECK (!(Cell(2,4,6) == Cell(2,8,6)));
    BOOST_CHECK (!(Cell(2,4,6) == Cell(4,2,6)));
    BOOST_CHECK (Cell(1,2,3) < Cell(3,2,1));
    BOOST_CHECK (!(Cell(2,2,2) < Cell(2,2,3)));
}

BOOST_AUTO_TEST_CASE (testSetGetConstruct){
    Cell cell_1 = Cell(1,2,3);
    cell_1.setCoords(4,5);
    BOOST_CHECK (cell_1.getCoords() == std::make_pair(4,5));
    Cell cell_2 = Cell(5,6,7);
    BOOST_CHECK (cell_2.getXcoord() == 5);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE (StateSuite)

BOOST_AUTO_TEST_CASE (testStateConstruct){
    std::set<Cell> test_set1;
    test_set1.insert(Cell(1,2,3));
    std::set<Cell> test_set2;
    test_set2.insert(Cell(4,5,6));
    State test_state = State(test_set1, test_set2, 0);
    BOOST_CHECK (test_state.getActiveCells() == test_set1);
    BOOST_CHECK (test_state.getInactiveCells() == test_set2);

}



BOOST_AUTO_TEST_CASE (testAddingStateCells){
    std::set<Cell> test_set1;
    std::set<Cell> test_set2;
    State state_t = State(test_set1, test_set2, 0);
    state_t.addActiveCell(Cell(1,2,3));
    BOOST_CHECK (state_t.getActiveCells().size() == 1);

}

BOOST_AUTO_TEST_CASE (testRemovingStateCells){
    std::set<Cell> test_set1;
    std::set<Cell> test_set2;
    test_set2.insert(Cell(1,2,3));
    State state_t = State(test_set1, test_set2, 0);
    state_t.removeInactiveCell(Cell(1,2,19));
    BOOST_CHECK (state_t.getInactiveCells().size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE (ChangeSuite)

BOOST_AUTO_TEST_CASE (testChangeConstructor){
    std::list<Cell> test_list1;
    std::list<Cell> test_list2;
    test_list1.push_back(Cell(1,2,3));
    test_list2.push_back(Cell(4,5,6));
    BOOST_CHECK (Change(test_list1, test_list2).getToBirth() == test_list1);
    BOOST_CHECK (Change(test_list1, test_list2).getToBirth() == test_list2);
}

BOOST_AUTO_TEST_CASE (testAddingChangeCells){
    std::list<Cell> test_list1;
    std::list<Cell> test_list2;
    Change change_t = Change(test_list1, test_list2);
    change_t.addToBirth(Cell(1,2,3));
    BOOST_CHECK (change_t.getToBirth().size() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
                                 

BOOST_AUTO_TEST_SUITE(GameSuite)
                                 
BOOST_AUTO_TEST_CASE (EasyFunctions){
    Rules rules = Rules(NeighbourhoodType::MOORE, 1, 1, 1, 1, 1, 1, 1);
    std::deque<Change> test_changes;
    test_changes.push_front(Change());
    State test_state = State();
    BOOST_CHECK ( Game(rules, test_changes, test_state).getRules().smin == rules.smin);    
}
           
BOOST_AUTO_TEST_CASE (updateRecordTest){
    Rules test_rules = Rules(NeighbourhoodType::MOORE, 1, 1, 1, 1, 1, 1, 1);
    std::deque<Change> test_changes;
    State test_state = State();
    Game test_game = Game(test_rules, test_changes, test_state);
    std::map<std::pair<int, int>, int> influence_map_test; 
    test_game.updateRecord( &influence_map_test, 1, 1);
    test_game.updateRecord( &influence_map_test, 1, 1);
    test_game.updateRecord( &influence_map_test, -1, 2);
    test_game.updateRecord( &influence_map_test, 2, -1);
    BOOST_CHECK (influence_map_test[std::make_pair(1,1)] == 2);
    BOOST_CHECK (influence_map_test[std::make_pair(-1,2)] == 1);
    BOOST_CHECK (influence_map_test.size() == 3);
    
}
                               
BOOST_AUTO_TEST_CASE (generateInfluemceMapTest){
    Rules test_rules = Rules(NeighbourhoodType::NEUM, 2, 1, 1, 1, 1, 1, 1);
    std::deque<Change> test_changes;
    State test_state = State();
    test_state.addActiveCell(Cell(1,0,2));
    test_state.addActiveCell(Cell(3,0,0));
    Game game_test = Game(test_rules, test_changes, test_state);
    std::map<std::pair<int, int>, int> influence_map_test = game_test.generateInfluenceMap();
    BOOST_CHECK (influence_map_test.size() == 21);
    BOOST_CHECK (influence_map_test[std::make_pair(2,1)] == 2);         
}

BOOST_AUTO_TEST_CASE (implementChangeTest){
	Rules test_rules = Rules(NeighbourhoodType::NEUM, 2, 1, 1, 1, 1, 1, 1);
}
}

                               
