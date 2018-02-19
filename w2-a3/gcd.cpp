#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int current_gcd = 1, tmp;
  int m_max = max(a, b);
  int m_min = min(a, b);

  while (m_max % m_min != 0){
	  tmp = m_max % m_min;
	  m_max = m_min;
	  m_min = tmp;
  }

  current_gcd = m_min;

  return current_gcd;
}

void test_solution() {
    assert(gcd_fast(3, 2) == 1);
    assert(gcd_fast(10, 5) == 5);
    assert(gcd_fast(100500,200600) == 100);
    cout << "Asserts: ok";
    int a, b, r1, r2, n = 1;

    while(true){
    	a = rand();
    	b= rand();

    	if ((r1 = gcd_fast(a, b)) == (r2 = gcd_naive(a, b))) {
    		std::cout << "Stress test #" << n << " ok" << std::endl;
    	} else {
    		cout << "Test #" << n << " failed: a = " << a << " b = " << b;
    		break;
    	}

		n++;
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;

//	test_solution();
	return 0;
}
