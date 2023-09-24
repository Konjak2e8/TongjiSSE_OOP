#include <iostream>
#include <exception>
#define SIZE 5
const int MAX_STREAM_SIZE = 65536;
using namespace std;
struct Point {
	int x, y;
	bool operator ==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	friend istream& operator >>(istream& in, const Point& Rec);
	friend ostream& operator <<(ostream& out, const Point& Rec);
};
//重载>>运算符，消掉Point类型输入时的逗号
istream& operator>>(istream& in, Point& Rec) {
	char tmp = ' ';
	in >> Rec.x >> tmp >> Rec.y;
	return in;
}
//重载<<运算符，在输出Point类型时补上逗号
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
	void push(T elem) {
		if (isFull()) {
			return;
		}
		elems[head] = elem;
		head++;
	}
	T pop() {
		T tmp;
		if (isEmpty()) {
			tmp = elems[0];
			return tmp;
		}
		tmp = elems[head - 1];
		head--;
		//cout << tmp << " is popped" << endl;
		return tmp;
	}
	void print() {
		for (int i = 0; i < head; i++) cout << elems[i] << ',';
	}
};
template<typename T>
struct Queue {
	Stack<T> stackA; //入数据的栈
	Stack<T> stackB; //出数据的栈
	void inQueue(T elem) {
		if (isFull()) {
			cerr << "Queue is full!" << endl;
			return;
		}
		stackA.push(elem);
	}
	T deQueue() {
		T tmp;
		if (stackB.isEmpty()) {
			while (!stackA.isEmpty()) {
				stackB.push(stackA.elems[stackA.head - 1]);
				stackA.pop();
			}
		}
		T ret = stackB.elems[stackB.head - 1];
		cout << ret << " is dequeued!" << endl;
		stackB.pop();
		return ret;
	}
	bool isEmpty() {
		return stackA.isEmpty() && stackB.isEmpty();
	}
	bool isFull() {
		return stackA.head + stackB.head == SIZE;
	}
	
	void print() {
		cout << '[';
		stackB.print();
		while (!stackB.isEmpty()) {
			stackB.pop();
		}
		stackA.print();
		cout << ']' << endl;
	}
};
int main() {
	int opt;
	cin >> opt;
	Queue<int>i_que;
	int i_tmp(0);
	Queue<string>s_que;
	string s_tmp(" ");
	Queue<Point>p_que;
	Point p_tmp({ 0, 0 });
	if (opt == 0) {
		while (cin >> opt) {
			switch (opt) {
			case 1:
				cin >> i_tmp;
				i_que.inQueue(i_tmp);
				break;
			case 2:
				if (i_que.isEmpty())
					cerr << "Queue is empty!" << endl;
				else
					i_que.deQueue();
				break;
			case 0:
				i_que.print();
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
				s_que.inQueue(s_tmp);
				break;
			case 2:
				if (s_que.isEmpty())
					cerr << "Queue is empty!" << endl;
				else
					s_que.deQueue();
				break;
			case 0:
				s_que.print();
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
				p_que.inQueue(p_tmp);
				break;
			case 2:
				if (p_que.isEmpty())
					cerr << "Queue is empty!" << endl;
				else
					p_que.deQueue();
				break;
			case 0:
				p_que.print();
				break;
			default:
				break;
			}
			if (opt == 0)
				break;
		}
	}
	return 0;
}