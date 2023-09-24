#include<iostream>
#include<queue>
using namespace std;
bool check(int x) { //���鵱ǰ�Ƿ���ϱ��Ե��ı�׼
	if (x % 7 == 0)
		return true;
	while (x) {
		if (x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}
int main() {
	int n, now = 1;
	queue<int> q; //�ö��д洢n�����
	cin >> n;
	while (n <= 0 || cin.fail()) {
		cin.clear();
		cin.ignore(1e9, '\n');
		cout << "Invalid input. Please input n again:\n";
		cin >> n;
	}
	for (int i = 1; i <= n; i++) q.push(i);
	while (q.size() > 1) {
		if (check(now)) { //����������ɾȥ
			q.pop();
		}
		else { //���������� ��Ҫ�ٹ�һ�ֲŻᱻ���� ���ñ��push����β
			q.push(q.front());
			q.pop();
		}
		now++;
	}
	cout << q.front();
	fflush(stdout);
	return 0;
}