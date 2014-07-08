#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
	int x, y;
	
	Point() {}
	Point(int x, int y): x(x), y(y) {}

	bool friend operator<(Point a, Point b) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
};

struct Answer {
	int x, y;
	Answer() {}
	Answer(int x, int y): x(x), y(y) {}
};

Point p[55555];

vector<Answer> ans;

int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		p[i] = Point(x, y);
	}
	sort(p, p + n);
	Answer tmp = Answer(p[0].x, p[0].y);
	// for (int i = 0; i < n; i++) {
	// 	printf("%d %d\n", p[i].x, p[i].y);
	// }
	for (int i = 1; i < n; i++) {
		if (p[i].x <= tmp.y) {
			tmp.y = max(tmp.y, p[i].y);
		} else {
			ans.push_back(tmp);
			tmp.x = p[i].x;
			tmp.y = p[i].y;
		}
	}
	ans.push_back(tmp);
	
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}
