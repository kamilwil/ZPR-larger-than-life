//game.hpp

#include <boost/python.hpp>
#include <set>
#include <deque> 
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>  
#include <cmath>     
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"
#include "rules.hpp"



/// Class Game being our instance of a game.
/// Fields:
/// Rules rules_ - structure with parameters regarding rules of the game
/// std::deque<Change> changes_ - container with a Change object for each of the game's iterations
/// State state_ - State object - our current board state

typedef std::map<std::pair<int,int>,int>::iterator Findertype;
typedef std::set<Cell>::iterator Stateiteratortype;

/// Default Game constructor
Game::Game()=default;
/// Default Game destructor
Game::~Game()=default;
/// Game constructor with three inputs, similar to fields in the class
Game::Game(const Rules& rules, const std::deque<Change>& changes, const State& state){
    rules_ = rules;
    changes_ = changes;
    state_ = state;
}

/// Function updating a particular cell in influence_map 
/// Inputs:
/// std::map<std::pair<int,int>,int>* influence_map - representing influence (number of neighbours)
/// int x_index - x coordinate of a cell
/// int y_index - y coordinate of a cell
/// Outputs:
/// none (void)
void Game::updateRecord(std::map<std::pair<int, int>, int>* influence_map, int x_index, int y_index){
    std::pair<int,int> to_find = std::make_pair(x_index, y_index);
    Findertype finder = influence_map->find(to_find);
        
    if (finder == influence_map->end()){           // when in there is no such key in the map
        influence_map->insert(std::make_pair(to_find, 1));
    }
    else{                                          // otherwise
        (*influence_map)[to_find] += 1;
    }    
}

/// Function updating all cells in influence_map affected by a particular Cell
/// Inputs:
/// std::map<std::pair<int,int>,int>* influence_map - representing influence (number of neighbours)
/// Cell current_cell - influencing Cell
/// Outputs:
/// none (void)
void Game::includeCellInfluence(std::map<std::pair<int, int>, int>* influence_map, Cell  current_cell){
       
    int current_x = current_cell.getXcoord();
    int current_y = current_cell.getYcoord(); 
            
    if (rules_.neighbourhood_ == NeighbourhoodType::MOORE)
        for (auto x_offset = std::max(-rules_.range_, -current_x) ; x_offset <= std::min(rules_.range_, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = std::max(-rules_.range_, -current_y) ; y_offset <= std::min(rules_.range_, BOARD_SIZE-1-current_y); ++y_offset) 
                Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);
    
    else if (rules_.neighbourhood_ == NeighbourhoodType::NEUM)
        for (auto x_offset = std::max(-rules_.range_, -current_x) ; x_offset <= std::min(rules_.range_, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -std::abs(rules_.range_ - std::abs(x_offset)); y_offset <= std::abs(rules_.range_ - std::abs(x_offset)); ++y_offset) 
                 Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);      
        
    else if (rules_.neighbourhood_ == NeighbourhoodType::CIRC)
        for (auto x_offset = std::max(-rules_.range_, -current_x) ; x_offset <= std::min(rules_.range_, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -floor(sqrt(pow(rules_.range_ + 0.5, 2) - pow(x_offset, 2))); y_offset <= floor(sqrt(pow(rules_.range_ + 0.5, 2) - pow(x_offset, 2))); ++y_offset) 
                 Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);            
                  
}
    
/// Function generating an influence map
/// Inputs:
/// none
/// Outputs:
/// std::map<std::pair<int,int>,int> influence_map - representing influence (number of neighbours)
std::map<std::pair<int, int>, int> Game::generateInfluenceMap(){
        
    std::map<std::pair<int, int>, int> influence_map;
        
    for(Stateiteratortype it = state_.getActiveCells().begin(); it != state_.getActiveCells().end(); ++it)
        this->includeCellInfluence(&influence_map, *it);                        
    
    return influence_map;
}

