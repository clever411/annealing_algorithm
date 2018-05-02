#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Solution.hpp"

using namespace std;

extern Solution annealing(Solution const &);

int main(int argc, char **argv) {
	srand(time(0));

	int n = 10;
	if(argc > 1) {
		n = atoi(argv[1]);
	}
	
	Solution sol(n);
	cout << "at start: " << endl;
	sol.print(cout);
	cout << endl;
	sol = annealing(sol);
	cout << "at end: " << endl;
	sol.print(cout);
	cout << endl;
	return 0;
}
