#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
	//write your code here
	const vector<int> denominations = { 10, 5, 1 };
	int n = 0;
	int current = 0;
	int den = denominations[current];
	while (m > 0 && current < denominations.size()) {
		while (m >= den) {
			m -= den;
			++n;
		}
		++current;
		den = denominations[current];
	}
	return n;
}

int main() {
	int m;
	cin >> m;
	std::cout << get_change(m) << '\n';
}
