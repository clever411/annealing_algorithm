#include <cmath>
#include <random>
#include "Solution.hpp"

float const START_TEMPERATURE = 100;
float const FINISH_TEMPERATURE = 0.0001;
int const ITERATIONS = 100;
float const ALPHA = 0.99;


Solution annealing(Solution const &startsol) {
	Solution work(startsol), cur(startsol), best(startsol);
	for(float temp = START_TEMPERATURE; temp > FINISH_TEMPERATURE; temp *= ALPHA) {
		cur.tweak();
		if(cur.energy() <= work.energy()) {
			work = cur;
			if(cur.energy() < best.energy())
				best = cur;
		}
		else if(exp(-(work.energy()-cur.energy()/temp)) > rand()%RAND_MAX) {
			work = cur; 
		}
		else {
			cur = work; 
		}
	}
	return best;
}
