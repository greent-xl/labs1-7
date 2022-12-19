//#include<iostream>
//
//class Figure {
//public:
//	virtual void perimeter() = 0;
//	virtual void area() = 0;
//	virtual void print() = 0;
//	virtual void Set() = 0;
//	virtual int Getx() = 0;
//	virtual int Gety() = 0;
//	virtual int Getsize() = 0;
//	virtual double Getradius() = 0;
//};
//
//
//class Position : public Figure {
//protected:
//	int x;
//	int y;
//private:
//	void perimeter() override {};
//	void area() override {};
//	int Getsize() override { return 0; };
//	double Getradius() override { return 0; };
//public:
//	Position();
//	~Position();
//	Position(int kz);
//	Position(int kx, int ky);
//	void print() override;
//	void Set() override;
//	int Getx() { return x; };
//	int Gety() { return y; };
//};
//
//class Square : virtual public Position {
//protected:
//	int size;
//private:
//	double Getradius() override { return 0; };
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
//class Comands {
//public:
//	void print(Figure* f){
//		f->print();
//	}
//	void Set(Figure* f){
//		f->Set();
//	}
//	void perimeter(Figure* f){
//		f->perimeter();
//	}
//	void area(Figure* f){
//		f->area();
//	}
//	int Getx(Figure* f) { return f->Getx(); };
//	int Gety(Figure* f) { return f->Gety(); };
//	int Getsize(Figure* f) { return f->Getsize(); };
//	double Getradius(Figure* f) { return f->Getradius(); };
//};
//
//
//
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
//Square::~Square(){}
//Square::Square(int len) {
//	size = len;
//}
//Square::Square(int kx, int ky, int len) {
//	x = kx; y = ky; size = len;
//}
//void Square::print(){
//	std::cout << "x = " << x << ", y = " << y << ", size = " << size << std::endl;
//
//}
//void Square::Set() {
//	std::cout << "������� ����� ���������� � ������:\n";
//	std::cout << "x = "; std::cin >> x;
//	std::cout << "y = "; std::cin >> y;
//	std::cout << "size = "; std::cin >> size;
//}
//void Square::perimeter(){
//	std::cout << "������� �� �������� " << size << " � ������ � ����� � ������������ (" << x << ", " << y << ")\n";
//	std::cout << "��� �������� = " << size * 4 << std::endl;
//}
//void Square::area(){
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
//
//int main(){
//	setlocale(LC_ALL, "ru");
//	int choise;
//	int x = 0, y = 0, size = 0; double radius = 0;
//
//
//	while (true) {
//		std::cout << "����� ������� ���������: \n";
//		std::cout << "1 - ���� ���������\n2 - ����� ���������\n3 - ���� ��������\n4 - ����� ������� ��������\n5 - ����� ��������� ��������\n6 - ���� �����\n7 - ����� ������� �����\n8 - ����� ��������� �����\n";
//		std::cout << "9 - ���� ��������� ���������� �� ������� ��������\n10 - ���� ��������� ���������� �� �������\n11 - ����� ������� �������� � �����\n12 - ����� ��������� �������� � �����\n13 - �����\n";
//		std::cout << "������� ����� �������: "; std::cin >> choise;
//		switch(choise){
//		case 1: {
//			Circle pos;
//			pos.Set();
//			x = pos.Getx(); y = pos.Gety(); radius = pos.Getradius();
//			break;
//		}
//		case 2: {
//			Circle pos(x, y, radius);
//			pos.print();
//
//
//			break;
//		}
//		
//		
//		case 13: {
//			return 0;
//		}
//		default:
//			std::cout << "�������� �������\n";
//			std::cout << "\n";
//			continue;
//		}
//	}
//}
