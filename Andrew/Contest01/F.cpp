#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 333;
const double eps = 1e-6;

double x[maxn], y[maxn], r[maxn], d[maxn], T[maxn];
double fx, fy, fr;
bool bb[maxn];
int n, m, a[maxn];

struct Node {
	int y, n;
	double d;
};

Node b[maxn * maxn];

double dis(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j])
			+ (y[i] - y[j]) * (y[i] - y[j]));
}

void addEdge(int x, int y, double d) {
	b[++m].y = y;
	b[m].d = d;
	b[m].n = a[x];
	a[x] = m;
}

bool spfa() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = a[x]; i; i = b[i].n) {
			int y = b[i].y;
			if (d[y] > d[x] + b[i].d + eps) {
				d[y] = d[x] + b[i].d;
				if (bb[y]) {
					if ((++T[y]) >= n)
						return 0;
					bb[y] = 0;
					q.push(y);
				}
			}
		}
		bb[x] = 1;
	}
	return 1;
}

int main() {
	freopen("out.in", "r", stdin);
	freopen("out.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
	}
	scanf("%lf %lf %lf", &fx, &fy, &fr);
	for (int i = 1; i <= n; i++) {
		x[i] -= fx;
		y[i] -= fy;
		r[i] += fr;
	}

	x[0] = y[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (r[i] + r[j] - eps >= dis(i, j)) {
				double c = acos((x[i] * x[j] + y[i] * y[j])
						/ (dis(i, 0) * dis(j, 0)));
				if (x[i] * y[j] - x[j] * y[i] < 0) {
					c = -c;
				}
				addEdge(i, j, c);
				addEdge(j, i, -c);
			}
		}
	}
	
	if (spfa()) {
		puts("YES");
	} else {
		puts("NO");
	}
}
