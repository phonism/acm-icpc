#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 400400;
int n, m, q, par[maxn];
vector<int> adj[maxn], query, ans;
bool vis[maxn];

int find(int x) {
	if (par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

void init() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x++; y++;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x; scanf("%d", &x);
		x++;
		vis[x] = true;
		query.push_back(x);
	}
}

void work() {
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == true)
			continue;
		for (int j = 0; j < adj[i].size(); j++) {
			int x = adj[i][j];
			if (vis[x] == true)
				continue;
			int fx = find(i);
			int fy = find(x);
			if (fx != fy) {
				par[fx] = fy;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false && par[i] == i)
			cnt++;
	}
	for (int i = query.size() - 1; i >= 0; i--) {
		ans.push_back(cnt);
		int x = query[i];
		vis[x] = false;
		cnt++;
		for (int j = 0; j < adj[x].size(); j++) {
			int y = adj[x][j];
			if (vis[y] == true)
				continue;
			int fx = find(x);
			int fy = find(y);
			if (fx != fy) {
				par[fx] = fy;
				cnt--;
			}
		}
	}
	ans.push_back(cnt);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[ans.size() - 1 - i]);
	}
}


int main() {
	init();
	work();
	return 0;
}
