#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 101010;

long long val[maxn];

struct SegNode {
	int left, right;
	long long sum;
	
	int mid() {
		return (left + right) >> 1;
	}

	int len() {
		return right - left + 1;
	}
};

struct SegmentTree {

	SegNode tree[maxn * 7];

	void pushUp(int idx) {
		tree[idx].sum = tree[idx<<1].sum + tree[idx<<1|1].sum;
	}

	void build(int left, int right, int idx) {
		tree[idx].left = left;
		tree[idx].right = right;
		if (left == right) {
			tree[idx].sum = val[left];
			return ;
		}
		int mid = tree[idx].mid();
		build(left, mid, idx << 1);
		build(mid + 1, right, idx << 1 | 1);
		pushUp(idx);
	}

	void update(int left, int right, int idx) {
		if (tree[idx].len() == tree[idx].sum) {
			return ;
		}
		if (tree[idx].left == tree[idx].right) {
			tree[idx].sum = (long long) sqrt(1.0 * tree[idx].sum);
			return ;
		}
		int mid = tree[idx].mid();
		if (left > mid) {
			update(left, right, idx << 1 | 1);
		} else if (right <= mid) {
			update(left, right, idx << 1);
		} else {
			update(left, mid, idx << 1);
			update(mid + 1, right, idx << 1 | 1);
		}
		pushUp(idx);
	}

	long long query(int left, int right, int idx) {
		if (tree[idx].left == left && right == tree[idx].right) {
			return tree[idx].sum;
		}
		int mid = tree[idx].mid();
		if (left > mid) {
			return query(left, right, idx << 1 | 1);
		} else if (right <= mid) {
			return query(left, right, idx << 1);
		} else {
			return query(left, mid, idx << 1) 
				+ query(mid + 1, right, idx << 1 | 1);
		}
	}
};
SegmentTree seg;

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &val[i]);
	}
	seg.build(1, n, 1);
	scanf("%d", &m);
	for (int cas = 1; cas <= m; cas++) {
		int op; scanf("%d", &op);
		if (op == 0) {
			int l, r;		
			scanf("%d %d", &l, &r);
			if (l > r) 
				swap(l, r);
			seg.update(l, r, 1);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			if (l > r)
				swap(l, r);
			printf("%lld\n", seg.query(l, r, 1));
		}
	}
}
