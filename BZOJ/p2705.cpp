#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


long long phi(long long x) {
	long long ans = 1;
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				cnt++;
				x /= i;
			}
			ans *= i - 1;
			for (int j = 2; j <= cnt; j++) {
				ans *= i;
			}
		}
	}
	if (x > 1) {
		ans *= x - 1;
	}
	return ans;
}

int main() {
	long long n, ans = 0;
	// printf("%lld %lld\n", phi(2), phi(3));
	scanf("%lld", &n);
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans += i * phi(n / i);
			if (i * i < n) {
				ans += n / i * phi(i);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}