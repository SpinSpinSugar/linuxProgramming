#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int fib_mod(int n, int mod) {
	int cur = 0, next = 1, tmp;
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
	int n, mod;
	
	int res = 0;
	res = scanf("%i %i", &n, &mod);
	assert(res == 2);
	
	printf("%i", fib_mod(n, mod));
	return 0;
}
