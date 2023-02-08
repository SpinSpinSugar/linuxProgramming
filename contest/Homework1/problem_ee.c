#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long ext_euclid(long long x, long long y, long long* coef1, long long* coef2) {
	char sign1 = x > 0;
	char sign2 = y > 0;
	char flag;
	long long r = x % y, q = x / y,
			  a = 0, a_tmp = 1,
			  b = 1, b_tmp = 0;
	long long t;	
	while (r != 0) {
		x = y;
		y = r;
		t = a_tmp;
		a_tmp = a;
		a = t - q * a;
		t = b_tmp;
		b_tmp = b;
		b = t - q * b;
		r = x % y;
		q = x / y;
	}
	flag = y > 0;
	*coef1 = flag ? a : -a;
	*coef2 = flag ? b : -b;
	return abs(y); 
}
int main() {
	long long x = 0, y = 0, a, b, d;
	int res;
	res = scanf("%lld %lld", &x, &y);
	assert(res == 2);
	d = ext_euclid(x, y, &a, &b);
	printf("%lld %lld %lld", a, b, d);
	return 0;
}
