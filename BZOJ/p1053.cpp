#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n, ans, opt;

void dfs(int base, int dv, long long num) {
	if (dv > opt) {
		opt = dv;
		ans = 0x7FFFFFFF;
	}
	if (dv == opt && num < ans) {
		ans = num;
	}
	if (base >= 10)
		return ;
	for (int i = 0; num <= n; num *= prime[base], i++) {
		dfs(base + 1, dv * (i + 1), num);
	}
}

int main() {
	scanf("%d", &n);
	dfs(0, 1, 1);
	printf("%d\n", ans);
	return 0;
}
