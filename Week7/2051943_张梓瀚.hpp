#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
const double eps = 1e-12;
class point {
private:
	double x, y;
public:
	point() { x = 0, y = 0; };
	point(double _x, double _y) { x = _x, y = _y; }
	double get_x() const {
		return x;
	}
	double get_y() const {
		return y;
	}
	void set_x(double _x) {
		x = _x;
	}
	void set_y(double _y) {
		y = _y;
	}
};
class polygen {
private:
	std::vector<point>pts;
public:
	polygen() {};
	polygen(std::vector<point>points) {
		for (std::vector<point>::iterator it = points.begin(); it != points.end(); it++) {
			pts.push_back(*it);
		}
	}
	int sides() const {
		const int sz = pts.size();
		if (sz < 2)
			return 0;
		else if (sz == 2)
			return 1;
		int sidesCnt = 1;
		double slopeLst = (pts[0].get_y() - pts[sz - 1].get_y()) / (pts[0].get_x() - pts[sz - 1].get_x() + eps), slopeNow = 0;
		// 分母加一个极小偏移量，防止分母为0的情况导致错误
		for (int i = 0; i < sz - 1; i++) {
			slopeNow = (pts[i + 1].get_y() - pts[i].get_y()) / (pts[i + 1].get_x() - pts[i].get_x() + eps);
			if (fabs(slopeNow - slopeLst) > (1e-6))
				sidesCnt++;
		}
		return sidesCnt;
	}
	virtual double area() = 0;
};
class rectangle :public polygen {
private:
	double X1, X2, Y1, Y2;
public:
	rectangle(point left_up, point right_bottom) :polygen(std::vector<point>{left_up, point{ right_bottom.get_y(),left_up.get_x() }, right_bottom, point{ left_up.get_x(),right_bottom.get_y() } }) {
		X1 = left_up.get_x(), Y1 = left_up.get_y();
		X2 = right_bottom.get_x(), Y2 = right_bottom.get_y();
	}
	double area() {
		return (Y2 - Y1) * (X2 - X1);
	}
};
class triangle :public polygen {
private:
	double x[3], y[3], len[3];
public:
	triangle(point p1, point p2, point p3) :polygen(std::vector<point>{p1, p2, p3}) {
		x[0] = p1.get_x(), x[1] = p2.get_x(), x[2] = p3.get_x();
		y[0] = p1.get_y(), y[1] = p2.get_y(), y[2] = p3.get_y();
		len[0] = sqrt((y[0] - y[2]) * (y[0] - y[2]) + (x[0] - x[2]) * (x[0] - x[2]));
		len[1] = sqrt((y[1] - y[0]) * (y[1] - y[0]) + (x[1] - x[0]) * (x[1] - x[0]));
		len[2] = sqrt((y[2] - y[1]) * (y[2] - y[1]) + (x[2] - x[1]) * (x[2] - x[1]));
	}
	double area() {
		double s = 0;
		for (int i = 0; i < 3; i++) s += len[i];
		s *= 0.5;
		return sqrt(s * (s - len[0]) * (s - len[1]) * (s - len[2]));
	}
};