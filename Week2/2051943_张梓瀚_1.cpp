#include<string>
#include<iostream>
using namespace std;
bool isPalind(string s) { //判断是否为回文
	string exp_s = "#";
	for (int i = 0; i < s.size(); i++) {
		exp_s += s[i];
		exp_s += '#';
	}
	int now_pos = exp_s.size() / 2;
	for (int i = 0; now_pos - i > 0; i++) {
		if (exp_s[now_pos - i] != exp_s[now_pos + i]) {
			return false;
		}
	}
	return true;
}
int main() {
	string s, dup_s;
	cin >> s;
	bool hasPalindSub = false;
	for (int i = 0; i < s.size(); i++) {
		//分类讨论 取得s删去i位置一个字符后的新串
		if (i == 0) dup_s = s.substr(1, s.size() - 1);
		else if (i == s.size() - 1) dup_s = s.substr(0, s.size() - 1);
		else dup_s = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
		if (isPalind(dup_s)) {
			hasPalindSub = true;
			break;
		}
	}
	cout << (hasPalindSub ? "True" : "False");
	fflush(stdout);
	return 0;
}