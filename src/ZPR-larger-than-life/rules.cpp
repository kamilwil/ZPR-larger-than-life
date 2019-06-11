#include "rules.hpp"

// Implementacja konstruktora struktury rules
Rules::Rules(NeighbourhoodType n, int r, int c, int sminimum, int smaximum, int bminimum, int bmaximum, int flag){
	neighbourhood = n;
	range = r;
	states = c;
	smin = sminimum;
	smax = smaximum;
	bmin = bminimum;
	bmax = bmaximum;
	m = flag;
}

Rules::Rules() = default;
Rules::~Rules() = default;