#include <iostream>

int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int i, j, lensub = strlen(substring), lenst = strlen(str_for_search_in);

	for (i = 0; i <= lenst - lensub; i++)
	{
		for (j = 0; j < lensub && str_for_search_in[i + j] == substring[j]; j++);

		if (j == lensub)
			if (start_position - 1) start_position--;
			else return i;
	}
	return -1;
}

int* find_substring2(const char* str_for_search_in, const char* substring) {
	int *arr = new int[256];
	for (int i = 0; i < 256; i++) {
		arr[i] = 300;
	}
	int n = 0, k = 0;

	for (int i = 1; n != -1; i++)
	{
		n = find_substring1(str_for_search_in, substring,i);
		if (n >= 0) {
			arr[k] = n;
			k++;
		}
	}
	return arr;
}

bool Palindrom(char* str){
	bool flag = true;
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		while (str[i] == ' ') {
			i++;
		}
		while (str[j] == ' ') {
			j--;
		}
		if (tolower(str[i]) != tolower(str[j])) {
			flag = false;
			break;
		}
	}
	return flag;
}

void encrypt(char* str_for_encrypt, int key) {
	int m;
	for (int i = 0; i < strlen(str_for_encrypt); i++) {
		m = (int)str_for_encrypt[i];
		if (90 <= m and m <= 122) {
			m += (key % 26);
			if (m > 122) m -= 26;
			str_for_encrypt[i] = (char)m;
		}
		else if (65 <= m and m <= 90) {
			m += (key % 26);
			if (m > 90) m -= 26;
			str_for_encrypt[i] = (char)m;
		}
	}
}

void text(char* str, int& k, int& ans) {
	char mas[512];
	bool flag = true;
	k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '\"') {
			char arr[256];
			int m = 0;

			i++;
			arr[m] = str[i];
			m++;
			while (str[i] != '\"') {
				i++;
				if (str[i] != '\"') {
					arr[m] = str[i];
					m++;
				}
				if (i >= strlen(str)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = k, f = 0; j < k + m; j++, f++) {
					mas[j] = arr[f];
				}
				k += m;
				mas[k] = '\n';
				k++;
				ans = 1;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		str[i] = mas[i];
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;
	const int SIZE = 256;

	while (true) {
		std::cout << "Что вы хотите выполнить?\n";
		std::cout << "1 - проверка на пандром\n2 - поиск подстроки в строке\n";
		std::cout << "3 - шифрование сдвигами (шифр Цезаря)\n";
		std::cout << "4 - вывести все названия (то, что внутри кавычек)\n5 - выход\n";
		std::cout << "Введите номер команды для выполнения: " << std::endl; std::cin >> choise;
		std::cin.get();
		switch (choise) {
		case 1: {
			//ввод строки
			char str[SIZE];
			std::cout << "Пожалуйста введите строку:\n";
			std::cin.getline(str, SIZE);

			//проверка строки на палиндром
			int i = Palindrom(str);
			system("cls");
			if (i) {
				std::cout << "Cтрока является палиндромом\n\n";
			}
			else {
				std::cout << "Cтрока не является палиндромом\n\n";
			}
			break;
		}
		case 2: {
			char str_for_search_in[SIZE], substring[SIZE];
			std::cout << "Введите строку: ";
			std::cin.getline(str_for_search_in, SIZE);
			std::cout << "Введите подстроку: ";
			std::cin.getline(substring, SIZE);
			system("cls");
			
			int k = 0;

			int *mas = find_substring2(str_for_search_in, substring);
			if (mas[0] == 300) {
				std::cout << "Подстрок не найдено\n";
			}
			else {
				for (int i = 0; i < 300; i++) {
					if (mas[i] == 300) {
						break;
					}
					std::cout << mas[i] << " ";
				}
			}
			std::cout << std::endl;
			delete[]mas;
			break;
		}
		case 3: {
			int key = 0;
			char str_for_encrypt[SIZE];
			
			std::cout << "Введите строку: \n";
			std::cin.getline(str_for_encrypt, SIZE);
			std::cout << "Введите ключ: \n";
			std::cin >> key; std::cin.get();
			system("cls");

			std::cout << "Введенная строка: \n";
			for (int i = 0; i < strlen(str_for_encrypt); i++) {
				std::cout << str_for_encrypt[i];
			}

			encrypt(str_for_encrypt, key);
			std::cout << "\nЗашифрованная строка\n";
			for (int i = 0; i < strlen(str_for_encrypt); i++) {
				std::cout << str_for_encrypt[i];
			}
			std::cout << std::endl;
			break;
		}
		case 4: {
			char str[SIZE * 2];
			int n; int ans = 0;

			std::cout << "Введите строку: ";
			std::cin.getline(str, SIZE);

			text(str, n, ans);
			system("cls");
			if (ans == 0) {
				std::cout << "Нет символов в кавычках\n" << std::endl;
			}
			else {
				std::cout << "Строки в кавычках: \n";
				for (int i = 0; i < n; i++) {
					std::cout << str[i];
				}
			}
			break;
		}
		case 5: {
			return 0;
		}
		default:
			std::cout << "\nНеправильное действие\n";
			continue;
		}
	}
}