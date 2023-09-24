#include<iostream>
#include<string>
using namespace std;
const int ROW_LEN = 100;
struct Rectangle {
	int x, y;
	Rectangle() { x = 0, y = 0; }
	bool operator <(const Rectangle& Rec) {
		return x * y < Rec.x* Rec.y;
	}
	bool operator ==(const Rectangle& Rec) {
		return x * y == Rec.x * Rec.y;
	}
	friend istream& operator >>(istream& in, const Rectangle& Rec);
	friend ostream& operator <<(ostream& out, const Rectangle& Rec);
};
//重载>>运算符，消掉Rectangle类型输入时的逗号
istream& operator>>(istream& in, Rectangle& Rec) {
	char tmp = ' ';
	in >> Rec.x >> tmp >> Rec.y;
	return in;
}
//重载<<运算符，在输出Rectangle类型时补上逗号
ostream& operator<< (ostream& out, const Rectangle& Rec) {
	out << Rec.x << ',' << Rec.y;
	return out;
}
//按题目要求重载string类型的<运算符
bool operator < (const string& s1, const string& s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	return s1.length() < s2.length();
}
//在三个同类对象中取最大值的函数模板
template<typename T>
T max(T t1, T t2, T t3) {
	if (t1 == t2 && t2 == t3)
		return t1;
	else if (t1 == t2 && t3 < t1)
		return t1;
	else if (t1 == t3 && t2 < t1)
		return t1;
	else if (t2 == t3 && t1 < t2)
		return t2;
	else if (t2 < t1 && t3 < t1)
		return t1;
	else if (t1 < t2 && t3 < t2)
		return t2;
	else
		return t3;
}

int main() {
	int i_num[3] = { 0,0,0 };
	double d_flt[3] = { 0,0,0 };
	char c_char[3] = { 0,0,0 };
	string s_str[3];
	Rectangle r_rct[3], r_rctTmp[3], * pr_pntRct[3];
	for (int i = 0; i < 3; i++)
		pr_pntRct[i] = &r_rctTmp[i];
	for (int i = 0; i < 3; i++)
		cin >> i_num[i];
	for (int i = 0; i < 3; i++)
		cin >> d_flt[i];
	for (int i = 0; i < 3; i++)
		cin >> c_char[i];
	for (int i = 0; i < 3; i++)
		cin >> s_str[i];
	for (int i = 0; i < 3; i++)
		cin >> r_rct[i];
	for (int i = 0; i < 3; i++)
		cin >> r_rctTmp[i];
	cout << max(i_num[0], i_num[1], i_num[2]) << endl;
	cout << max(d_flt[0], d_flt[1], d_flt[2]) << endl;
	cout << max(c_char[0], c_char[1], c_char[2]) << endl;
	cout << max(s_str[0], s_str[1], s_str[2]) << endl;
	cout << max(r_rct[0], r_rct[1], r_rct[2]) << endl;
	cout << max(*pr_pntRct[0], *pr_pntRct[1], *pr_pntRct[2]) << endl;
	return 0;
}