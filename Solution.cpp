#include <algorithm>
#include <cmath>
#include "Solution.hpp"
#include <string>
#include <random>

using namespace std;

Solution::Solution(Solution const &sol):
	 _n(sol._n), _code(new int[sol._n]), _energy(sol._energy) {
	copy(sol._code, sol._code+sol._n, _code);
}

Solution& Solution::operator=(Solution const &sol) {
	if(_n == sol._n) {
		copy(sol._code, sol._code+sol._n, _code);
	}
	else {
		delete[] _code;
		_n = sol._n;
		_code = new int[sol._n];
		copy(sol._code, sol._code+sol._n, _code);
	}
	_energy = sol._energy;
	return *this;
}

Solution::Solution(int n): _n(n), _code(new int[n]), _energy(0) {
	for(int i = 0; i < n; ++i) 
		_code[i] = i;
	_update();
	return;
}
Solution::~Solution() {
	delete [] _code;
}

void Solution::tweak() {
	int a, b;
	do {
		a = rand()%_n;
		b = rand()%_n;
	}
	while(a == b);
	
	swap(_code[a], _code[b]);
	_update();
	
	return;
}
float Solution::energy() const {
	return _energy;
}

std::ostream& Solution::print(std::ostream &os) const {
	for(int i = 0; i < _n; ++i) {
		for(int j = 0; j < _code[i]; ++j)
			os << ' ';
		os << 'Q' << '\n';
	}
	os << "energy: " << _energy << '\n';
	os << "--------------------------";
	os << "\n\n" << flush;
	return os;
}

void Solution::_update() {
	_energy = 0;
	for(int x = 0; x < _n; ++x) {
		for(int i = x+1; i < _n; ++i) {
			if(abs(x-i) == abs(_code[x]-_code[i])) {
				_energy += 1;
			}
		}
	}
	return;
}

