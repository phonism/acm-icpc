#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 1001000;

struct BIT {

	int n, tree[maxn];

	void init(int _) {
		n = _;
		memset(tree, 0, sizeof(tree));
	}

	void init(int _, int val[maxn]) {
		n = _;
		for (int i = 0; i < maxn; i++) {
			tree[i] = val[i];
		}
	}

	int lowbit(int x) {
		return x & -x;
	}

	void update(int idx, int val) {
		for ( ; idx <= n; idx += lowbit(idx)) {
			tree[idx] += val;
		}
	}

	int query(int idx) {
		int res = 0;
		for ( ; idx; idx -= lowbit(idx)) {
			res += tree[idx];
		}
		return res;
	}

};

BIT bit;
int n, c, m;
int a[maxn], pre[maxn];
int p[maxn], ans[maxn];
vector<pair<int, int> > adj[maxn];

int main() {
	scanf("%d %d %d", &n, &c, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (pre[a[i]]) {
			p[i] = pre[a[i]];
		}
		pre[a[i]] = i;
	}
	bit.init(n);
	for (int q = 1; q <= m; q++) {
		int l, r;
		scanf("%d %d", &l, &r);
		adj[r].push_back(make_pair(l, q));
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", p[i]);
	// }
	// puts("");
	for (int i = 1; i <= n; i++) {
		bit.update(p[i] + 1, -1);
		bit.update(p[p[i]] + 1, 1);
		if (adj[i].size() > 0) {
			for (int j = 0; j < adj[i].size(); j++) {
				int u = adj[i][j].first;
				ans[adj[i][j].second] = bit.query(u);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}