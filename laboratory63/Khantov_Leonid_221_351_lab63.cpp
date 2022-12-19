#include<iostream>
#include<queue>

int min(int a, int b, int c) {
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

}

void chisla235() {
	std::cout << "Введите кол-во чисел: "; int n; std::cin >> n;
	std::queue<int> qu2, qu3, qu5;
	qu2.push(2); qu3.push(3); qu5.push(5);
	for (int i = 0; i < n; i++) {
		int mini = min(qu2.front(), qu3.front(), qu5.front());
		std::cout << mini << " ";
		qu2.push(mini * 2); qu3.push(mini * 3); qu5.push(mini * 5);
		if (qu2.front() == mini) { qu2.pop(); }
		if (qu3.front() == mini) { qu3.pop(); }
		if (qu5.front() == mini) { qu5.pop(); }
	}
	std::cout << std::endl;
}


int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	while (true) {
		std::cout << "1 - выполнить программу\n2 - выход\nВведите команду: ";
		std::cin >> choise; std::cin.get();
		switch (choise) {
		case 1: {
			system("cls");
			chisla235();
			break;
		}
		case 2: {
			return 0;
		}
		default:
			system("cls");
			std::cout << "Неверная команда\n";
			continue;
		}
	}
}