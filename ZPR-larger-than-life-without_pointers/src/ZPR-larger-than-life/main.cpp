#include "cell.hpp"
#include "state.hpp"
#include "change.hpp"
#include "game.hpp"





int main (void)

{
    Cell *test1=new Cell();
    Game *test2=new Game();
    State *test3=new State();
    Change *test4=new Change();
    delete test1;
    delete test2;
    delete test3;
    delete test4;
}