#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(const long& a, const long& b) {
	if (a == 0 || b == 0) return 0;
	long gcd = gcd_fast(a, b);
	long long div_a = a / gcd;
	return div_a * b;
}

void test_solution() {
    assert(lcm_fast(1, 2) == 2);
    assert(lcm_fast(6, 8) == 24);
    assert(lcm_fast(28851538, 1183019) == 1933053046);

    cout << "Assertions: ok" << endl;

    int a, b, r1, r2, n = 1;
    while(true){
    	a = rand();
    	b= rand();

    	if ((r1 = lcm_fast(a, b)) == (r2 = lcm_naive(a, b))) {
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
  std::cout << lcm_fast(a, b) << std::endl;

//  test_solution();
  return 0;
}
