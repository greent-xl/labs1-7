#include<iostream>
#include<stack>
#include<string>
using std::string;

struct my_stack{
private:
	bool check_bracket(char br1, char br2) {
		if (br1 == '(') {
			return br2 == ')';
		}
		else if (br1 == '[') {
			return br2 == ']';
		}
		else if (br1 == '{') {
			return br2 == '}';
		}
		else {
			return false;
		}
	}
public:
	bool check_stack(string str) {
		std::stack<char> stack;
		for (char s : str) {
			if (s == '(' or s == '[' or s == '{') {
				stack.push(s);
			}
			else if (s == ')' or s == ']' or s == '}') {
				if (!stack.empty() and check_bracket(stack.top(), s)) {
					stack.pop();
				}
				else {
					return false;
				}
			}
		}
		if (stack.empty()) {
			return true;
		}
		else {
			return false;
		}

	}
};

int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;
	string str;

	while (true) {
		std::cout << "1 - ввод строки\n2 - вывод строки\n3 - проверка строки\n4 - выход\nВведите команду: ";
		std::cin >> choise; std::cin.get();
		switch (choise){
		case 1: {
			system("cls");
			std::cout << "Введите строку: \n";
			std::getline(std::cin, str);
			break;
		}
		case 2: {
			system("cls");
			std::cout << "Строка - " << str << std::endl;
			break;
		}
		case 3: {
			system("cls");
			my_stack stack;
			(stack.check_stack(str)) ? std::cout << "Скобки стоят правильно\n" : std::cout << "Скобки стоят неправильно\n";
			break;
		}
		case 4: {
			return 0;
		}
		default:
			system("cls");
			std::cout << "Неверная команда\n";
			continue;
		}
	}
}