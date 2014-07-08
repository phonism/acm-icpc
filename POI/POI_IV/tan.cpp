#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn];
int d, H;
int f[maxn], g[maxn], h[maxn];

int main() {
	scanf("%d %d", &d, &H);
	for (int i = 1; i <= H; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	a[H+1] = d; b[H+1] = 0;
	for (int i = 1; i <= H + 1; i++) {
		f[i] = g[i] = INF;
		h[i] = 0;
	}

	for (int i = 1; i <= H + 1; i++) {
		for (int j = i - 1; j >= 0 && a[i] - a[j] <= 800; j--) {
			if (f[j] + b[i] < f[i]) {
				f[i] = f[j] + b[i];
				g[i] = g[j] + 1;
				h[i] = j;
			} else if (f[j] + b[i] == f[i] && g[j] + 1 < g[i]) {
				g[i] = g[j] + 1;
				h[i] = j;
			}
		}
	}
	vector<int> ans;
	for (int i = H + 1; h[i]; i = h[i]) {
		ans.push_back(h[i]);
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (i == ans.size() - 1) {
			printf("%d", a[ans[i]]);
		} else {
			printf(" %d", a[ans[i]]);
		}
	}
	puts("");

	f[0] = g[0] = 0;
	for (int i = 1; i <= H + 1; i++) {
		f[i] = g[i] = INF;
		h[i] = 0;
	}
	for (int i = 1; i <= H + 1; i++) {
		for (int j = i - 1; j >= 0 && a[i] - a[j] <= 800; j--) {
			if (g[j] + 1 < g[i]) {
				f[i] = f[j] + b[i];
				g[i] = g[j] + 1;
				h[i] = j;
			} else if (g[j] + 1 == g[i] && f[j] + b[i] < f[i]) {
				f[i] = f[j] + b[i];
				h[i] = j;
			}
		}
	}
	ans.clear();
	for (int i = H + 1; h[i]; i = h[i]) {
		ans.push_back(h[i]);
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (i == ans.size() - 1) {
			printf("%d", a[ans[i]]);
		} else {
			printf(" %d", a[ans[i]]);
		}
	}
	puts("");
	return 0;
}