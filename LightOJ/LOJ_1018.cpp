#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y): x(x), y(y) {}
};

Point p[20];

int cross(int i, int j, int k) {
	int tmp = (p[i].x - p[k].x) * (p[j].y - p[k].y);
	int tem = (p[i].y - p[k].y) * (p[j].x - p[k].x);
	return tmp - tem;
}

int state[20][20];
int f[666666];
int n;

void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	memset(state, 0, sizeof(state));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (cross(i, j, k) == 0) {
					state[i][j] |= (1 << k);
				}
			}
		}
	}
}

int work() {
	//memset(f, inf, sizeof(f));
	for (int i = 0; i < 666666; i++) {
		f[i] = inf;
	}
	f[0] = 0;
	int limit = (1 << n) - 1;
	for (int i = 0; i <= limit; i++) {
		if (f[i] == inf) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) 
				continue;
			for (int k = j + 1; k < n; k++) {
				f[i|state[j][k]] = min(f[i|state[j][k]], f[i] + 1);
			}
			break;
		}
	}
	int answer = f[limit];
	answer = min(answer, f[limit^1<<n-1] + 1);
	// for (int i = 0; i < n; i++) {
	// 	answer = min(answer, f[limit^1<<i] + 1);
	// }
	return answer;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		init();
		printf("Case %d: %d\n", cas, work());
	}
	return 0;
}