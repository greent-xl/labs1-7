#include<iostream>
#include"Position.h"
#include"Square.h"
#include"Circle.h"
#include"Circlesquare.h"


//class Position{
//protected:
//	int x;
//	int y;
//private:
//	virtual void perimeter() {};
//	virtual void area() {};
//	virtual int Getsize() { return 0; };
//	virtual double Getradius() { return 0; };
//public:
//	Position();
//	~Position();
//	Position(int kz);
//	Position(int kx, int ky);
//	virtual void print();
//	virtual void Set();
//	virtual int Getx() { return x; };
//	virtual int Gety() { return y; };
//};
//
//class Square : virtual public Position {
//protected:
//	int size;
//private:
//	double Getradius() { return 0; };
//public:
//	Square();
//	~Square();
//	Square(int len);
//	Square(int kx, int ky, int len);
//	void print() override;
//	void Set() override;
//	void perimeter() override;
//	void area() override;
//	int Getx() override { return x; };
//	int Gety() override { return y; };
//	int Getsize() override { return size; };
//};
//
//class Circle : virtual public Position {
//protected:
//	double radius;
//private:
//	int Getsize() override { return 0; };
//public:
//	Circle();
//	~Circle();
//	Circle(double r);
//	Circle(int kx, int ky, double r);
//	void print() override;
//	void Set() override;
//	void perimeter() override;
//	void area() override;
//	int Getx() override { return x; };
//	int Gety() override { return y; };
//	double Getradius() override { return radius; };
//};
//
//class Circlesquare : public Square, public Circle {
//public:
//	Circlesquare();
//	~Circlesquare();
//	Circlesquare(int len);
//	Circlesquare(int kx, int ky, double r);
//	void print() override;
//	void Set() override;
//	void perimeter() override;
//	void area() override;
//	int Getx() override { return x; };
//	int Gety() override { return y; };
//	int Getsize() override { return size; };
//	double Getradius() override { return radius; };
//};
//
//
//Position::Position() {
//	x = 0; y = 0;
//}
//Position::~Position() {}
//Position::Position(int kz) {
//	x = kz; y = kz;
//}
//Position::Position(int kx, int ky) {
//	x = kx; y = ky;
//}
//void Position::print() {
//	std::cout << "x = " << x << ", y = " << y << std::endl;
//}
//void Position::Set() {
//	std::cout << "������� ����� ����������:\n";
//	std::cout << "x = "; std::cin >> x;
//	std::cout << "y = "; std::cin >> y;
//}
//
//Square::Square() {
//	size = 0;
//}
//Square::~Square() {}
//Square::Square(int len) {
//	size = len;
//}
//Square::Square(int kx, int ky, int len) {
//	x = kx; y = ky; size = len;
//}
//void Square::print() {
//	std::cout << "x = " << x << ", y = " << y << ", size = " << size << std::endl;
//
//}
//void Square::Set() {
//	std::cout << "������� ����� ���������� � ������:\n";
//	std::cout << "x = "; std::cin >> x;
//	std::cout << "y = "; std::cin >> y;
//	std::cout << "size = "; std::cin >> size;
//}
//void Square::perimeter() {
//	std::cout << "������� �� �������� " << size << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
//	std::cout << "��� �������� = " << size * 4 << std::endl;
//}
//void Square::area() {
//	std::cout << "������� �� �������� " << size << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
//	std::cout << "��� ������� = " << size * size << std::endl;
//}
//
//Circle::Circle() {
//	radius = 0;
//}
//Circle::~Circle() {};
//Circle::Circle(double r) {
//	radius = r;
//}
//Circle::Circle(int kx, int ky, double r) {
//	x = kx; y = ky; radius = r;
//}
//void Circle::print() {
//	std::cout << "x = " << x << ", y = " << y << ", radius = " << radius << std::endl;
//
//}
//void Circle::Set() {
//	std::cout << "������� ����� ���������� � ������:\n";
//	std::cout << "x = "; std::cin >> x;
//	std::cout << "y = "; std::cin >> y;
//	std::cout << "radius = "; std::cin >> radius;
//}
//void Circle::perimeter() {
//	std::cout << "���������� � �������� " << radius << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
//	std::cout << "Ÿ �������� = " << 6.28 * radius << std::endl;
//}
//void Circle::area() {
//	std::cout << "���������� � �������� " << radius << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
//	std::cout << "Ÿ ������� = " << 3.14 * radius * radius << std::endl;
//}
//
//Circlesquare::Circlesquare() {};
//Circlesquare::~Circlesquare() {};
//Circlesquare::Circlesquare(int len) {
//	size = len; radius = size / 2.;
//}
//Circlesquare::Circlesquare(int kx, int ky, double r) {
//	x = kx; y = ky; radius = r; size = radius * 2;
//}
//void Circlesquare::print() {
//	this->::Square::print();
//	this->::Circle::print();
//}
//void Circlesquare::Set() {
//	std::cout << "������� ����� ����������:\n";
//	std::cout << "x = "; std::cin >> x;
//	std::cout << "y = "; std::cin >> y;
//	std::cout << "������ ������ �������� ��� ������ ����������?\n1 - ������ ��������\n2 - ������ ����������\n";
//	int ans; std::cin >> ans;
//	if (ans == 1) {
//		std::cout << "size = "; std::cin >> size;
//		radius = size / 2.;
//	}
//	else {
//		std::cout << "radius = "; std::cin >> radius;
//		size = radius * 2;
//	}
//}
//void Circlesquare::perimeter() {
//	this->::Square::perimeter();
//	this->::Circle::perimeter();
//}
//void Circlesquare::area() {
//	this->::Square::area();
//	this->::Circle::area();
//}
//

