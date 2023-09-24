#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>nums;
	int* i_tmp = new int;
	while (cin >> *i_tmp)
		nums.push_back(*i_tmp);
	delete i_tmp;
	int jump_min = 0;
	if (nums.size() >= 2) {
		//����˼·����������¼��ǰ�ܵ������Զλ�ã��ڵ����λ��ǰ����Ծ����Զλ���뵱ǰλ���غϺ�������ǰλ��
		int curMaxIdx = nums[0], maxIdx = nums[0]; 
		//curMaxIdx��¼��ǰ����������Զλ�� maxIdx��¼�����������ܵ������Զλ��
		jump_min = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (i > curMaxIdx) {
				curMaxIdx = maxIdx;
				jump_min++;
			}
			if (maxIdx < nums[i] + i) {
				maxIdx = nums[i] + i; 
			}
		}
	}
	cout << jump_min << endl;
	return 0;
}