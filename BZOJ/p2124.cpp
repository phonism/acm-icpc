#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 20010;
unsigned long long fac[maxn];
unsigned long long val[maxn];

struct SegNode {
	int left, right;
	unsigned long long hash;

	int mid() {
		return (left + right) >> 1;		
	}

	int len() {
		return right - left + 1;
	}
};

struct SegmentTree {

	SegNode tree[maxn * 5];

	// void pushUp(int idx) {
	// 	tree[idx].hash = tree[idx<<1].hash * fac[tree[idx].len()]
	// 		+ tree[idx<<1|1].hash;
	// 	// cout << tree[idx].hash << endl;
	// }

	void build(int left, int right, int idx) {
		tree[idx].left = left;
		tree[idx].right = right;
		if (left == right) {
			tree[idx].hash = val[left];
			return ;
		}
		int mid = tree[idx].mid();
		build(left, mid, idx << 1);
		build(mid + 1, right, idx << 1 | 1);
		tree[idx].hash = tree[idx<<1].hash * fac[right-mid]
			+ tree[idx<<1|1].hash;
	}

	void update(int pos, int val, int idx) {
		if (tree[idx].left == tree[idx].right) {
			tree[idx].hash = val;
			return ;
		}
		int mid = tree[idx].mid();
		if (pos <= mid) {
			update(pos, val, idx << 1);
		} else {
			update(pos, val, idx << 1 | 1);
		}
		tree[idx].hash = tree[idx<<1].hash * fac[tree[idx].right-mid]
			+ tree[idx<<1|1].hash;
	}

	unsigned long long query(int left, int right, int idx) {
		if (tree[idx].left == left && tree[idx].right == right) {
			return tree[idx].hash;
		}
		int mid = tree[idx].mid();
		if (right <= mid) {
			return query(left, right, idx << 1);
		} else if (left > mid) {
			return query(left, right, idx << 1 | 1);
		} else {
			return query(left, mid, idx << 1) * fac[right-mid]
				+ query(mid + 1, right, idx << 1 | 1);
		}
	}
};
SegmentTree segL, segR;

int test, n, x;

void pre() {
	fac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i-1] * 3;
		// cout << fac[i] << endl;
	}
}

void init() {
	scanf("%d", &n);
	memset(val, 0, sizeof(val));
	segL.build(1, n, 1);
	segR.build(1, n, 1);
	// while (true){}
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (ok == true) {
			continue;
		}
		int tmp = min(x - 1, n - x);
		// cout << tmp << endl;
		if (x > 1 && x != n) {
			unsigned long long left = segR.query(n - x + 2, n - x + 1 + tmp, 1);
			unsigned long long right = segL.query(x + 1, x + tmp, 1);
			// cout << n - x + 2 << " " << n - x + 1 + tmp << endl;
			// cout << x + 1 << " " << x + tmp << endl;
			// cout << left << " " << right << endl;
			if (left != right) {
				ok = true;
			}
		}
		segL.update(x, 1, 1);
		segR.update(n-x+1, 1, 1);
	}
	if (ok) {
		puts("Y");
	} else {
		puts("N");
	}
}

int main() {
	scanf("%d", &test);
	pre();
	for (int cas = 1; cas <= test; cas++) {
		init();
	}
	return 0;
}