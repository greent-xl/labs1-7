#include<iostream>
#include"Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int choise;

	Matrix mat1(4);
	Matrix mat2(4);

	while (true) {
		std::cout << "����� ������� ���������: \n";
		std::cout << "1 - ���� �������\n2 - ���������� ������� ���������� �������\n3 - ������ �������\n4 - ������ ���-�� �������� �������\n5 - ������ ����� �������\n";
		std::cout << "6 - ������ ������������ �������\n7 - �������� ������\n8 - ��������� ������\n9 - ����� ������ � �������\n10 - ��������� ������\n11 - ��������� ������� �� �����\n12 - �����\n";
		std::cout << "������� ����� �������: "; std::cin >> choise;
		switch (choise){
		case 1: {
			system("cls");
			std::cout << "����� ������� ���������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cin >> mat1;
				std::cout << "\n";
				std::cout << "������� ���������";
			}
			else {
				std::cin >> mat2;
				std::cout << "\n";
				std::cout << "������� ���������";
			}
			std::cout << "\n\n";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "����� ������� ���������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				mat1.input();
				std::cout << "\n";
				std::cout << "������� ���������";
			}
			else {
				mat2.input();
				std::cout << "\n";
				std::cout << "������� ���������";
			}
			std::cout << "\n\n";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "����� ������� �������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			std::cout << "\n";
			if (ans == 1) {
				std::cout << mat1;
			}
			else {
				std::cout << mat2;
			}
			std::cout << "\n";
			break;
		}
		case 4: {
			system("cls");
			std::cout << "���-�� ��������� ����� ������� �������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			std::cout << "\n���-�� ��������: ";
			if (ans == 1) {
				std::cout << mat1.get_columns() << "\n\n";
			}
			else {
				std::cout << mat2.get_columns() << "\n\n";
			}
			break;
		}
		case 5: {
			system("cls");
			std::cout << "���� ����� ������� �������?\n1 - ���� ������ �������\n2 - ���� ������ �������\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				std::cout << mat1.trace();
			}
			else {
				std::cout << mat2.trace();
			}
			std::cout << "\n\n";
			break;
		}
		case 6: {
			system("cls");
			std::cout << "������������ ����� ������� �������?\n1 - ������������ ������ �������\n2 - ������������ ������ �������\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				std::cout << mat1.det();
			}
			else {
				std::cout << mat2.det();
			}
			std::cout << "\n\n";
			break;
		}
		case 7: {
			system("cls");
			std::cout << "������ �������: \n";
			mat1.print();
			std::cout << "\n������ �������: \n";
			mat2.print();
			std::cout << "\n";
			mat1 + mat2;
			break;
		}
		case 8: {
			system("cls");
			std::cout << "������ �������: \n";
			mat1.print();
			std::cout << "\n������ �������: \n";
			mat2.print();
			std::cout << "\n";
			mat1 - mat2;
			break;
		}
		case 9: {
			system("cls");
			std::cout << "����� ����� ������� ��������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "������ �������: \n";
				mat1.print();
				-mat1;
			}
			else {
				std::cout << "\n������ �������: \n";
				mat2.print();
				-mat2;
			}
			break;
		}
		case 10: {
			system("cls");
			std::cout << "������ �������: \n";
			mat1.print();
			std::cout << "\n������ �������: \n";
			mat2.print();
			std::cout << "\n";
			mat1 * mat2;
			break;
		}
		case 11: {
			system("cls");
			std::cout << "\n�� ����� ����� �������� �������?\n";
			int k; std::cin >> k;
			std::cout << "����� ������� ��������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "������ �������: \n";
				mat1.print();
				mat1 * k;
			}
			else {
				std::cout << "\n������ �������: \n";
				mat2.print();
				mat2 * k;
			}
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