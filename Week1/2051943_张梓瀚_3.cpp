#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 505;
struct BigInteger {
	char s[N];
	int len, bit[N];
	BigInteger() { //构造函数
		len = 0;
		memcpy(s, "", 1);
		memset(bit, 0, sizeof bit);
	}
	~BigInteger() {};
	void Input() { //输入并判断输入是否合法
		cin >> len >> s;
		while (cin.fail() || strlen(s) != len) {
			if (cin.good()) {
				cout << "Input length mismatching.Please input again:\n";
				cin >> len >> s;
				continue;
			}
			cin.clear();
			cin.ignore(1e9, '\n');
			cout << "Input error.Please input again:\n";
			cin >> len >> s;
		}
		for (int i = 1; i <= len; i++) bit[i] = s[len - i] - '0';
	}
	void Output() { //按位输出大整数
		for (int i = len; i >= 1; i--) cout << bit[i];
		cout << endl;
		fflush(stdout);
	}
	BigInteger operator + (const BigInteger& T) const { //重载运算符
		BigInteger res;
		res.len = len > T.len ? len : T.len;
		for (int i = 1; i <= res.len; i++)
		{
			res.bit[i] += bit[i] + T.bit[i];
			res.bit[i + 1] += res.bit[i] / 10;
			res.bit[i] %= 10;
		}
		if (res.bit[res.len + 1] > 0) res.len++;
		while (res.len > 1 && res.bit[res.len] == 0) res.len--;
		return res;
	}
};

int main() {
	BigInteger BigInteger1, BigInteger2;
	BigInteger1.Input();
	BigInteger2.Input();
	BigInteger res = BigInteger1 + BigInteger2;
	res.Output();
	return 0;
}