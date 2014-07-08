#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 400100;

int x[maxn], y[maxn], next[maxn], match[maxn], pattern[maxn];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		x[n+1] = x[1]; y[n+1] = y[1];
		x[n+2] = x[2]; y[n+2] = y[2];
		int tot = 0, answer = 0;
		for (int i = 1; i <= n; i++) {
			match[++tot] = (x[i+1] - x[i]) * (x[i+1] - x[i]) 
				+ (y[i+1] - y[i]) * (y[i+1] - y[i]);
			match[++tot] = (x[i+1] - x[i]) * (y[i+2] - y[i]) 
				- (y[i+1] - y[i]) * (x[i+2] - x[i]);
		}

		for (int i = 1; i <= tot; i++) {
			pattern[tot-i+1] = match[i+tot] = match[i];
		}
		memset(next, 0, sizeof(next));
		for (int i = 2, j = 0; i <= tot; i++) {
			while (j && pattern[j+1] != pattern[i]) {
				j = next[j];
			}
			j += (pattern[j+1] == pattern[i]);
			next[i] = j;
		}
		for (int i = 1, j = 0; i <= tot * 2; i++) {
			while (j && pattern[j+1] != match[i]) {
				j = next[j];
			}
			j += (pattern[j+1] == match[i]);
			if (j == tot) {
				answer++;
				j = next[j];
			}
		}
		printf("%d\n", answer);
	}
}