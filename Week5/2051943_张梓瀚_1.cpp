#include <iostream>
#define SIZE 5
const int MAX_STREAM_SIZE = 65536;
using namespace std;
struct Point {
	int x, y;
	bool operator ==(const Point& rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	friend istream& operator >>(istream& in, const Point& Rec);
	friend ostream& operator <<(ostream& out, const Point& Rec);
};
//����>>�����������Point��������ʱ�Ķ���
istream& operator>>(istream& in, Point& Rec) {
	char tmp = ' ';
	in >> Rec.x >> tmp >> Rec.y;
	return in;
}
//����<<������������Point����ʱ���϶���
ostream& operator<< (ostream& out, const Point& Rec) {
	out << '(' << Rec.x << ',' << Rec.y << ')';
	return out;
}
template <typename T>
struct Stack {
	T elems[SIZE];
	int head = 0;
	bool isEmpty() {
		return head == 0;
	}
	bool isFull() {
		return head == SIZE;
	}
	void push(T elem, bool isMerge) {
		if (isMerge) { //�����Ƿ���Ҫ�����ϲ�
			if (!isEmpty() && elem == elems[head - 1]) {
				head--;
				return;
			}
		}
		if (isFull()) {
			cerr << "Stack is full!" << endl;
			return;
		}
		elems[head] = elem;
		head++;
	}
	T pop() {
		T tmp;
		if (isEmpty()) {
			tmp = elems[0];
			cerr << "Stack is empty!" << endl;
			return tmp;
		}
		tmp = elems[head - 1];
		head--;
		cout << tmp << " is popped" << endl;
		return tmp;
	}
	void print() {
		cout << '[';
		for (int i = 0; i < head; i++) cout << elems[i] << ',';
		cout << ']';
		cout << endl;
	}
};
void test1() { //����Ҫ�����ϲ������Σ���2�⣩
	int opt;
	cin >> opt;
	Stack<int>i_stk;
	int i_tmp(0);
	Stack<string>s_stk;
	string s_tmp(" ");
	Stack<Point>p_stk;
	Point p_tmp({ 0, 0 });
	if (opt == 0) {
		while (cin >> opt) {
			switch (opt) {
			case 1:
				cin >> i_tmp;
				i_stk.push(i_tmp, 0);
				break;
			case 2:
				i_stk.pop();
				break;
			case 0:
				i_stk.print();
				break;
			default:
				break;
			}
			if (opt == 0)
				break;
		}
	}
	else if (opt == 1) {
		while (cin >> opt) {
			switch (opt) {
			case 1:
				cin >> s_tmp;
				s_stk.push(s_tmp, 0);
				break;
			case 2:
				s_stk.pop();
				break;
			case 0:
				s_stk.print();
				break;
			default:
				break;
			}
			if (opt == 0)
				break;
		}
	}
	else if (opt == 2) {
		while (cin >> opt) {
			switch (opt) {
			case 1:
				cin >> p_tmp;
				p_stk.push(p_tmp, 0);
				break;
			case 2:
				p_stk.pop();
				break;
			case 0:
				p_stk.print();
				break;
			default:
				break;
			}
			if (opt == 0)
				break;
		}
	}
	return;
}
void test2() { //��Ҫ�����ϲ������Σ���3�⣩
	string s;
	cin >> s;
	Stack<char>c_stk;
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		c_stk.push(*it, 1);
	}
	c_stk.print();
	return;
}
int main() {
	int opt = 1;
	char ch = ' ';
	while (opt) {
		cout << "������Ҫ���еĲ��ԣ�����1���������������͵Ĳ��ԣ�����2���������ϲ����ԣ�����0�˳���" << endl;
		cin >> opt;
		if (cin.fail() || opt < 0 || opt>2) {
			opt = 1;
			cin.clear();
			while (ch = getchar() != '\n');
			continue;
		}
		if (opt) cout << "�����룺" << endl;
		if (opt == 1) test1();
		else if (opt == 2) test2();
	}
	return 0;
}