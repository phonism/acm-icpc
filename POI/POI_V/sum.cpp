#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	if (abs(k) > n * (n - 1) / 2 || abs(k) % 2 != (n / 2) % 2) {
		puts("NIE");
	} else {
		long long m = ((n * (n - 1) / 2) - k) / 2;
		int i = 0, j = 0;
		for (i = 1; i <= n; i++) {
			if ((long long)i * (i + 1) / 2 >= m)
				break;
		}
		m = m - (long long)i * (i - 1) / 2;
		// printf("%d\n", m);
		// printf("FUCK%d\n", i);
		for (j = 0; j <= n - i - 1; j++) {
			printf("%d\n", j);
		}
		// puts("FUCK");
		for (j = n - i - 2; j >= n - i - m - 1; j--) {
			printf("%d\n", j);
		}
		// puts("FUCK");
		for (j = n - i - m; j >= n - 2 * i + 1; j--) {
			printf("%d\n", j);
		}
	}
	return 0;
}