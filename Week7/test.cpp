#include"_2051943ÕÅè÷å«.h"
int main() {
	point p1({ 3.3,4.6 });
	std::cout << "x = " << p1.get_x() << std::endl << "y = " << p1.get_y() << std::endl;
	p1.set_x(1.5);
	p1.set_y(2.7);
	std::cout << "x = " << p1.get_x() << std::endl << "y = " << p1.get_y() << std::endl;
	point p2({ 4.5,4.7 });
	rectangle rec1(p1, p2);
	std::cout << "area of rectangle = " << rec1.area() << std::endl;
	std::cout << "nums of sides of rectangle = " << rec1.sides() << std::endl;
	point p3({ 4.5,2.7 });
	point p4({ 4.5,-7.3 });
	triangle tri1(p1, p3, p4);
	std::cout << "area of triangle = " << tri1.area() << std::endl;
	std::cout << "num of sides of triangle = " << tri1.sides() << std::endl;
	return 0;
}