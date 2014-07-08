#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 200200;

struct SegNode {
	int left, right;
	int mx;

	int mid() {
		return (left + right) >> 1;
	}
};

struct SegmentTree {
	
	SegNode tree[maxn * 5];

	void pushUp(int idx) {
		tree[idx].mx = max(tree[idx<<1].mx, tree[idx<<1|1].mx);
	}

	void build(int left, int right, int idx) {
		tree[idx].left = left;
		tree[idx].right = right;
		if (left == right) {
			tree[idx].mx = 0;
			return ;
		}
		int mid = tree[idx].mid();
		build(left, mid, idx << 1);
		build(mid + 1, right, idx << 1 | 1);
		pushUp(idx);
	}

	void update(int left, int right, int idx, int value) {
		if (left == tree[idx].left && right == tree[idx].right) {
			tree[idx].mx = value;
			return ;
		}
		int mid = tree[idx].mid();
		if (left > mid) {
			update(left, right, idx << 1 | 1, value);
		} else if (right <= mid) {
			update(left, right, idx << 1, value);
		} else {
			update(left, mid, idx << 1, value);
			update(mid + 1, right, idx << 1 | 1, value);
		}
		pushUp(idx);
	}

	int query(int left, int right, int idx) {
		if (left == tree[idx].left && right == tree[idx].right) {
			return tree[idx].mx;
		}
		int mid = tree[idx].mid();
		if (left > mid) {
			return query(left, right, idx << 1 | 1);
		} else if (right <= mid) {
			return query(left, right, idx << 1);
		} else {
			return max(query(left, mid, idx << 1), 
					query(mid + 1, right, idx << 1 | 1));
		}
	}
};
SegmentTree seg;

int n, mod;
char op[2];

int main() {
	int tail = 0, tmp = 0;
	scanf("%d %d", &n, &mod);
	seg.build(1, n, 1);
	for (int i = 1; i <= n; i++) {
		scanf("%s", op);
		if (op[0] == 'A') {
			int val; scanf("%d", &val);
			tail++;
			seg.update(tail, tail, 1, (val + tmp) % mod);
		} else {
			int len; scanf("%d", &len);
			tmp = seg.query(tail - len + 1, tail, 1);
			printf("%d\n", tmp);
		}
	}
	return 0;
}
