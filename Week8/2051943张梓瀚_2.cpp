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
		//总体思路：遍历并记录当前能到达的最远位置，在到达该位置前不跳跃，最远位置与当前位置重合后跳到当前位置
		int curMaxIdx = nums[0], maxIdx = nums[0]; 
		//curMaxIdx记录当前能跳到的最远位置 maxIdx记录整个过程中能到达的最远位置
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