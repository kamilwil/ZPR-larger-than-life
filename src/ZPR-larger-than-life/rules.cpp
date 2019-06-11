#include "rules.hpp"
/// Structure with rules regarding the game
/// Fields:
/// NeighbourhoodType neighbourhood - neeghbourhood type
/// int range_ - range of neighbourhood
/// int states_ - number of states
/// int smin_ - minimal number of neighbours for cell to survive
/// int smax_ - maximal number of neighbours for cell to survive
/// int bmin_ - minimal number of neighbours for cell to be born
/// int bmax_ - maximal number of neighbours for cell to be born
/// int m_ - flaga of inclusion cell as its own neighbour


/// Constructor with arguments similar to fields of the structure
Rules::Rules(NeighbourhoodType n, int r, int c, int sminimum, int smaximum, int bminimum, int bmaximum, int flag){
	neighbourhood_ = n;
	range_ = r;
	states_ = c;
	smin_ = sminimum;
	smax_ = smaximum;
	bmin_ = bminimum;
	bmax_ = bmaximum;
	m_ = flag;
}

/// Rules default constructor
Rules::Rules() = default;
/// Rules default destructor
Rules::~Rules() = default;
