#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int mod = 100003;

long long fastMod(long long x, long long k) {
	long long res = 1;
	for ( ; k; k >>= 1) {
		if (k & 1)
			res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}

long long n, m;

int main() {
	cin >> m >> n;
	long long all = fastMod(m, n);
	long long sum = m * fastMod(m-1, n-1) % mod;
	long long ans = all - sum;
	while (ans < 0) {
		ans += mod;
	}
	cout << ans << endl;
	return 0;
}
