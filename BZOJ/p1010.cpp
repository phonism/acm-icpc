#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 50050;

long long dp[maxn], sum[maxn];
int que[maxn], head, tail;
int n, L;

double func(int j, int k) {
	double tmp = 1.0 * (dp[j-1] - dp[k-1] + (sum[j-1] + j)
		* (sum[j-1] + j) - (sum[k-1] + k) * (sum[k-1] + k));
	double tem = 1.0 * (sum[j-1] + j - sum[k-1] - k);
	return tmp / tem;
}

int main() {
	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &sum[i]);
		sum[i] += sum[i-1];
	}
	que[head] = 1;
	for (int i = 1; i <= n; i++) {
		while (head < tail && func(que[head], que[head+1]) 
				< 2 * (sum[i] + i - L))
			head++;
		int tmp = que[head];
		long long tem = sum[i] + i - L - sum[tmp-1] - tmp;
		dp[i] = dp[tmp-1] + tem * tem;
		while (head < tail && func(que[tail-1], que[tail])
				> func(que[tail], i + 1))
			tail--;
		que[++tail] = i + 1;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
