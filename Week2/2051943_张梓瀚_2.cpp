#include<iostream>
#include<iomanip>
using namespace std;
//�ɱ��������֪�����һ����������4��5����˽����β����ȻΪ0�����ǽ�β0��λ���洢������
//�Է�ֹ������������������㲿���ټ������0
void calc(int n) {
	int tmp = 1, zeroCnt = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) tmp *= 4;
		else tmp *= 5;
		while (tmp % 10 == 0) { //��β���������ֹ���
			tmp /= 10;
			zeroCnt++;
		}
	}
	cout << tmp; //������㲿��
	for (int i = 0; i < zeroCnt; i++) cout << '0'; //���β��
	return;
}
int main() {
	int n = 1; //��Ϊ1����������ж������Ƿ���
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