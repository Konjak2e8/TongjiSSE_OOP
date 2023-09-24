#include<iostream>
#include<queue>
using namespace std;
bool check(int x) { //检验当前是否符合被吃掉的标准
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
	queue<int> q; //用队列存储n个标号
	cin >> n;
	while (n <= 0 || cin.fail()) {
		cin.clear();
		cin.ignore(1e9, '\n');
		cout << "Invalid input. Please input n again:\n";
		cin >> n;
	}
	for (int i = 1; i <= n; i++) q.push(i);
	while (q.size() > 1) {
		if (check(now)) { //满足条件就删去
			q.pop();
		}
		else { //不满足条件 则要再过一轮才会被数到 将该标号push到队尾
			q.push(q.front());
			q.pop();
		}
		now++;
	}
	cout << q.front();
	fflush(stdout);
	return 0;
}