#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100100;

double val[maxn];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &val[i]);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		val[u] += 1.0 * w / 2;
		val[v] += 1.0 * w / 2;
	}
	sort(val + 1, val + n + 1);
	double sum1 = 0, sum2 = 0;
	for (int i = n; i >= 1; i--) {
		if (i % 2 == 0)
			sum1 += val[i];
		else
			sum2 += val[i];
	}
	printf("%lld\n", (long long) (sum1 - sum2));
	return 0;
}