/// Funkcja generating Change object with regard to influence map
/// Inputs:
/// std::map<std::pair<int,int>,int>* influence_map - representing influence (number of neighbours)
/// Outputs:
/// none (void)
void Game::generateChange(std::map<std::pair<int, int>, int>* influence_map){
    Change* change_i = new Change();

    for(Findertype it = influence_map->begin(); it != influence_map->end(); ++it){
       
        
        Stateiteratortype cell_find = std::find( state_.getActiveCells().begin(),  state_.getActiveCells().end(), Cell((it->first).first, (it->first).second, 0));

        if (cell_find != state_.getActiveCells().end()){
            if ((it->second < rules_.smin_ + 1 - rules_.m_) || (it->second  > rules_.smax_ + 1 - rules_.m_)){                 //survivability condition not reached
                change_i->addToShift((*cell_find));
                break;
            }                                                                                                         //otherwise we do nothing                        
        }              
        else if ((it->second >= rules_.bmin_ + 1 - rules_.m_) && (it->second  <= rules_.bmax_ + 1 - rules_.m_)){     //being here means there is no such cell in container
            change_i->addToBirth((*cell_find));                                                              //so we may want to create it
        }                                                                                
                                   
    }
    changes_.push_back(*(change_i));
}

/// Function changing state field with regard to Change
/// Inputs:
/// Change change - Change object
/// Outputs:
/// none (void)
void Game::implementChange (Change change){
    for (std::list<Cell>::iterator it = change.getToBirth().begin(); it != change.getToBirth().end(); ++it){
        
        auto it_cell = std::find(state_.getInactiveCells().begin(), state_.getInactiveCells().end(), (*it));           // checking if cell is not already there
        if (it_cell == state_.getInactiveCells().end()){                                                              //if there is not we create it
            (*it).setState(rules_.states_);                                                   
            state_.addActiveCell(*it);
        }
        else{
            state_.removeInactiveCell(*it);
            (*it).setState(rules_.states_);               //setting to a max state value        
            state_.addActiveCell(*it);
        }
    }

    for (std::list<Cell>::iterator it2 = change.getToShift().begin(); it2 != change.getToShift().end(); ++it2){
        auto it_cell = std::find(state_.getActiveCells().begin(), state_.getActiveCells().end(), (*it2));           // checking if cell is in inactive cells (assuming such cell exists)
                                 
        it2->setState(it2->getState() - 1);
        if (it2->getState() == 0){
            state_.removeActiveCell(*it2);
            state_.addInactiveCell(*it2);
        }
    } 
}
    
    Rules Game::getRules(){return rules_;}
    std::deque<Change> Game::getChanges(){return changes_;}
    State Game::getState(){return state_;}

    void Game::setRules(const Rules& rulings){rules_ = rulings;}
    void Game::setChanges(const std::deque<Change>& change_list){changes_ = change_list;}
    void Game::setState(const State& status){state_ = status;}


    /// Function matching field change_list with changes at each iteration of the game
    /// Inputs:
    /// none
    /// Outputs:
    /// none (void)
    void Game::generateAllChanges(){

        // change_list[0] is received from interface
        for (int i = 1; i < GAME_LENGTH; ++i){
            std::map<std::pair<int, int>, int> influence_map = generateInfluenceMap();
            generateChange(&influence_map);
            implementChange(changes_[i]);
        }
        
    }
    


   Rules Game::receiveRules(const boost::python::list& l)
    {
        int rcv_range = boost::python::extract<int> (l[0]);
        int rcv_states = boost::python::extract<int> (l[1]);
        int rcv_smin = boost::python::extract<int> (l[3]);
        int rcv_smax = boost::python::extract<int> (l[4]);
        int rcv_bmin = boost::python::extract<int> (l[5]);
        int rcv_bmax = boost::python::extract<int> (l[6]);
        int rcv_m = boost::python::extract<int> (l[2]);
        int rcv_n = boost::python::extract<char> (l[7]);
        NeighbourhoodType rcv_neighbourhood = NeighbourhoodType::MOORE;

        switch (rcv_n)
        {
            case 'M':
                rcv_neighbourhood = NeighbourhoodType::MOORE;
                break;
            case 'C':
                rcv_neighbourhood = NeighbourhoodType::NEUM;
                break;
            case 'N':
                rcv_neighbourhood = NeighbourhoodType::CIRC;
                break;
        }

        Rules out = Rules(rcv_neighbourhood, rcv_range, rcv_states, rcv_smin, rcv_smax, rcv_bmin, rcv_bmax, rcv_m);
        return out;
    }



