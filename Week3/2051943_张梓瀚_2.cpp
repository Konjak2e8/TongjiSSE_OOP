#include<iostream>
using namespace std;
void Output(string s, const int len, int l, int r) {
	if (r > l) return;
	if (s.length() == len) {
		cout << s << endl;
		return;
	}
	if (l == r) 
		Output(s + '(', len, l + 1, r);
	else if (l - r < len - s.length()) {
		Output(s + '(', len, l + 1, r);
		Output(s + ')', len, l, r + 1);
	}
	else
		Output(s + ')', len, l, r + 1);
	return;
}
int main() {
	int n;
	cin >> n;
	while (cin.fail() || n < 1 || n>8) {
		cout << "n输入有误，请重新输入\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> n;
	}
	Output("(", n * 2, 1, 0);
	return 0;
}