#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

int fibonacci_fast(const int& n) {
	if (n <= 1)
		return n;

	vector<int> fib_seq;
	fib_seq.push_back(1);
	fib_seq.push_back(1);
	for (auto i = 2; i < n; i++) {
		fib_seq.push_back(fib_seq[i - 1] + fib_seq[i - 2]);
	}

	return fib_seq.back();
}

int Pisano_length(const long long& m){
	if (m < 2) return 1;
	long long previous = 0;
	long long current = 1;
	long long next = previous + current;

	int i = 3;
	while (true){
		if ((current % m == 0) && (next % m == 1)) {
			return i;
		}
		previous = current;
		current = next;
		next = current + previous;
		i++;
	}

}

long long get_fibonacci_huge_fast(long long n, long long m) {
	long long periodlength = Pisano_length(m);
	int patternRemainder = n % periodlength;
	return fibonacci_fast(patternRemainder) % m;
}

int main() {
	long long n, m;
	std::cin >> n >> m;
//	std::cout << get_fibonacci_huge_naive(n, m) << endl;
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}
