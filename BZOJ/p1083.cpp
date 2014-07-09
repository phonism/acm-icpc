#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 333;
const int maxm = 100100;

struct Road {
	int u, v, w;

	Road() {}
	Road(int u, int v, int w):
		u(u), v(v), w(w) {}

	bool operator<(const Road &o) const {
		return w < o.w;
	}
};

Road road[maxm];
int n, m, par[maxn];

int find(int x) {
	if (par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

void gao() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		road[i] = Road(u, v, w);
	}
	sort(road, road + m);
	
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	int ans = 0, tmp = 0;
	for (int i = 0; i < m; i++) {
		int fu = find(road[i].u);
	    int	fv = find(road[i].v);
		int w = road[i].w;
		if (fu != fv) {
			ans += w;
			tmp = max(w, tmp);
			par[fu] = fv;
		}
	}
	printf("%d %d\n", n - 1, tmp);
}

int main() {
	gao();
}
