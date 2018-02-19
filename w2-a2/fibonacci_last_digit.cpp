#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int first = 0;
    int second = 1;

    int res;

    for (int i = 2; i <= n; i++) {
        res = (first + second) % 10;
        first = second;
        second = res;
    }

    return res;
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2%10);
    assert(get_fibonacci_last_digit_fast(10) == 55%10);
    assert(get_fibonacci_last_digit_fast(239) == 1);
    for (int n = 0; n < 20; ++n)
    {
    	assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
    	std::cout << "Stress test #" << n + 1 << " ok" << std::endl;
    }
}

int main() {
	int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
	return 0;
//    test_solution();
//    return 0;
}
