#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long seq_len(long long mod) {
	long long cur = 0, next = 1, tmp, r1 = 0, r2 = 1, counter = 0;
	do {
		++counter;
		cur = cur % mod;
		next = next % mod;
		tmp = next;
		next += cur;
		cur = tmp;
		r1 = cur % mod;
		r2 = next % mod;
	}	while (r1 != 0 || r2 != 1);
	return counter;
}

long long fib_mod(long long n, long long mod, long long len) {
	long long cur = 0, next = 1, tmp;
	n %= len;
	
	while (n-- != 0) {
		
		cur = cur % mod;
		next = next % mod;
		tmp = next;
		next += cur;
		cur = tmp;
	}
	return cur % mod;
}

int main() {
	long long n, mod;
	long long len = 0, r = 0;

	long long res = 0;
	res = scanf("%lld %lld", &n, &mod);
	assert(res == 2);
	len = seq_len(mod);
	r = fib_mod(n, mod, len);
	printf("%lld %lld", r, len);
	return 0;
}
