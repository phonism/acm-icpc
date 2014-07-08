#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<long long> ans;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			long long l = i, r = n / i;
			for (int j = 0; j <= n; j += r) {
				if ((j + 2) % l == 0 && j + 2 <= n) {
					ans.insert(j + 1);
				}
				if ((j - 2) >= 0 && (j - 2) % l == 0) {
					ans.insert(j - 1);
				}
			}
		}
	}
	if (ans.size() == 0) {
		puts("None");
	} else {
		for (set<long long>::iterator it = ans.begin(); it != ans.end(); it++) {
			printf("%lld\n", *it);
		}
	}
	return 0;
}