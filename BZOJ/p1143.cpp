#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
const int maxn = 10012;
  
struct Graph {
      
    bool vis[maxn];
    int n, match[maxn];
    vector<int> E[maxn];
      
    void init(int n) {
        this->n = n;
        for (int i = 0; i < maxn; i++)
            E[i].clear();
        memset(vis, false, sizeof(vis));
        memset(match, 255, sizeof(match));
    }
  
    void addEdge(int u, int v) {
        E[u].push_back(v);
    }
  
    bool dfs(int u) {
        for (int i = 0; i < E[u].size(); i++) {
            int v = E[u][i];
            if (!vis[v]) {
                vis[v] = true;
                if (match[v] == -1 || dfs(match[v])) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
  
    int solve() {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof(vis));
            if (dfs(i)) ans++;
        }
        return ans;
    }
}g;

bool vis[maxn];
vector<int> E[maxn];

void dfs(int u) {
	if (vis[u] == true) {
		return ;
	}
	vis[u] = true;
	for (int i = 0; i < E[u].size(); i++) {
		int v = E[u][i];
		dfs(v);
	}
}
  
int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        g.init(n);
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            E[u].push_back(v);
            // g.addEdge(u, v);
        }
        for (int i = 1; i <= n; i++) {
        	memset(vis, false, sizeof(vis));
        	dfs(i);
        	for (int j = 1; j <= n; j++) {
        		if (vis[j] == true && i != j) {
        			g.addEdge(i, j);
        		}
        	}
        }
        printf("%d\n", n - g.solve());
    }
    return 0;
}