#ifndef RULES_HPP
#define RULES_HPP


enum class NeighbourhoodType {MOORE, NEUM, CIRC };

struct Rules {
    
    NeighbourhoodType neighbourhood_;
    int range_;
    int states_;
    int smin_;
    int smax_;
    int bmin_;
    int bmax_;
    int m_;

	Rules(NeighbourhoodType, int, int, int, int, int, int, int);
	Rules();
	~Rules();
};

#endif