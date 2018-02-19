//============================================================================
// Name        : w1_a2.cpp
// Author      : aivanov
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((long long)numbers[i] * numbers[j] > result) {
        result = (long long)numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

void swap(int& a, int& b){
	  auto tmp = a;
	  a = b;
	  b = tmp;
}


long long MaxPairwiseProductFast(vector<int>& numbers) {
	int n = numbers.size();
	int max = 0, tmp;

	for (auto r=0; r < 2; r++){
		for (auto i = 0; i < n - r; i++){
			auto& item = numbers[i];
			if (item > numbers[max]) max = i;
		}
		tmp = numbers[n-r-1];
		numbers[n-r-1] = numbers[max];
		numbers[max] = tmp;
		max = 0;
	}

	return (long long)numbers[n - 1] * numbers[n - 2];
}

int main() {
//	vector<int> numbers;
//	long long result1, result2;
//	int n;
//	while(true){
//		n = rand() % 100 + 2;
//		numbers.resize(n);
//		for (auto& next : numbers){
//			next = rand();
//		}
//		result1 = MaxPairwiseProductFast(numbers);
//		result2 = MaxPairwiseProduct(numbers);
//		if (result1 != result2) {
//			cout << result1  << " != " << result2 << std::endl;
//			break;
//		} else {
//			cout << "test ok; n: " << n << std::endl;
//		}
//	}
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (auto& next : numbers)
		cin >> next;
	cout << MaxPairwiseProductFast(numbers) << std::endl;
    return 0;
}
