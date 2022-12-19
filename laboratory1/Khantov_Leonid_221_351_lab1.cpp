#include <iostream>
#include <bitset>
#include <locale>

int main() {
	setlocale(LC_ALL, "Russian");

	//������� 1
	std::cout << "1.\n" << "Khantov Leonid Vladimirovich, 221-351" << std::endl;

	//������� 2
	std::cout << "2.\n" << "min int = " << INT_MIN << ", max int = " << INT_MAX << ", size of int = " << sizeof(int) << std::endl;
	std::cout << "min unsigned int = 0, max unsigned int = " << UINT_MAX << ", size of unsigned int = " << sizeof(unsigned int) << std::endl;
	std::cout << "min short = " << SHRT_MIN << ", max short = " << SHRT_MAX << ", size of short = " << sizeof(short) << std::endl;
	std::cout << "min unsigned short = 0, max unsigned short = " << USHRT_MAX << ", size of unsigned short = " << sizeof(unsigned short) << std::endl;
	std::cout << "min long = " << LONG_MIN << ", max long = " << LONG_MAX << ", size of long = " << sizeof(long) << std::endl;
	std::cout << "min long long = " << LLONG_MIN << ", max long long = " << LLONG_MAX << ", size of long long = " << sizeof(long long) << std::endl;
	std::cout << "min double = -1.7E-308, max double = 1.7E+308, size of double = 8" << std::endl;
	std::cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ", size of char = " << sizeof(char) << std::endl;
	std::cout << "bool = true or false, size of bool = " << sizeof(bool) << std::endl;

	//������� 3
	std::cout << "3.\n";
	std::cout << "������ �����: ";
	int num; std::cin >> num;
	std::cout << "� �������� ���� " << std::bitset<8*sizeof(num)>(num) << std::endl;
	std::cout << "� ����������������� ���� " << std::hex << num << std::dec << std::endl;
	std::cout << "bool " << (bool)num << std::endl;
	std::cout << "double " << (double)num << std::endl;
	std::cout << "char " << (char)num << std::endl;

	//������� 4
	std::cout << "4.\n������� ������������ a * x = b: ";
	int a, b; std::cin >> a >> b;
	std::cout << a << " * x = " << b << std::endl <<
		"x = " << b << " / " << a << std::endl <<
		"x = " << (double)b / a << std::endl <<
		"�����: " << (double)b / a << std::endl;

	//������� 5
	std::cout << "5.\n������� ���������� ������� �� ������ ";
	std::cin >> a >> b;
	std::cout << "�������� ���������������� � ����� � ����������� " << (a + b) / 2.;
	return 0;
}