#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 500500;

struct People {
	int a, b, id;

	People() {}
	People(int a, int b, int id): a(a), b(b), id(id) {}

	bool operator<(const People &o) const {
		return (a == o.a && b > o.b) || a < o.a;
	}
};

People p[maxn];
int last[maxn], par[maxn];

int main() {
	freopen("people.in", "r", stdin);
	freopen("people.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		p[i] = People(a, b, i);
	}
	sort(p, p + n);

	last[0] = -1;
	last[1] = 0;
	par[0] = -1;
	int m = 1;
	for (int i = 1; i < n; i++) {
		int l = 0, r = m;
		int mid = 0;
		while (l < r) {
			mid = (l + r + 1) / 2;
			if (p[last[mid]].b >= p[i].b) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		last[l+1] = i;
		par[i] = last[l];
		if (l == m)
			m++;
	}
	printf("%d\n", m);
	int cur = last[m];
	while (cur != -1) {
		printf("%d ", p[cur].id + 1);
		cur = par[cur];
	}
	puts("");
}
