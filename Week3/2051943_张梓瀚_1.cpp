#include<vector>
#include<iostream>
using namespace std;
const int N = 1005, minLim = 1, maxLim = 100000;
vector<int>nums, greaterPrev[N], smallerPrev[N]; //������vector��ÿ����֮ǰ������/С����������
int main() {
	int *t = new int;
	while (cin >> *t) {
		if (cin.fail() || *t<minLim || *t>maxLim) {
			cin.clear();
			cin.ignore(100000, '\n');
		}
		nums.push_back(*t);
		if (nums.size() == 1000)
			break;
	}
	delete t;
	
	long long ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[i]) {
				greaterPrev[i].push_back(j);
				ans += greaterPrev[j].size(); //��ÿ������Ϊ��β�� ���� С������������֮ǰ�����������greaterPrev��
			}
			if (nums[j] < nums[i]) {
				smallerPrev[i].push_back(j);
				ans += smallerPrev[j].size(); //����ͬ��
			}
		}
	}
	cout << ans << endl;
	return 0;
}