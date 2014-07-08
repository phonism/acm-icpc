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
int f[(1<<19)+1][21];
int pre[450500], son[450500], last[450500], len[450500];

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
	if (gone == (1 << k) - 1) {
		return dist[now][k+1];
	}
	f[gone][now] = 0x3f3f3f3f;
	for (int i = 0; i < k; i++) {
		if ((gone & (1 << i)) == 0 && (depend[i] & gone) == depend[i]) {
			f[gone][now] = min(f[gone][now], dp(gone|(1<<i), i+1) + dist[now][i+1]);
		}
	}
	return f[gone][now];
}

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
	}

	for (int i = 0; i<= k; i++) {
		spfa(i);
		for (int j = 0; j <= k; j++) {
			dist[i][j] = d[j];
		}
		dist[i][k+1] = dist[k+1][i] = d[n-1];
	}

	memset(f, -1, sizeof(f));
}

int main() {
	init();
	printf("%d\n", dp(0, 0));
	return 0;
}