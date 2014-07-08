#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int BASE = (int) 1e4;

struct BigInt {
	vector<int> a;

	BigInt() {}
	BigInt(int b) {
		while (b > 0) {
			a.push_back(b % BASE);
			b /= BASE;
		}
	}

	int get(int p) {
		if (p >= a.size())
			return 0;
		return a[p];
	}

	int &operator[] (int p) {
		return a[p];
	}

	BigInt operator+(BigInt b) {
		BigInt c;
		c.a.resize(max(a.size(), b.a.size()));
		int carry = 0;
		for (int i = 0; i < c.a.size(); i++) {
			carry += get(i) + b.get(i);
			c[i] = carry % BASE;
			carry /= BASE;
		}
		if (carry > 0)
			c.a.push_back(carry);
		return c;
	}

	void operator+=(BigInt b) {
		*this = *this + b;
	}

	void print() {
		if ((int) a.size() == 0)
			printf("0");
		else {
			printf("%d", a.back());
			for (int i = (int) a.size() - 2; i >= 0; i--)
				printf("%04d", a[i]);
		}
		puts("");
	}
};

const int maxn = 66;

int n;
BigInt dp[maxn][maxn][maxn];

int main() {
	freopen("regular.in", "r", stdin);
	freopen("regular.out", "w", stdout);

	scanf("%d", &n);
	dp[0][0][0] = 1;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				if (i < j || j < k || i < k)
					continue;
				if (i + 1 >= j && j >= k)
					dp[i+1][j][k] += dp[i][j][k];
				if (i >= j + 1 && j + 1 >= k)
					dp[i][j+1][k] += dp[i][j][k];
				if (i >= j && j >= k + 1)
					dp[i][j][k+1] += dp[i][j][k];
			}
		}
	}
	dp[n][n][n].print();
	return 0;
}
