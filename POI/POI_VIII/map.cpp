#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 255;
int n, r;
int mp[maxn][maxn], sum[maxn][maxn], ans[maxn][maxn];

int main() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mp[i][j]);
			sum[i][j] = sum[i-1][j] + sum[i][j-1] 
				- sum[i-1][j-1] + mp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int A = max(i - r, 1);
			int B = min(i + r, n);
			int L = max(j - r, 1);
			int R = min(j + r, n);
			A--; L--;
			ans[i][j] = sum[B][R] - sum[A][R]
				- sum[B][L] + sum[A][L];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				printf("%d", ans[i][j]);
			} else {
				printf(" %d", ans[i][j]);
			}
		}
		puts("");
	}
}