#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1111;
const int maxm = 10 * maxn;
const int inf = 0x3f3f3f3f;
const int fu = -12312312;

struct Node {
	int to, next;
	int cap, cost;
	void init(int to, int next, int cap, int cost) {
		this->to = to; this->next = next;
		this->cap = cap; this->cost = cost;
	}
};

struct MinCost {
	int E[maxn], p[maxn], n, len;
	Node buf[maxm];

	void init(int n) {
		this->n = n;
		memset(E, 255, sizeof(E));
		len = 0;
	}

	void addCap(int u, int v, int cap, int cost) {
		buf[len].init(v, E[u], cap, cost); E[u] = len++;
		buf[len].init(u, E[v], 0, -cost); E[v] = len++;
	}

	bool spfa(int source, int sink) {
		static queue<int> q;
		static int d[maxn];
		memset(d, 63, sizeof(d));
		memset(p, 255, sizeof(p));
		d[source] = 0;
		q.push(source);
		int u, v;
		while (!q.empty()) {
			u = q.front();
			q.pop();
			for (int i = E[u]; i != -1; i = buf[i].next) {
				v = buf[i].to;
				if (buf[i].cap > 0 && d[u] + buf[i].cost < d[v]) {
					d[v] = d[u] + buf[i].cost;
					p[v] = i; q.push(v);
				}
			}
		}
		return d[sink] != inf;
	}

	int solve(int source, int sink) {
		int mincost = 0, maxflow = 0;
		while (spfa(source, sink)) {
			int neck = inf;
			for (int t = p[sink]; t != -1; t = p[buf[t^1].to])
				neck = min(neck, buf[t].cap);
			maxflow += neck;
			for (int t = p[sink]; t != -1; t = p[buf[t^1].to]) {
				buf[t].cap -= neck;
				buf[t^1].cap += neck;
				mincost += buf[t].cost * neck;
			}
		}
		return mincost;
	}
}g;

int n, m, S;
int need[maxn], cost[maxn];

int main() {
	scanf("%d %d %d", &n, &m, &S);
	int s = 0, t = n + 1;
	g.init(t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &need[i]);
		g.addCap(i, t, need[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		g.addCap(s, i, inf, cost[i]);
	}
	for (int i = 1; i < n; i++) {
		g.addCap(i, i + 1, S, m);
	}
	printf("%d\n", g.solve(s, t));
}
