#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long fib[50];
int ans[50] = {};

void fill_fib_array(long long* arr, int n) {
	long long cur = 0, next = 1, tmp;
	int i = 0;
	assert(n <= 50 && n >= 0);
	while (n-- != 0) {
		arr[i] = cur;
		tmp = next;
		next += cur;
		cur = tmp;
		++i;
	}
}

int get_fib_representation(int x, long long* mem_fib, int* ans)  {
	int n = 50;
	int max_n = 50;	
	int flag = 1;
	assert (x >= 0);
	while (x >= 0) {
		for (int i = 0; i < n - 1; ++i) {
			if (x < mem_fib[i+1] && x >= mem_fib[i]) {
				if (flag) {
					max_n = i;
					flag = 0;
				}
				n = i;
				break;
			}
		}
		//printf("%d ", mem_fib[n]);		
		if (mem_fib[n] == 0) break;
		x -= mem_fib[n];
		ans[n] = 1;
	}
	return max_n;
}


int main() {
	int x, max_n;
	
	int res = 0;
	res = scanf("%d", &x);
	assert(res == 1);
	
	fill_fib_array(fib, 50);
#if DEBUG
	for(int i = 1; i < 10; ++i) printf("%lld ", fib[i]);
	printf("\n");
#endif
	max_n = get_fib_representation(x, fib, ans);
	for (int i = max_n; i != 1; --i) printf("%d", ans[i]);
	 
	return 0;
}
