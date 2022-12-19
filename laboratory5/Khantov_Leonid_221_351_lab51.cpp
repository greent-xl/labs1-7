#include<iostream>
#include"Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int choise = 0;

	Matrix mat1(4);
	Matrix mat2(4);
	while (true) {
		std::cout << "����� ������� ���������: \n";
		std::cout << "1 - ���� �������\n2 - ������ �������\n3 - ������ ���-�� ����� �������\n4 - ������ ���-�� �������� �������\n5 - ������ (i, j) ��������\n";
		std::cout << "6 - ����� ������\n7 - ��������� ������\n8 - ������ ����� �������\n9 - ������ ������������ �������\n10 - ��������� ������� �� �����\n11 - �����\n";
		std::cout << "������� ����� �������: "; std::cin >> choise;
		switch (choise) {
		case 1: {
			system("cls");
			std::cout << "����� ������� ���������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			std::cout << "������� ������ �������: \n���-�� ����� - ";
			int rw; std::cin >> rw; std::cout << "���-�� ��������� - "; int cl; std::cin >> cl;
			if (ans == 1) {
				mat1.createmat(rw, cl);
			}
			else {
				mat2.createmat(rw, cl);
			}
			std::cout << "������� �������\n\n";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "����� ������� �������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				mat1.print();
			}
			else {
				mat2.print();
			}
			std::cout << "\n";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "���-�� ����� ����� ������� �������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "���-�� ����� ������ ������� = " << mat1.get_rows() << "\n\n";
			}
			else {
				std::cout << "���-�� ����� ������ ������� = " << mat2.get_rows() << "\n\n";
			}
			break;
		}
		case 4: {
			system("cls");
			std::cout << "���-�� ������� ����� ������� �������?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "���-�� ������� ������ ������� = " << mat1.get_columns() << "\n\n";
			}
			else {
				std::cout << "���-�� ������� ������ ������� = " << mat2.get_columns() << "\n\n";
			}
			break;
		}
		case 5: {
			system("cls");
			std::cout << "�� ����� ������� ������� (i, j) �������?\n1 - �� ������\n2 - �� ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "������� ����� ������(����� �� 0 �� " << mat1.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "������� ����� �������(����� �� 0 �� " << mat1.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "�������: \n";
				mat1.print();
				std::cout << "������� �� ���� ������� = " << mat1.get_elem(ans_i, ans_j);
			}
			else {
				std::cout << "������� ����� ������(����� �� 0 �� " << mat2.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "������� ����� �������(����� �� 0 �� " << mat2.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "�������: \n";
				mat2.print();
				std::cout << "������� �� ���� ������� = " << mat2.get_elem(ans_i, ans_j);
			}
			std::cout << "\n\n";
			break;
		}
		case 6: {
			system("cls");
			mat1.sum(mat2);
			std::cout << "\n\n";
			break;
		}
		case 7: {
			system("cls");
			mat1.mult(mat2);
			std::cout << "\n\n";
			break;
		}
		case 8: {
			system("cls");
			std::cout << "���� ����� ������� �������?\n1 - ���� ������ �������\n2 - ���� ������ �������\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				mat1.trace();
			}
			else {
				mat2.trace();
			}
			std::cout << "\n";
			break;
		}
		case 9: {
			system("cls");
			std::cout << "������������ ����� ������� �������?\n1 - ������������ ������ �������\n2 - ������������ ������ �������\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				int f = mat1.get_columns();
				mat1.det(f);
			}
			else {
				int f = mat2.get_columns();
				mat2.det(f);
			}
			std::cout << "\n";
			break;
		}
		case 10: {
			system("cls");
			std::cout << "������� ����� �� ������� �������� �������: ";
			int k;  std::cin >> k;
			std::cout << "����� ������� �������� �� " << k << "?\n1 - ������\n2 - ������\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "������� �� ���������: \n";
				mat1.print();
				Matrix mat3(mat1.mult_by_num(k));
				std::cout << "������� ����� ���������:\n";
				mat3.print();
			}
			else {
				std::cout << "������� �� ���������: \n";
				mat2.print();
				Matrix mat3(mat2.mult_by_num(k));
				std::cout << "������� ����� ���������:\n";
				mat3.print();
			}
			break;
		}
		case 11: {
			return 0;
		}
		default:
			std::cout << "�������� �������\n";
			continue;
		}
	}
	return 0;
}