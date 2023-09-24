#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const char c[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
const int N = 15;
class Six2Other { //�����Ƶ���������
private:
	int m, Dec;
	char k[N];
	string ans;
	
	int myPow(int base, int k) { //��λ��������ݣ����ڼ�������������ʮ����ֵ
		int res = 1;
		while (k) {
			if (k & 1) res *= base;
			base *= base;
			k >>= 1;
		}
		return res;
	}
	int Six2Dec(char c[], int base) { //����������ת��ʮ����
		int res = 0;
		for (int i = 0; i < strlen(c); i++) {
			res += (c[i] - '0') * myPow(6, int(strlen(c)) - i - 1);
		}
		return res;
	}
	string Dec2m(int x, int base) { //��ʮ������ת��n����
		string s = "";
		while (x) {
			s += c[x % base];
			x /= base;
		}
		return s;
	}
public:
	void Input() { //���벢�ж������Ƿ�Ϸ�
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
	void Output() { //ת�������
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