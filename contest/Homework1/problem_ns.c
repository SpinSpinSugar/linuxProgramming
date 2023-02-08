#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int ans[32];

unsigned long long power(unsigned long long x, int n) {
	unsigned long long ans = 1;
	while (n-- != 0) ans *= x;
	return ans;
}

int change_base(unsigned long long x,
							   unsigned long long base) {
	int i = 0;
	while (x != 0) {
		ans[i] = x % base;
		++i;
		x /= base;
	}
	return i;
}

int main() {
	unsigned long long x, base, len;	
	int res = 0;
	
	res = scanf("%llu %llu", &x, &base);
	assert(res == 2);

	len	= change_base(x, base);
	for (int i = len - 1; i != -1; --i) printf("%d", ans[i]);

	return 0;
}
