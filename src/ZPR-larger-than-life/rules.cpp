#include "rules.hpp"
//* Structure with rules regarding the game
//* Fields:
//* NeighbourhoodType neighbourhood - neeghbourhood type
//* int range - range of neighbourhood
//* int states - number of states
//* int smin - minimal number of neighbours for cell to survive
//* int smax - maximal number of neighbours for cell to survive
//* int bmin - minimal number of neighbours for cell to be born
//* int bmax - maximal number of neighbours for cell to be born
//* int m - flaga of inclusion cell as its own neighbour


//* Constructor with arguments similar to fields of the structure
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

//* Rules default constructor
Rules::Rules() = default;
//* Rules default destructor
Rules::~Rules() = default;
