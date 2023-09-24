#include<iostream>
using namespace std;
int main() {
	string s;
	int numRows;
	cin >> s >> numRows;
	while (cin.fail() || numRows<1 || numRows>1000) {
		cout << "输入错误，请重新输入\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> s >> numRows;
	}
	int len = 2 * (numRows - 1);
	for (int i = 0; i < numRows; i++) { //i表示当前行数
		bool isEnd = true;
		for (int j = 0;; j++) { // j表示当前在第几个V形
			if (s.length() < j * len) break;
			if (j * len + i < s.length())
				cout << s[j * len + i];
			if (i != 0 && i != numRows - 1)
				if (j * len + len - i < s.length())
					cout << s[j * len + len - i];
		}
	}
	return 0;
}