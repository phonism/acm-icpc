#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 55005;

struct Line {
	int k, b, no;

	Line() {}
	Line(int k, int b, int no): k(k), b(b), no(no) {}

	bool operator<(const Line &o) const {
		return k < o.k || k == o.k && b > o.b;
	}

	bool operator==(const Line &o) const {
		return k == o.k;
	}
};

double cal(Line a, Line b) {
	return double(b.b - a.b) / (a.k - b.k);
}

Line L[maxn], S[maxn];
int n, top = 0;
vector<int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &L[i].k, &L[i].b);
		L[i].no = i;
	}
	sort(L, L + n);
	n = unique(L, L + n) - L;
	for (int i = 0; i < n; i++) {
		while (top > 1 && cal(S[top-1], S[top-2]) >= cal(S[top-1], L[i]))
			--top;
		S[top++] = L[i];
	}
	for (int i = 0; i < top; i++) {
		ans.push_back(S[i].no);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}
	puts("");
}
