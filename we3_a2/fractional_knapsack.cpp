#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

struct FractionalValue{
public:
	double fractional_value = 0.0;
	int index;
};

double get_optimal_value(int capacity, vector<int> weights,
		vector<int> values) {
	double value = 0.0;

	// write your code here
	int size = values.size();
	std::vector<FractionalValue> index_by_normilized_value;
	for (auto i = 0; i < size; i++) {
		index_by_normilized_value.push_back(
				(FractionalValue ) { (double) values[i] / weights[i], i });
	}

	std::sort(begin(index_by_normilized_value), end(index_by_normilized_value), [](FractionalValue a, FractionalValue b){
		return a.fractional_value > b.fractional_value;
	});

	int current_capacity = capacity;
	int current_weight = 0, delta_weight = 0;
	for (auto& item : index_by_normilized_value) {
		current_weight = weights[item.index];

		delta_weight =std::min(current_weight, current_capacity);

		value += delta_weight * item.fractional_value;
		current_capacity -= delta_weight;

		//		std::cout << "fractional_value = " << item.fractional_value << std::endl;
		//		std::cout << "delta_weight = " << delta_weight << std::endl;

		if (current_capacity == 0) break;
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
