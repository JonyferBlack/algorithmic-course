//============================================================================
// Name        : w2_a1.cpp
// Author      : aivanov
//============================================================================

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(const int& n) {
    if (n <= 1)
        return n;

	vector<int> fib_seq;
	fib_seq.push_back(1);
    fib_seq.push_back(1);
    for (auto i = 2; i < n; i++){
    	fib_seq.push_back(fib_seq[i-1] + fib_seq[i-2]);
    }

    return fib_seq.back();
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
    {
    	assert(fibonacci_fast(n) == fibonacci_naive(n));
    	std::cout << "Stress test #" << n + 1 << " ok" << std::endl;
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';

//    test_solution();
//    std::cout << fibonacci_fast(n) << '\n';

    return 0;
}
