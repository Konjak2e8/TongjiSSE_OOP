#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int max(vector<int>nums) {
	int maxNum = -INT_MAX;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		if (*it > maxNum) {
			maxNum = *it;
		}
	}
	return maxNum;
}
int min(vector<int>nums) {
	int minNum = INT_MAX;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		if (*it < minNum) {
			minNum = *it;
		}
	}
	return minNum;
}
int mean(vector<int>nums) {
	int avgNum = 0;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		avgNum += *it;
	}
	avgNum /= nums.size();
	return avgNum;
}
int median(vector<int>nums) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}
int calc(int a, int b, int c, int d, int e, int(*p_func)(vector<int>)) {
	return p_func(vector<int>{a, b, c, d, e});
}
int main() {
	string s;
	int a, b, c, d, e;
	char ch = ' ';
	while (1) {
		cin >> s >> a >> b >> c >> d >> e;
		if (cin.good()) {
			break;
		}
		else {
			cin.clear();
			while ((ch = getchar()) != '\n');
			cout << "输入错误，请重新输入" << endl;
		}
	}
	switch (s[2]) {
	case 'x':
		cout << calc(a, b, c, d, e, max);
		break;
	case 'n':
		cout << calc(a, b, c, d, e, min);
		break;
	case 'a':
		cout << calc(a, b, c, d, e, mean);
		break;
	case 'd':
		cout << calc(a, b, c, d, e, median);
		break;
	default:
		break;
	}
	return 0;
	
}