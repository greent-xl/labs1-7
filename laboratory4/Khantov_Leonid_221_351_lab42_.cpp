//#include <iostream>
//#include <fstream>
//#include<string>
//
//std::string file_format(const std::string file_path_full) {
//	std::string files;
//	files.assign(file_path_full, file_path_full.rfind('.') + 1, file_path_full.size() - 1);
//	return files;
//}
//
//std::string file_name(const std::string file_path_full) {
//	std::string files;
//	files.assign(file_path_full, file_path_full.rfind('\\') + 1, file_path_full.rfind('.') - file_path_full.rfind('\\') - 1);
//	return files;
//}
//
//std::string file_path(const std::string file_path_full) {
//	std::string files;
//	if (std::count(file_path_full.begin(), file_path_full.end(), '\\') == 1) {
//		files = "";
//	}
//	else {
//		files.assign(file_path_full, file_path_full.find('\\') + 1, file_path_full.rfind('\\') - file_path_full.find('\\') - 1);
//	}
//	return files;
//}
//
//std::string file_disk(const std::string file_path_full) {
//	std::string files;
//	files.assign(file_path_full, 0, file_path_full.find('\\'));
//	return files;
//}
//
//std::string file_rename(std::string file_path_full) {
//	std::string str, str1, str2, str3;
//	std::cout << "������� ����� ��������: \n";
//	getline(std::cin, str2);
//	str1.assign(file_path_full, 0, file_path_full.rfind('\\') + 1);
//	str3.assign(file_path_full, file_path_full.rfind('.'), file_path_full.size() - file_path_full.rfind('.'));
//	str = str1 + str2 + str3;
//	return str;
//}
//
//std::string rename_new(std::string file_path_full) {
//	std::string str, str1, str2;
//	str1.assign(file_path_full, 0, file_path_full.rfind('.'));
//	str2.assign(file_path_full, file_path_full.rfind('.'), file_path_full.size() - file_path_full.rfind('.'));
//	str = str1 + "_copy" + str2;
//	return str;
//}
//bool file_copy(const std::string str1) {
//	bool ans = true;
//	std::string str2 = rename_new(str1), st;
//
//	std::ifstream fin(str1);
//	if (fin)
//	{
//		std::ofstream fout(str2);
//		for (int i = 0; getline(fin, st); i++) {
//			fout << st << "\n";
//		}
//		fout.close();
//		fin.close();
//	}
//	else {
//		ans = false;
//	}
//	return ans;
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	int choise;
//
//	while (true) {
//		std::cout << "��� �� ������ ���������?\n";
//		std::cout << "1 - ������� ���������� �����\n2 - ������� �������� �����\n";
//		std::cout << "3 - ������� ������������ �����\n4 - ������� �������� ����� �����\n";
//		std::cout << "5 - ������������� ����\n6 - ������� ����� �����\n7 - �����\n";
//		std::cout << "������� ����� ������� ��� ����������: " << std::endl; std::cin >> choise;
//		std::cin.get();
//
//		switch (choise){
//		case 1: {
//			std::string str;
//			std::cout << "������� ������������ �����: \n";
//			std::getline(std::cin, str);
//			system("cls");
//			std::cout << "����: " << str << std::endl;
//			str = file_format(str);
//			std::cout << "����������: " << str << std::endl << std::endl;
//			break;
//		}
//		case 2: {
//			std::string str;
//			std::cout << "������� ������������ �����: \n";
//			std::getline(std::cin, str);
//			system("cls");
//			std::cout << "����: " << str << std::endl;
//			str = file_name(str);
//			std::cout << "��������: " << str << std::endl << std::endl;
//			break;
//		}
//		case 3: {
//			std::string str;
//			std::cout << "������� ������������ �����: \n";
//			std::getline(std::cin, str);
//			system("cls");
//			std::cout << "����: " << str << std::endl;
//			str = file_path(str);
//			if (str.size() == 0) {
//				std::cout << "���� ���������� ����� �� �����\n\n";
//			}
//			std::cout << "������������: " << str << std::endl << std::endl;
//			break;
//		}
//		case 4: {
//			std::string str;
//			std::cout << "������� ������������ �����: \n";
//			std::getline(std::cin, str);
//			system("cls");
//			std::cout << "����: " << str << std::endl;
//			str = file_disk(str);
//			std::cout << "�������� �����: " << str << std::endl << std::endl;
//			break;
//		}
//		case 5: {
//			std::string str, ans;
//			std::cout << "������� ������������ �����: \n";
//			std::getline(std::cin, str);
//			ans = str;
//			system("cls");
//			str = file_rename(str);
//			std::cout << "������ �������� �����: " << ans << std::endl;
//			std::cout << "����� �������� �����: " << str << std::endl << std::endl;
//			break;
//		}
//		case 6: {
//			std::string str1;
//			std::cout << "������� ������������ �����: \n";
//			getline(std::cin, str1);
//			system("cls");
//			std::cout << str1 << std::endl;
//			if (!file_copy(str1)) {
//				std::cout << "�� ������� ������� ���� � ����� ���������\n" << std::endl;
//			}
//			else {
//				std::cout << "���� ������� ����������\n" << std::endl;
//			}
//			break;
//		}
//		case 7: {
//			return 0;
//		}
//		default:
//			std::cout << "\n������������ ��������\n";
//			continue;
//		}
//
//
//	}
//
//
//
//	return 0;
//}