#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 50050;

int prime[maxn], mu[maxn], sum[maxn];
bool check[maxn];
int cnt = 0, n, m, k, test;

int main() {
	mu[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!check[i]) {
			prime[++cnt] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= cnt; j++) {
			if (i * prime[j] >= maxn)
				break;
			check[i*prime[j]] = true;
			if (i % prime[j]) {
				mu[i*prime[j]] = -mu[i];
			} else {
				mu[i*prime[j]] = 0;
				break;
			}
		}
	}
	for (int i = 1; i < maxn; i++) {
		sum[i] = sum[i-1] + mu[i];
	}

	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		scanf("%d %d %d", &n, &m, &k);
		n /= k; m /= k;
		if (n > m) {
			swap(n, m);
		}
		int ans = 0;
		for (int i = 1, j = 0; i <= n; ) {
			j = min(n / (n / i), m / (m / i));
			ans += (sum[j] - sum[i-1]) * (n / i) * (m / i);
			i = j + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}