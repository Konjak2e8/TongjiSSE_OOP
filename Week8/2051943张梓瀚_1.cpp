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
			//遍历并找出高度最高的位置
			maxn = *i_tmp;
			maxIdx = v1.size() - 1;
		}
	}
	int ans = 0, nowMax = 0;
	for (int i = 0; i < maxIdx; i++) { //从左侧遍历
		if (v1[i] > nowMax) {
			nowMax = v1[i];
			continue;
		}
		ans += nowMax - v1[i];
	}
	nowMax = 0;
	for (int i = v1.size() - 1; i > maxIdx; i--) { //从右侧遍历
		if (v1[i] > nowMax) {
			nowMax = v1[i];
			continue;
		}
		ans += nowMax - v1[i];
	}
	cout << ans << endl;
	return 0;
}