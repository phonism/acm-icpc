#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111;
const int inf = ~0U>>2;

int n, m, k;
int mat1[N], mat2[N][N], sum[N];
int dp1[N][N], dp2[N][N][11];

void solve1() {
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mat1[i]);
		mat1[i] += mat1[i-1];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			int &x = dp1[i][j]; x = -inf;
			if (j) {
				x = dp1[i][j-1];
			}
			for (int l = 0; l < j; l++) {
				x = max(x, dp1[i-1][l] + mat1[j] - mat1[l]);
			}
		}
	}
	printf("%d\n", dp1[k][n]);
}

void solve2() {
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < 2; i++) {
			scanf("%d", &mat2[i][j]);
			sum[j] += mat2[i][j];
			mat2[i][j] += mat2[i][j-1];
		}
	}
	for (int i = 1; i <= n; i++)
		sum[i] += sum[i-1];
	for (int i = 1; i <= k; i++) {
		for (int l = 0; l <= n; l++) {
			for (int r = 0; r <= n; r++) {
				int &x = dp2[l][r][i]; x = -inf;
				if (l) {
					x = max(x, dp2[l-1][r][i]);
					for (int o = 0; o < l; o++) {
						x = max(x, dp2[o][r][i-1] + mat2[0][l] 
								- mat2[0][o]);
					}
				}
				if (r) {
					x = max(x, dp2[l][r-1][i]);
					for (int o = 0; o < r; o++) {
						x = max(x, dp2[l][o][i-1] + mat2[1][r] 
								- mat2[1][o]);
					}
				}
				if (l == r) {
					for (int o = 0; o < l; o++)
						x = max(x, dp2[o][o][i-1] + sum[l] - sum[o]);
				}
			}
		}
	}
	printf("%d\n", dp2[n][n][k]);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (m == 1) {
		solve1();
	} else {
		solve2();
	}
	return 0;
}
