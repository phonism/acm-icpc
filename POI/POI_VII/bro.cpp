/*
 Good Problem easy think hard implement
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 11111;
int n;
int z[maxn], d[maxn];

long long allSum = 0, allLen = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &z[i], &d[i]);
		allSum += z[i];
		allLen += d[i];
	}
	allLen /= 2;

	// int head = 1, tail = 1;
	// long long tmp = 0, tem = 0;
	// long long sumLeft = 0, sumRight = 0, ans = 0;
	// for (int i = 1; i <= n; i++) {
	// 	tmpLeft += d[i];
	// 	sumLeft += z[i] * tmpLeft;
	// 	if (tmpLeft <= allLen && tmpLeft + d[i+1] > allLen) {
	// 		tail = i;
	// 	}
	// }
	// sumLeft = tem;
	// for (int i = n; i >= tail; i--) {
	// 	tmpRight += d[i];
	// 	sumRight += z[i] * tmpRight;
	// }

	// ans = sumLeft + sumRight;

	// for (int i = 2; i <= n; i++) {
	// 	long long newSumLeft = sumLeft - (tmpLeft - a[i-1]) * d[i-1];
	// 	long long newSumRight = sumRight + tmpRight * d[i-1];
	// 	if (tmpLeft - a[i-1] > allLen) {
	// 		ans = min(newSumLeft + newSumRight, ans);
	// 		continue;
	// 	} else {
	// 		newSumLeft = a[tail] * 
	// 	}
	// }
	int pos = 1;
	long long leftZ = 0, rightZ = 0;
	long long leftD = 0, rightD = 0;
	long long leftSum = 0, rightSum = 0;
	long long answer = 0;
	// find pos
	for (int i = 1; i <= n; i++) {
		leftZ += z[i];
		leftSum += leftD * z[i];
		leftD += d[i];
		if (leftD - d[i] <= allLen && leftD > allLen) {
			pos = i;
			leftD -= d[pos];
			break;
		}
	}
	// pos = 1;
	leftZ = 0; leftD = 0; leftSum = 0;
	for (int i = 1; i <= pos; i++) {
		leftZ += z[i];
		leftSum += leftD * z[i];
		if (i != pos)
			leftD += d[i];
	}

	for (int i = n; i > pos; i--) {
		rightZ += z[i];
		rightD += d[i];
		rightSum += rightD * z[i];
	}

	answer = leftSum + rightSum;

	// printf("%d %lld %lld %lld\n", pos, answer, leftSum, rightSum);

	for (int i = 2; i <= n; i++) {
		long long newLeftSum = leftSum - (leftZ - z[i-1]) * d[i-1];
		long long newRightSum = rightSum + (rightZ + z[i-1]) * d[i-1];
		// printf("first: %lld %lld\n", newLeftSum, newRightSum);
		leftD = leftD - d[i-1];
		rightD = rightD + d[i-1];
		leftZ = leftZ - z[i-1];
		rightZ = rightZ + z[i-1];
		// printf("LeftD: %lld RightD: %lld\n", leftD, rightD);
		// if (leftD > allLen) {
		answer = min(answer, newLeftSum + newRightSum);
		while (leftD + d[pos] < allLen) {
			//pos = (pos + 1) % (n + 1);
			int newPos = (pos + 1) % n == 0 ? n : (pos + 1) % n;
			newLeftSum += (leftD + d[pos]) * z[newPos];
			newRightSum -= rightD * z[newPos];
			// printf("%lld %lld\n", newLeftSum, newRightSum);
			answer = min(answer, newLeftSum + newRightSum);
			leftD += d[pos];
			leftZ += z[newPos];
			leftSum = newLeftSum;
			rightD -= d[newPos];
			rightZ -= z[newPos];
			rightSum = newRightSum;
			// printf("RIGHTD:%lld\n", rightD);
			pos = newPos;
		}
		leftSum = newLeftSum;
		rightSum = newRightSum;
	}

	printf("%lld\n", answer);

}