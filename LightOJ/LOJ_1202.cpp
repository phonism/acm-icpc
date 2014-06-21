#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int tmp = abs(r2 - r1), tem = abs(c2 - c1);
		if (abs(tmp - tem) % 2 == 1) {
			printf("Case %d: impossible\n", cas);
		} else if (abs(tmp - tem) == 0) {
			printf("Case %d: 1\n", cas);
		} else {
			printf("Case %d: 2\n", cas);
		}
	}
	return 0;
}
