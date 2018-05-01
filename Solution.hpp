#include <iostream>

class Solution {
public:
	Solution(Solution const &sol);
	Solution& operator=(Solution const &sol);
	
	Solution(int n = 8);
	~Solution();

	void tweak();
	float energy() const;
	
	std::ostream& print(std::ostream &os) const;
private:
	void _update();

	int _n;
	int *_code;
	float _energy;
};
