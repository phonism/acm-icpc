#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1111;

vector<int> red[maxn];
bool vis[maxn][maxn];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		red[x].push_back(y);
		red[y].push_back(x);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d\n", (int)red[i].size());
	// }
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += red[i].size() * (n - red[i].size() - 1);
	}
	answer = n * (n - 1) * (n - 2) / 6 - answer / 2;
	printf("%d\n", answer);
	return 0;
}