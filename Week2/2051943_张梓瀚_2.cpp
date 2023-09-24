#include<iostream>
#include<iomanip>
using namespace std;
//由本题题意可知，结果一定含有因子4和5，因此结果的尾数必然为0，考虑将尾0的位数存储起来，
//以防止结果溢出，最后输出完非零部分再集中输出0
void calc(int n) {
	int tmp = 1, zeroCnt = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) tmp *= 4;
		else tmp *= 5;
		while (tmp % 10 == 0) { //将尾零存起来防止溢出
			tmp /= 10;
			zeroCnt++;
		}
	}
	cout << tmp; //输出非零部分
	for (int i = 0; i < zeroCnt; i++) cout << '0'; //输出尾零
	return;
}
int main() {
	int n = 1; //置为1，方便后续判断输入是否超限
	cin >> n;
	while (n <= 0 || n >= 50 || cin.fail()) {
		if (cin.good()) {
			cout << "Input out of range.Please input n again:\n";
			cin >> n;
		}
		else {
			cin.clear();
			cin.ignore(1e9, '\n');
			cout << "Input error.Please input n again:\n";
			cin >> n;
		}
	}
	calc(n);
	fflush(stdout);
	return 0;
}