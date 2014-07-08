/*
	Dp
	f[i][j] = min{f[i][j], f[i-ti][j-ai] + wi}
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int f[50][100];

int main() {
	int t, a, n;
	scanf("%d %d %d", &t, &a, &n);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 100; j++) {
			f[i][j] = 1 << 30;
		}
	}
	f[0][0] = 0;
	for (int cas = 0; cas < n; cas++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		for (int i = t; i >= 0; i--) {
			for (int j = a; j >= 0; j--) {
				int k = min(i + u, t);
				int l = min(j + v, a);
				f[k][l] = min(f[i][j] + w, f[k][l]);
			}
		}
	}
	printf("%d\n", f[t][a]);
}