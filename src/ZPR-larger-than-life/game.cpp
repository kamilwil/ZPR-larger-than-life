//game.hpp

#include <set>
#include <deque> // http://www.gotw.ca/gotw/054.htm
#include "cell.hpp"
#include "change.hpp"
#include "game.hpp"
#include "state.hpp"
#include <map>
#include <deque>
#include <utility>
#include <iterator>
#include <algorithm>  // min,max (da sie bez tego ale jest czytelniej niz konstrukcja a ? b : c ; zgaduje za duzo pythona)
#include <cmath>     //sqrt, floor, ceil
#include "rules.hpp"
#include <boost/python>


typedef std::map<std::pair<int,int>,int>::iterator findertype;
typedef std::set<Cell>::iterator stateiteratortype;

// Definicja publiczynch kontruktorow oraz destruktora
Game::Game()=default;
Game::~Game()=default;

Game::Game(Rules rulings, std::deque<Change> change_list, State status){
    rules = rulings;
    changes = change_list;
    state = status;
}

// Defiinicja funkcji uaktalniajaca mape wplywu po uwzglednieniu danej komorki
void Game::updateRecord(std::map<std::pair<int, int>, int>* influence_map, int x_index, int y_index){
    std::pair<int,int> to_find = std::make_pair(x_index, y_index);
    findertype finder = influence_map->find(to_find);
        
    if (finder == influence_map->end()){           // nie ma takiego klucza https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
        influence_map->insert(std::make_pair(to_find, 1));
    }
    else{                                       // jest taki klucz
        (*influence_map)[to_find] += 1;
    }    
}

// Definicja funkcji odopowiedzialnej za generacje wplywu pojedynczej komorki na mape wplywow uwzgledniajac ograniczenia zwiazane z rozmiarem planszy oraz wartosciami pol w strukturze Rules
void Game::includeCellInfluence(std::map<std::pair<int, int>, int>* influence_map, Cell  current_cell){
       
    int current_x = current_cell.getXcoord();
    int current_y = current_cell.getYcoord();
    int min_x = (current_x > 0) ? current_x : 0;
    int max_x = (current_x < BOARD_SIZE-1) ? current_x : BOARD_SIZE - 1;     
    int min_y = (current_y > 0) ? current_y : 0;
    int max_y = (current_y < BOARD_SIZE-1) ? current_x : BOARD_SIZE - 1;   
            
    if (rules.neighbourhood == NeighbourhoodType::MOORE)
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = std::max(-rules.range, -current_y) ; y_offset <= std::min(rules.range, BOARD_SIZE-1-current_y); ++y_offset) 
                Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);
    
    else if (rules.neighbourhood == NeighbourhoodType::NEUM)
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -std::abs(rules.range - std::abs(x_offset)); y_offset <= std::abs(rules.range - std::abs(x_offset)); ++y_offset) 
                 Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);      
        
    else if (rules.neighbourhood == NeighbourhoodType::CIRC)
        for (auto x_offset = std::max(-rules.range, -current_x) ; x_offset <= std::min(rules.range, BOARD_SIZE-1-current_x); ++x_offset)
             for (auto y_offset = -floor(sqrt(pow(rules.range + 0.5, 2) - pow(x_offset, 2))); y_offset <= floor(sqrt(pow(rules.range + 0.5, 2) - pow(x_offset, 2))); ++y_offset) 
                 Game::updateRecord(influence_map, current_x + x_offset, current_y + y_offset);            
                  
}
    
// Funkcja generujaca calosciowa mape wplywow, potrzebna do generacji obiektu Change
std::map<std::pair<int, int>, int> Game::generateInfluenceMap(){
        
    std::map<std::pair<int, int>, int> influence_map;
        
    for(stateiteratortype it = state.getActiveCells().begin(); it != state.getActiveCells().end(); ++it)
        this->includeCellInfluence(&influence_map, *it);                        
    
    return influence_map;
}

