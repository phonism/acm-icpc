#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a[20][20], f[66666];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(f, 0, sizeof(f));
		f[0] = 0;
		for (int i = 0; i < (1 << n); i++) {
			int one = __builtin_popcount(i) + 1;
			for (int j = 1; j <= n; j++) {
				if ((i >> (j - 1)) & 1) {
					continue;
				}
				f[i|1<<(j-1)] = max(f[i|1<<(j-1)], f[i] + a[j][one]);
			}
		}
		printf("Case %d: %d\n", cas, f[(1<<n)-1]);
	}
	return 0;
}