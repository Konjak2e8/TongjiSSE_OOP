#include<iostream>
#include<queue>
using namespace std;
int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}
int main() {
	int *i_tmp = new int;
	vector<int>v1;
	int maxn = 0, maxIdx = 0;
	while (cin >> *i_tmp) {
		v1.emplace_back(*i_tmp);
		if (*i_tmp > maxn) {
			//�������ҳ��߶���ߵ�λ��
			maxn = *i_tmp;
			maxIdx = v1.size() - 1;
		}
	}
	int ans = 0, nowMax = 0;
	for (int i = 0; i < maxIdx; i++) { //��������
		if (v1[i] > nowMax) {
			nowMax = v1[i];
			continue;
		}
		ans += nowMax - v1[i];
	}
	nowMax = 0;
	for (int i = v1.size() - 1; i > maxIdx; i--) { //���Ҳ����
		if (v1[i] > nowMax) {
			nowMax = v1[i];
			continue;
		}
		ans += nowMax - v1[i];
	}
	cout << ans << endl;
	return 0;
}