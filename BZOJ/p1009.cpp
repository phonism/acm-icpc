#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxm = 20;

int n, m, mod, A[maxm], next[maxm + 1];

struct Matrix {
	int mat[maxm][maxm];

	Matrix() {
		memset(mat, 0, sizeof(mat));
	}

	void operator=(const Matrix &o) {
		memcpy(mat, o.mat, sizeof(mat));
	}

	Matrix operator*(Matrix &o) {
		Matrix res;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					res.mat[i][j] += mat[i][k] * o.mat[k][j];
					res.mat[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix orig;

Matrix power(int n) {
	if (n == 1)
		return orig;
	Matrix tmp = power(n / 2);
	tmp = tmp * tmp;
	if (n & 1)
		tmp = tmp * orig;
	return tmp;
}

int main() {
	scanf("%d %d %d", &n, &m, &mod);
	char ch[maxm+1];
	scanf("%s", ch);
	for (int i = 0; i < m; i++) {
		A[i+1] = ch[i] - '0';
	}
	
	next[1] = 0;
	for (int i = 2, j = 0; i <= m; i++) {
		while (j > 0 && A[j+1] != A[i])
			j = next[j];
		if (A[j+1] == A[i])
			j++;
		next[i] = j;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 10; j++) {
			int k = i;
			while (k > 0 && A[k+1] != j)
				k = next[k];
			if (A[k+1] == j)
				k++;
			orig.mat[k][i]++;
		}
	}
/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", orig.mat[i][j]);
		}
		puts("");
	}
*/

	Matrix answer = power(n);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans += answer.mat[i][0];
		ans %= mod;
	}
	printf("%d\n", ans);
}
