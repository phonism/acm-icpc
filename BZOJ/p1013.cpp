#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int maxn = 22;
const double eps = 1e-8;

double f[maxn], a[maxn][maxn], b[maxn][maxn];
int n;

double gauss() {
	for (int i = 1; i <= n; i++) {
		int x = i;
		for (int j = i + 1; j <= n; j++) {
			if (fabs(a[j][i] - a[x][i]) > eps)
				x = j;
		}
		if (x != i) {
			for (int j = 1; j <= n + 1; j++) {
				swap(a[i][j], a[x][j]);
			}
		}
		for (int j = i + 1; j <= n; j++) {
			if (fabs(a[j][i]) > eps) {
				double tmp = a[j][i] / a[i][i];
				for (int k = i; k <= n + 1; k++) {
					a[j][k] -= tmp * a[i][k];
				}
			}
		}
	}
	for (int i = n; i; i--) {
		double tmp = a[i][n+1];
		for (int j = i + 1; j <= n; j++) {
			tmp -= f[j] * a[i][j];
		}
		f[i] = tmp / a[i][i];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lf", &b[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		double tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += b[i+1][j] * b[i+1][j] - b[i][j] * b[i][j];
			a[i][j] = 2 * (b[i+1][j] - b[i][j]);
		}
		a[i][n+1] = tmp;
	}
	gauss();
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			printf("%.3f", f[i]);
		else
			printf(" %.3f", f[i]);
	}
	puts("");
}
