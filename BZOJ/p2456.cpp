#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	scanf("%d %d", &n, &num);
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		int x; scanf("%d", &x);
		if (cnt == 0) {
			cnt = 1;
			num = x;
		} else {
			if (x == num)
				cnt++;
			else
				cnt--;
		}
	}
	printf("%d\n", num);
}
