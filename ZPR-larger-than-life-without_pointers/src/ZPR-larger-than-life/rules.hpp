

#ifndef RULES_HPP
#define RULES_HPP


enum class NeighbourhoodType {MOORE, NEUM, CIRC };

struct Rules {
    
    NeighbourhoodType neighbourhood;
    int range;
    int states;
    int smin;
    int smax;
    int bmin;
    int bmax;
    int m;

};


#endif