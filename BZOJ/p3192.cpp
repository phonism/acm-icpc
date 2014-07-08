#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100100;

struct BIT {

	int n, tree[maxn];

	void init(int _) {
		n = _;
		memset(tree, 0, sizeof(tree));
	}

	void init(int _, int val[maxn]) {
		n = _;
		for (int i = 0; i < maxn; i++) {
			tree[i] = val[i];
		}
	}

	int lowbit(int x) {
		return x & -x;
	}

	void update(int idx, int val) {
		for ( ; idx <= n; idx += lowbit(idx)) {
			tree[idx] += val;
		}
	}

	int query(int idx) {
		int res = 0;
		for ( ; idx; idx -= lowbit(idx)) {
			res += tree[idx];
		}
		return res;
	}

};

BIT bit;

struct Node {
	int x, id;
	bool operator<(const Node o) const {
		return x > o.x;
	}
};

Node a[maxn];

int n1, n2;
int pos[maxn];

int main() {
	scanf("%d %d", &n1, &n2);
	bit.init(n1 + n2);
	for (int i = n1; i >= 1; i--) {
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	for (int i = n1 + 1; i <= n1 + n2; i++) {
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	int n = n1 + n2;
	sort(a + 1, a + n + 1);
	int tail = n1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = a[i].id;
		if (tmp <= tail) {
			ans += tail - tmp - (bit.query(tail) - bit.query(tmp));
			tail = tmp;
			bit.update(tmp, 1);
		} else {
			ans += tmp - 1 - tail - (bit.query(tmp - 1) - bit.query(tail));
			tail = tmp - 1;
			bit.update(tmp, 1);
		}
	}
	printf("%lld\n", ans);
	return 0;

}