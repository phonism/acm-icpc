#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100100;

long long d[maxn], a[maxn];
int l[maxn], r[maxn];
typedef long long LL;

set<pair<LL, LL> > heap;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		if (i > 1) {
			a[i] = d[i] - d[i-1];
			l[i] = i - 1;
			r[i] = i + 1;
			heap.insert(make_pair(a[i], i));
		}
	}
	a[1] = 1LL << 60;
	r[1] = 2;
	heap.insert(make_pair(a[1], 1));
	a[n+1] = 1LL << 60;
	l[n+1] = n;
	heap.insert(make_pair(a[n+1], n+1));
	long long answer = 0;
	for (int i = 0; i < k; i++) {
		set<pair<LL, LL> >::iterator it = heap.begin();
		answer += it->first;
		LL tmp = it->second;
		int left = l[tmp];
		int right = r[tmp];
		l[tmp] = l[left];
		r[l[left]] = tmp;
		r[tmp] = r[right];
		l[r[right]] = tmp;
		a[tmp] = a[left] + a[right] - a[tmp];
		heap.erase(*it);
		heap.erase(make_pair(a[left], left));
		heap.erase(make_pair(a[right], right));
		heap.insert(make_pair(a[tmp], tmp));
	}
	printf("%lld\n", answer);
	return 0;
}