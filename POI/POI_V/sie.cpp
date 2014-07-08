#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Answer {
	int x, y;

	Answer() {}
	Answer(int x, int y): x(x), y(y) {}
	
	bool friend operator<(Answer a, Answer b) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
};

const int maxn = 222;
int n;
int d[maxn][maxn];
vector<Answer> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool ok = false;
			for (int k = 1; k <= n; k++) {
				if (i != k && j != k) {
					if (d[i][k] + d[k][j] == d[i][j]) {
						ok = true;
						break;
					}
				}
			}
			if (ok == false) {
				ans.push_back(Answer(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
}