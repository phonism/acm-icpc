#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 111;
int n, m, answer;
int mp[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct Point {
	int x, y, hi;

	Point() {}
	Point(int x, int y, int hi): x(x), y(y), hi(hi) {}
};

struct cmp {
	bool operator()(Point &a, Point &b) {
		return a.hi > b.hi;
	}
};

priority_queue<Point, vector<Point>, cmp> q;

void floodFill(int x, int y, int hi) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false) {
			vis[tx][ty] = true;
			if (mp[tx][ty] >= hi) {
				Point tmp(tx, ty, mp[tx][ty]);
				q.push(tmp);
			} else {
				answer += (hi - mp[tx][ty]);
				floodFill(tx, ty, hi);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &mp[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		Point tmp(i, 1, mp[i][1]);
		Point tem(i, m, mp[i][m]);
		if (m == 1) {
			q.push(tmp);
		} else {
			q.push(tmp);
			q.push(tem);
		}
		vis[tmp.x][tmp.y] = true;
		vis[tem.x][tem.y] = true;
	}

	for (int j = 2; j <= m - 1; j++) {
		Point tmp(1, j, mp[1][j]);
		Point tem(n, j, mp[n][j]);
		if (n == 1) {
			q.push(tmp);
		} else {
			q.push(tmp);
			q.push(tem);
		}
		vis[tmp.x][tmp.y] = true;
		vis[tem.x][tem.y] = true;
	}

	while (!q.empty()) {
		Point tmp = q.top();
		q.pop();
		floodFill(tmp.x, tmp.y, tmp.hi);
	}
	printf("%d\n", answer);
}