#include<iostream>
#include<list>
#include<map>
#include<string>


int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	std::map<std::string, std::list<std::string>> groups;

	while (true) {
		std::cout << "1 - �������� ������ � ��������\n2 - ������ � ��������\n3 - �����\n������� �������: ";
		std::cin >> choise; std::cin.get();
		switch (choise) {
		case 1: {
			system("cls");
			std::string str;
			std::getline(std::cin, str);
			std::string key, value;
			bool flag = true;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == ' ') { flag = false; continue; }
				if (flag == true) { key += str[i]; }
				else { value += str[i]; }
			}
			if (groups.find(key) == groups.end()) {
				std::list<std::string> lst;
				lst.push_back(value);
				groups.insert(std::pair<std::string, std::list<std::string>>(key, lst));
			}
			else {
				groups[key].push_back(value);
			}
			break;
		}
		case 2: {
			system("cls");
			for (auto group : groups) {
				std::cout << "������: " << group.first << std::endl;
				std::cout << "��������: \n";
				for (auto stud : group.second) {
					std::cout << "\t" << stud << std::endl;
				}

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