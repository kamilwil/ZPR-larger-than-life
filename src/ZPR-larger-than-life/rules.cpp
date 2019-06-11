#include "rules.hpp"
//* Struktura rules przechowujaca odpowidnie wartosci zasad obecnych w danej grze
//* Pola klasy:
//* NeighbourhoodType neighbourhood - typ sasiedztwa
//* int range - zasieg sasiedztwa
//* int states - ilosc stanow
//* int smin - minimalna ilosc sasiadow do przezycia komorki
//* int smax - maksymalna ilosc sasiadow do przezycia komorki
//* int bmin - minimalna ilosc sasiadow do powstania komorki
//* int bmax - maksymalna ilosc sasiadow do powstania komorki


//* Implementacja konstruktora struktury rules o argumentach analogicznych do pol klasy
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

//* Domyslny konstruktor klasy Rules
Rules::Rules() = default;
//* Domyslny destruktor klasy Rules
Rules::~Rules() = default;
