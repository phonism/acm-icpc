#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

char s[100100];
int dp[100100];

int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%s", s);
	int ans = 0;
	for (int i = 0; s[i]; i++) {
		dp[i] = 0;
		if (i && s[i] == ']') {
			if (s[i-dp[i-1]-1] == '[') {
				dp[i] = dp[i-1] + 2;
				dp[i] = dp[i-dp[i]] + dp[i];
			}
		}
		if (i && s[i] == ')') {
			if (s[i-dp[i-1]-1] == '(') {
				dp[i] = dp[i-1] + 2;
				dp[i] = dp[i-dp[i]] + dp[i];
			}
		}
		if (dp[i] > dp[ans])
			ans = i;
	}
	for (int i = ans - dp[ans] + 1; i <= ans; i++) {
		putchar(s[i]);
	}
	puts("");
}
