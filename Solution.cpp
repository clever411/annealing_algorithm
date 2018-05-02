#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
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
	if(n < 2)
		throw invalid_argument("invalid n");
	for(int i = 0; i < _n; ++i) {
		_code[i] = rand()%_n;
	}
	_update();
	return;
}
Solution::~Solution() {
	delete [] _code;
}

void Solution::tweak() {
	int a = rand()%_n, b = rand()%_n;
	swap(_code[a], _code[b]);

	_update();
	
	return;
}
float Solution::energy() const {
	return _energy;
}

std::ostream& Solution::print(std::ostream &os) const {
	for(int i = 0; i < _n; ++i) {
		os << _code[i] << " ";
	}
	os << endl << "energy: " << _energy << endl;
	return os;
}

void Solution::_update() {
	_energy = 0;
	for(int i = 0; i < _n-1; ++i) {
		if(_code[i] > _code[i+1])
			_energy += _code[i]-_code[i+1];	
	}
	return;
}

