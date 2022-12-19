#include<iostream>
#include<string>
#include<sstream>
#include<map>

int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	std::map<std::string, int> words;
	std::string str;
	int count = 0;

	while (true) {
		std::cout << "1 - Ввод текста\n2 - Вывод процентного соотношения слов\n3 - выход\nВведите команду: ";
		std::cin >> choise; std::cin.get();
		switch (choise) {
		case 1: {
			system("cls");
			std::cout << "Введите строку: ";
			std::getline(std::cin, str); 

			std::istringstream text(str);
			std::string w;
			while (std::getline(text, w, ' ')) {
				count++;
				w = w.c_str();
				if (words.find(w) == words.end()) {
					words.insert(std::pair<std::string, int>(w, 1));
				}
				else {
					words[w]++;
				}
			}
			break;
		}
		case 2: {
			system("cls");
			for (auto word : words) {
				std::cout << word.first << ": " << word.second << ", " << (word.second / (double)count) * 100 << "%\n";
			}
			break;
		}
		case 3: {
			return 0;
		}
		default:
			system("cls");
			std::cout << "Неверная команда\n";
			continue;
		}
	}
}