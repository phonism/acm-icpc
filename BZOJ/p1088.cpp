#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int n, S[maxn], F[maxn], ans;

bool check(int p) {
	return F[p-1] + F[p] + F[p+1] == S[p];
}

void dfs(int p) {
	if (p == n + 1) {
		if (check(p - 1))
			ans++;
		return ;
	}
	F[p] = 0;
	if (p == 1 || check(p-1))
		dfs(p + 1);
	F[p] = 1;
	if (p == 1 || check(p-1))
		dfs(p + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &S[i]);
	}
	dfs(1);
	printf("%d\n", ans);
}
