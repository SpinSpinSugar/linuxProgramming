//-----------------------------------------------------------------------------
//
// Knuth Volume 1
// Licensed after GNU GPL v3
//
//-----------------------------------------------------------------------------
//
//  Generalized Euclid algorithm
//	Given m, n, find GCD and coefficients such a * m + b * n = GCD(m, n)
//
//
//----------------------------------------------------------------------------

#include <iostream>
#include <array>

std::array<int, 3> GenEuclid(int m, int n) {
	static int a = 0, a_tmp = 1, b = 1, b_tmp = 0, c = m, d = n;
	int q = c / d, r = c % d;
 	if (r == 0) return {a, b, a*c + b*d};
	c = d;
	d = r;
	int tmp = a_tmp;
	a_tmp = a;
	a = tmp - q * a;
	tmp = b_tmp;
	b_tmp = b;
	b = tmp - q * b;
	GenEuclid(c, d);
}

int main() {
	int m, n;
	std::cin >> m >> n;
	auto cf = GenEuclid(m, n);
	std::cout << cf[0] << "m + " << cf[1] << "n = " << cf[2];
}

