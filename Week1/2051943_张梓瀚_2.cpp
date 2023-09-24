#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const char c[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
const int N = 15;
class Six2Other { //六进制到其他进制
private:
	int m, Dec;
	char k[N];
	string ans;
	
	int myPow(int base, int k) { //按位运算快速幂，用于计算六进制数的十进制值
		int res = 1;
		while (k) {
			if (k & 1) res *= base;
			base *= base;
			k >>= 1;
		}
		return res;
	}
	int Six2Dec(char c[], int base) { //把六进制数转成十进制
		int res = 0;
		for (int i = 0; i < strlen(c); i++) {
			res += (c[i] - '0') * myPow(6, int(strlen(c)) - i - 1);
		}
		return res;
	}
	string Dec2m(int x, int base) { //把十进制数转成n进制
		string s = "";
		while (x) {
			s += c[x % base];
			x /= base;
		}
		return s;
	}
public:
	void Input() { //输入并判断输入是否合法
		cin >> m >> k;
		while (cin.fail() || m < 2 || m>20) {
			if (cin.good()) {
				cout << "Input range error.Please input m again(2 <= m <= 20):\n";
				cin >> m;
				continue;
			}
			cin.clear();
			cin.ignore(1e9, '\n');
			cout << "Invalid input.Please input m,k again:\n";
			cin >> m >> k;
		}
	}
	void Output() { //转换并输出
		Dec = Six2Dec(k, 10);
		ans = Dec2m(Dec, m);
		for (int i = ans.length() - 1; i >= 0; i--)
			cout << ans[i];
		fflush(stdout);
	}
};

int main() {
	Six2Other s;
	s.Input();
	s.Output();
	return 0;
}