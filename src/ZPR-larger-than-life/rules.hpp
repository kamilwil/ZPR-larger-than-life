
#ifndef RULES_HPP
#define RULES_HPP

// Klasa enumeryczna odpowiadajace typowi sasiedztwa
enum class NeighbourhoodType {MOORE, NEUM, CIRC };

// Struktura przechowujaca pola z wartoscia poszczegolnych zasad dla danej gry
struct Rules {
    
    NeighbourhoodType neighbourhood;
    int range;
    int states;
    int smin;
    int smax;
    int bmin;
    int bmax;
    int m;

    Rules(NeighbourhoodType, int, int, int, int, int, int, int);
};




#endif