int main() {
	setlocale(LC_ALL, "ru");
	int choise;
	int x = 0, y = 0, size = 0; double radius = 0;

	while (true) {
		std::cout << "����� ������� ���������: \n";
		std::cout << "1 - ���� ���������\n2 - ����� ���������\n3 - ���� ��������\n4 - ����� ������� ��������\n5 - ����� ��������� ��������\n6 - ���� �����\n7 - ����� ������� �����\n8 - ����� ��������� �����\n";
		std::cout << "9 - ���� ��������� ����������\n10 - ����� ������� �������� � �����\n11 - ����� ��������� �������� � �����\n12 - �����\n";
		std::cout << "������� ����� �������: "; std::cin >> choise;
		switch (choise) {
		case 1: {
			system("cls");
			Position pos;
			pos.Set();
			x = pos.Getx(); y = pos.Gety();
			std::cout << "\n";
			break;
		}
		case 2: {
			system("cls");
			Position pos(x, y);
			pos.print();
			std::cout << "\n";
			break;
		}
		case 3: {
			system("cls");
			Square pos;
			pos.Set();
			x = pos.Getx(); y = pos.Gety(); size = pos.Getsize();
			std::cout << "\n";
			break;
		}
		case 4: {
			system("cls");
			Square pos(x, y, size);
			pos.area();
			std::cout << "\n";
			break;
		}
		case 5: {
			system("cls");
			Square pos(x, y, size);
			pos.perimeter();
			std::cout << "\n";
			break;
		}
		case 6: {
			system("cls");
			Circle pos;
			pos.Set();
			x = pos.Getx(); y = pos.Gety(); size = pos.Getradius();
			std::cout << "\n";
			break;
		}
		case 7: {
			system("cls");
			Circle pos(x, y, size);
			pos.area();
			std::cout << "\n";
			break;
		}
		case 8: {
			system("cls");
			Circle pos(x, y, size);
			pos.perimeter();
			std::cout << "\n";
			break;
		}
		case 9: {
			system("cls");
			Circlesquare pos;
			pos.Set();
			x = pos.Getx(); y = pos.Gety(); size = pos.Getsize(); radius = pos.Getradius();
			std::cout << "\n";
			break;
		}
		case 10: {
			system("cls");
			Circlesquare pos(x, y, size);
			pos.area();
			std::cout << "\n";
			break;
		}
		case 11: {
			system("cls");
			Circlesquare pos(x, y, size);
			pos.perimeter();
			std::cout << "\n";
			break;
		}
		case 12: {
			return 0;
		}
		default:
			std::cout << "�������� �������\n";
			std::cout << "\n";
			continue;
		}
	}
}
