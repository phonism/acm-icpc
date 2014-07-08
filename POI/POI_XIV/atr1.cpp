#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m, k, c, tot;
int depend[100], dist[30][30];
int d[100100];
int f[(1<<19)+1][22];
int pre[550500], son[550500], last[550500], len[550500];

struct Node {
	int x, d;

	Node() {}
	Node(int x, int d): x(x), d(d) {}

	bool operator<(const Node& o) const {
		return d > o.d;
	}
};

priority_queue<Node> q;

void addEdge(int u, int v, int w) {
	tot++;
	son[tot] = v;
	len[tot] = w;
	pre[tot] = last[u];
	last[u] = tot;
}

void spfa(int s) {
	memset(d, 127, sizeof(d));
	d[s] = 0; q.push(Node(s, 0));
	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		if (u.d != d[u.x])
			continue;
		for (int i = last[u.x]; i != 0; i = pre[i]) {
			if (d[son[i]] > d[u.x] + len[i]) {
				d[son[i]] = d[u.x] + len[i];
				q.push(Node(son[i], d[son[i]]));
			}
		}
	}
}

int dp(int gone, int now) {
	if (f[gone][now] != -1) {
		return f[gone][now];
	}
	if (gone == (1 << (k-1)) - 1) {
		return dist[now][k];
	}
	f[gone][now] = 0x3f3f3f3f;
	for (int i = 0; i < k - 1; i++) {
		if ((gone & (1 << i)) == 0 && (depend[i] & gone) == depend[i]) {
			f[gone][now] = min(f[gone][now], dp(gone|(1<<i), i+1) + dist[now][i+1]);
		}
	}
	return f[gone][now];
}
bool check[50];

void init() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	scanf("%d", &c);
	for (int i = 1; i <= c; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u -= 2; v -= 2;
		depend[v] |= 1 << u;
		check[v] = true;
	}

	int answer = 0x3f3f3f3f;

	for (int l = 1; l <= k; l++) {
		int tmp = 0;
		if (check[l-1] == false) {
			spfa(0);
			tmp += d[l];
			printf("%d\n", tmp);
			memset(f, -1, sizeof(f));
			for (int i = l - 1; i < k; i++) {
				depend[i] = depend[i+1];
			}
			for (int i = 0; i <= k; i++) {
				int s = i;
				if (i == 0) {
					s = l;
				} else if (i == l) {
					continue;
				} else if (i > l) {
					s --;
				}
				spfa(i);
				for (int j = 0; j <= k; j++) {
					int t = j;
					if (j == 0) {
						t = l;
					} else if (j == l) {
						continue;
					} else if (j > l) {
						t --;
					}
					dist[s][t] = d[j];
				}
				dist[s][k] = dist[k][s] = d[n-1];
			}
			// for (int i = 0; i<= k; i++) {
			// 	if (i == l)
			// 		continue;
			// 	if (i < l) {
			// 		spfa(i);
			// 		for (int j = 0; j <= k; j++) {
			// 			if (j == l) {
			// 				continue;
			// 			}
			// 			if (j > l) {
			// 				dist[i][j-1] = d[j];
			// 			} else {
			// 				dist[i][j] = d[j];
			// 			}
			// 		}
			// 		dist[i][k] = dist[k][i] = d[n-1];
			// 	} else {
			// 		spfa(i);
			// 		for (int j = 0; j <= k; j++) {
			// 			if (j == l) {
			// 				continue;
			// 			}
			// 			if (j > l) {
			// 				dist[i-1][j-1] = d[j];
			// 			} else {
			// 				dist[i-1][j] = d[j];
			// 			}
			// 		}
			// 		dist[i-1][k] = dist[k][i-1] = d[n-1];
			// 	}
			// }
			tmp += dp(0, 0);
			answer = min(tmp, answer);
		}
	}

	printf("%d\n", answer);
}

int main() {
	init();
	return 0;
}