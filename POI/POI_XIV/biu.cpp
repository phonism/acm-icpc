#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

const int maxn = 100100;

vector<int> adj[maxn];
vector<int> ans;
list<int> lis;
bool vis[maxn], visit[maxn];
int n, m;

void bfs() {
	while (!lis.empty()) {
		queue<int> q;
		q.push(*lis.begin());
		visit[*lis.begin()] = true;
		lis.erase(lis.begin());
		int cnt = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < adj[u].size(); i++) {
				vis[adj[u][i]] = true;
			}
			for (list<int>::iterator it = lis.begin(); it != lis.end(); ) {
				if (vis[*it] == false && visit[*it] == false) {
					visit[*it] = true;
					q.push(*it);
					it = lis.erase(it);
					cnt++;
				} else {
					it++;
				}
			}
			for (int i = 0; i < adj[u].size(); i++) {
				vis[adj[u][i]] = false;
			}
		}
		ans.push_back(cnt);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		lis.push_back(i);
	}
	bfs();
	printf("%d\n", (int) ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0) {
			printf("%d", ans[i]);
		} else {
			printf(" %d", ans[i]);
		}
	}
	puts("");
	return 0;
}