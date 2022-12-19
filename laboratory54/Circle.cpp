#include"Circle.h"
#include<iostream>
Circle::Circle() {
	radius = 0;
}
Circle::~Circle() {};
Circle::Circle(double r) {
	radius = r;
}
Circle::Circle(int kx, int ky, double r) {
	x = kx; y = ky; radius = r;
}
void Circle::print() {
	std::cout << "x = " << x << ", y = " << y << ", radius = " << radius << std::endl;

}
void Circle::Set() {
	std::cout << "������� ����� ���������� � ������:\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	std::cout << "radius = "; std::cin >> radius;
}
void Circle::perimeter() {
	std::cout << "���������� � �������� " << radius << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
	std::cout << "Ÿ �������� = " << 6.28 * radius << std::endl;
}
void Circle::area() {
	std::cout << "���������� � �������� " << radius << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
	std::cout << "Ÿ ������� = " << 3.14 * radius * radius << std::endl;
}