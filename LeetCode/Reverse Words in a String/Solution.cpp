#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		vector<string> result;
		int len = s.length();
		string tmp = "";
		for (int i = 0; i < len; i++) {
			if (s[i] == ' ') {
				result.push_back(tmp);
				tmp = "";
				continue;
			} else {
				tmp += s[i];
			}
		}
		result.push_back(tmp);
		bool first = false;
		s = "";
		for (int i = result.size() - 1; i >= 0; i--) {
			if (result[i] != "") {
				if (first == false) {
					s += result[i];
					first = true;
				} else {
					s += " ";
					s += result[i];
				}
			}
		}
	}
};

Solution sol;

int main() {
	string s = "the sky is blue";
	sol.reverseWords(s);
	cout << s << endl;
	return 0;
}