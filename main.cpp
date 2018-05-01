#include <ctime>
#include <iostream>
#include "Solution.hpp"

using namespace std;

extern Solution annealing(Solution const &);

int main() {
	srand(time(0));
	Solution sol(10);
	sol = annealing(sol);
	sol.print(cout);
	return 0;
}
