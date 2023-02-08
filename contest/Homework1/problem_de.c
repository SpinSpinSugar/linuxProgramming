#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int ext_euclid(int x, int y, int* coef1, int* coef2) {
	char flag;
	int r = x % y, q = x / y,
		a = 0, a_tmp = 1,
		b = 1, b_tmp = 0;
	int t;	
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
	int a = 0, b = 0, c = 0, x, y, d;
	int res = 0;
	res = scanf("%i %i %i", &a, &b, &c);
	assert(res == 3);
	d = ext_euclid(a, b, &x, &y);
	if (c % d != 0) {
		printf("NONE");
		return 0;
	}
	printf("%i %i", c / d * x, c / d * y);
	return 0;
}
