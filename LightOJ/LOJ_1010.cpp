#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n, m; scanf("%d %d", &n, &m);
		if (n == 1 || m == 1) {
			printf("Case %d: %d\n", cas, n * m);
		} else if (n == 2 || m == 2) {
			int tmp = n * m / 8 * 4;
			int tem = min(n * m % 8, 4);
			printf("Case %d: %d\n", cas, tmp + tem);
		} else {
			printf("Case %d: %d\n", cas, (n * m + 1) / 2);
		}
	}
	return 0;
}