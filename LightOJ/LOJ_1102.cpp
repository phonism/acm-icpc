/*
	easy to find the answer is C(n+m-1, m-1)
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 2000100;
const int mod = 1000000007;

int fac[maxn], inv[maxn];

int fastMod(int n, int k) {
	int ret = 1;
	for ( ; k; k >>= 1) {
		if (k & 1)
			ret = (long long) ret * n % mod;
		n = (long long) n * n % mod;
	}
	return ret;
}

void init() {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = (long long) fac[i-1] * i % mod;
		inv[i] = fastMod(fac[i], mod - 2);
	}
}

int getC(int n, int m) {
	return (long long) fac[n] * inv[m] % mod * inv[n-m] % mod;
}

int main() {
	init();
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n, m; scanf("%d %d", &n, &m);
		printf("Case %d: %d\n", cas, getC(n + m - 1, m - 1));
	}
	return 0;
}
