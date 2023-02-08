#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int m[4], ans[4], tmp[4];

void power_matrix_mod(int* mtrx, int n, int mod, int* ans) {
	while (n != 1) {			
		tmp[0] = (ans[0] * mtrx[0] + ans[1] * mtrx[2]) % mod;
		tmp[1] = (ans[0] * mtrx[1] + ans[1] * mtrx[3]) % mod;	
		tmp[2] = (ans[2] * mtrx[0] + ans[3] * mtrx[2]) % mod;
		tmp[3] = (ans[2] * mtrx[1] + ans[3] * mtrx[3]) % mod;
		--n;
		for (int i = 0; i < 4; ++i) ans[i] = tmp[i];
	}
}

int main() {
	int n, mod;

	int res = 0;
	res = scanf("%d %d %d %d %d %d", &m[0], &m[1], &m[2], &m[3], &n, &mod);
	assert(res == 6);
	for (int i = 0; i < 4; ++i) ans[i] = m[i];


	power_matrix_mod(m, n, mod, ans);

	printf("%d %d %d %d", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}
