#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1111;
const int mod = 31011;

struct Node {
	int u, v, w;

	bool operator<(const Node &o) const {
		return w < o.w;
	}
};

Node node[maxn];

int n, m, par[maxn];

int find(int x) {
	if (par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		node[i].u = u;
		node[i].v = v;
		node[i].w = w;
	}
	sort(node, node + m);
	int ans = 1;
	for (int i = 0; i < m; i++) {
		int u = node[i].u;
		int v = node[i].v;
		int w = node[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu != fv) {
			int tmp = 1;
			for (int j = i + 1; j < m; j++) {
				if (node[j].w == w)
					tmp++;
			}
			ans *= tmp;
			ans %= mod;
			par[fu] = fv;
		}
	}
	printf("%d\n", ans);
}
