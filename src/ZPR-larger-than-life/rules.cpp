#include "rules.hpp"

Rules::Rules(int n, int r, int c, int sminimum, int smaximum, int bminimum, int bmaximum, int flag){
	neighbourhood = n;
	range = r;
	states = c;
	smin = sminimum;
	smax = smaximum;
	bmin = bminimum;
	bmax = bmaximum;
	m = flag;
}
