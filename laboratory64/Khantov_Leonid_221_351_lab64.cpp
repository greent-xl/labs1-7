#include<iostream>
#include<string>
#include<deque>
#include<set>

struct data_test{
	std::string name;
	int mark;
};

std::string getname() {
	std::string name;
	std::cin >> name;
	return name;
}

int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	std::set<std::string> names;
	std::deque<data_test> answers;
	data_test stud;

	while (true) {
		std::cout << "1 - ���� �������� � ������\n2 - ��� �������� � ������\n3 - �����\n������� �������: ";
		std::cin >> choise; std::cin.get();
		switch (choise) {
		case 1: {
			system("cls");
			std::cout << "������� ��������: ";
			stud.name = getname();
			std::cout << "������� ������: ";
			std::cin >> stud.mark;
			if (names.find(stud.name) == names.end()) {
				names.insert(stud.name);
				answers.push_back(stud);
			}
			else {
				std::cout << "���� ������� ��� ������ ����, ������ �� ��������\n";
			}
			break;
		}
		case 2: {
			system("cls");
			for (auto stud : answers) {
				std::cout << "�������: " << stud.name << ", ������: " << stud.mark << std::endl;

			}
			break;
		}
		case 3: {
			return 0;
		}
		default:
			system("cls");
			std::cout << "�������� �������\n";
			continue;
		}
	}
}