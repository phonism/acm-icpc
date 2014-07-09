#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 9;
const int maxk = 9 * 9 + 9;

long long dp[2][maxk][1<<maxn] = {0};
int cnt = 0, n, k, c[1<<maxn], state[1<<maxn];

void dfs(int p, int s) {
	if (p == n) {
		state[cnt++] = s;
		return ;
	}
	dfs(p + 1, s * 2);
	if (!(s&1))
		dfs(p + 1, s * 2 + 1);
}

bool legal(int a, int b) {
	a = state[a]; b = state[b];
	return !(a&b) && !((a<<1)&b) && !((a>>1)&b);
}

int count(int a) {
	a = state[a];
	return c[a];
}

int main() {
	scanf("%d %d", &n, &k);
	int now = 0, old = 1;
	dp[now][0][0] = 1;
	dfs(0, 0);
	c[0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		c[i] = c[i/2] + (i & 1);
	}

	for (int i = 0; i < n; i++) {
		swap(now, old);
		memset(dp[now], 0, sizeof(dp[now]));
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l < cnt; l++) {
				for (int r = 0; r < cnt; r++) {
					if (j - count(r) >= 0 && legal(r, l)) {
						dp[now][j][r] += dp[old][k-count(r)][l];
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < cnt; i++)
		ans += dp[now][k][i];
	printf("%lld\n", ans);
	return 0;
}