// Generowanie obiektu Change w oparciu o mape wplywow dla danej iteracji 
void Game::generateChange(std::map<std::pair<int, int>, int>* influence_map){
    Change* change_i = new Change();

    for(findertype it = influence_map->begin(); it != influence_map->end(); ++it){
       
        
        stateiteratortype cell_find = std::find( state.getActiveCells().begin(),  state.getActiveCells().end(), Cell((it->first).first, (it->first).second, 0));

        if (cell_find != state.getActiveCells().end()){
        //for (stateiteratortype it2 = state.getActiveCells().begin(); it2 != state.getActiveCells().end(); ++it2){
                                            //jesli cell o takich wspolrzednych jest w active cellsach
            if ((it->second < rules.smin + 1 - rules.m) || (it->second  > rules.smax + 1 - rules.m)){                 //jesli nei jest spelniony warunek przezywalnosci
                change_i->addToShift((*cell_find));
                break;
            }                                                                           //jesli jest to nic nie robimy                           
        }              
        else if ((it->second >= rules.bmin + 1 - rules.m) && (it->second  <= rules.bmax + 1 - rules.m)){     //jseli jestesmy w tym miejscu to oznacza ze takiego cella nie ma
            change_i->addToBirth((*cell_find));   
        }                                                                                
                                   // i jesli chcemy go stworzyc to go tworzymy

    }
    changes.push_back(*(change_i));
}


// Funkcja zmieniajaca obecny stan gry w zaleznosci od stanu poprzedniego oraz obiektu Change
void Game::implementChange (Change change){
    for (std::list<Cell>::iterator it = change.getToBirth().begin(); it != change.getToBirth().end(); ++it){
        
        auto it_cell = std::find(state.getInactiveCells().begin(), state.getInactiveCells().end(), (*it));           // sprawdzamy czy nie jest w inactive cellach
        if (it_cell == state.getInactiveCells().end()){                                              //jesli nie ma to po prostu tworzymy nowa komorke w active cellsach                                                                      //state cella; prawdopodobnie da sie uniknac tego kopiowania
            (*it).setState(rules.states);                                                   //TODO: pozmieniac nazwy zmiennych zeby bylo mniej roznych statesow
            state.addActiveCell(*it);
        }
        else{
            state.removeInactiveCell(*it);
            (*it).setState(rules.states);               //ustawiamy na maksa          
            state.addActiveCell(*it);
        }
    }

    for (std::list<Cell>::iterator it2 = change.getToShift().begin(); it2 != change.getToShift().end(); ++it2){
        auto it_cell = std::find(state.getActiveCells().begin(), state.getActiveCells().end(), (*it2));           // sprawdzamy czy nie jest w inactive cellach
                                 // mniej warunkow, bo zakladamy ze taki cell jest, na przyszlosc mozna tu wyjatek zrobic
        it2->setState(it2->getState() - 1);
        if (it2->getState() == 0){
            state.removeActiveCell(*it2);
            state.addInactiveCell(*it2);
        }
    } 
}
    

    // Implementacja getterow oraz setterow
    Rules Game::getRules(){return rules;}
    std::deque<Change> Game::getChanges(){return changes;}
    State Game::getState(){return state;}

    void Game::setRules(Rules rulings){rules = rulings;}
    void Game::setChanges(std::deque<Change> change_list){changes = change_list;}
    void Game::setState(State status){state = status;}

    void Game::updateState(Change change,int direction){}


    // Funkcja generujaca wszystkie zmiany dla danej dlugosci gry
    void Game::generateAllChanges(){

        // od jedynki bo zerowa zmiane pobieramy z czesci widokowej
        for (int i = 1; i < GAME_LENGTH; ++i){
            std::map<std::pair<int, int>, int> influence_map = generateInfluenceMap();
            generateChange(&influence_map);
            implementChange(changes[i]);
        }
        
    }

    // Funkcje sluzace do komunikacji z modulem pythonowym
    int Game::sendChanges(Change change,int it){return 1;}

    Rules Game::receiveRules(const boost::python::list& l)
    {
    	int rcv_range = extract<int> l[0];
    	int rcv_states = extract<int> l[1];
    	int rcv_smin = extract<int> l[3];
    	int rcv_smax = extract<int> l[4];
    	int rcv_bmin = extract<int> l[5];
    	int rcv_bmax = extract<int> l[6];
    	int rcv_m = extract<int> l[2];
    	int rcv_n = extract<char> l[7];
    	NeighbourhoodType rcv_neighbourhood = 'MOORE';

    	switch (rcv_n)
    	{
    		case 'M':
    			rcv_neighbourhood = 'MOORE';
    			break;
    		case 'C':
    			rcv_neighbourhood = 'CIRC';
    			break;
    		case 'N':
    			rcv_neighbourhood = 'NEUM';
    			break;
    	}

    	Rules out = new Rules(rcv_neighbourhood, rcv_range, rcv_states, rcv_smin, rcv_smax, rcv_bmin, rcv_bmax, rcv_m);
    	return out;
    }
    void Game::receiveStartingPosition(){} //changes[0] = starting_pos
    void Game::receiveTask(){}

