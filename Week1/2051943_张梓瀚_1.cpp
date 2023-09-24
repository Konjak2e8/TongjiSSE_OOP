#include<iostream>
using namespace std;
inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
class Triangle { //��������
private:
	int len1, len2, len3;

	bool isValid(int x) { //���볬���ж�
		if (x <= 0 || x >= 10000) return false;
		return true;
	}
	bool Check() { //�Ƿ񹹳�������
		if (len1 > len2) {
			swap(len1, len2);
		}
		if (len2 > len3) {
			swap(len2, len3);
		}
		return (len1 + len2 > len3);
	}

public:
	Triangle() { //���캯��
		len1 = 0, len2 = 0, len3 = 0;
	}
	~Triangle() {}; //��������
	void Input() { //���루���������Ƿ�Ϸ����жϣ�
		cin >> len1 >> len2 >> len3;
		while (cin.fail() || !isValid(len1) || !isValid(len2) || !isValid(len3)) {
			if (cin.good()) {
				cout << "Input range error.Please input a,b,c again(1 <= a,b,c <= 10000):\n";
				cin >> len1 >> len2 >> len3;
				continue;
			}
			cin.clear();
			cin.ignore(1e9, '\n');
			cout << "Invalid input.Please input a,b,c again:\n";
			cin >> len1 >> len2 >> len3;
		}
	}


	void Output() { //�жϲ�������
		if (Check()) {
			cout << "�ɹ���������" << endl;
		}
		else {
			cout << "��������ʧ��" << endl;
		}
		fflush(stdout);
	}
};

int main() {
	Triangle T;
	T.Input();
	T.Output();

	return 0;
}