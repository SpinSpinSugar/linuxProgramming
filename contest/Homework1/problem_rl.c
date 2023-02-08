#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {
  unsigned long long q;
  if (y > x)
    return gcd(y, x);
  assert (y > 0);
  q = x % y;
  if (q == 0)
    return y;
  return gcd(y, q);
}

long long loop_gcd(long long x,
				   long long y) {
    long long q;
	if (x < 0) return loop_gcd(-x, y);
	if (y < 0) return loop_gcd(x, -y);
	if (y > x) return loop_gcd(y, x);
	//assert (y > 0);
	q = x % y;
	while (q != 0) {
		x = y;
		y = q;
		q = x % y;
	}
	return y;
}

int main() {
  long long x = 0, y = 0, g;
  int res;
  
  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  //g = gcd(x, y);
  //printf("%lld\n", g);
  g = loop_gcd(x, y);
  printf("%lld\n", g);
  return 0;
}
