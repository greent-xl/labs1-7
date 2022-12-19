#include<iostream>

void task1(int n) {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= i - 1; j++) {
			std::cout << j;
		}
		std::cout << std::endl;
	}
}

void task2(int n) {
	long double c = n;
	for (int k = 1; k <= n; k++) {
		std::cout << c << " ";
		c *= (n - k);
		c /= (k + 1);
	}
	std::cout << std::endl;
}

void task3() {
	int s = 0, k = 0, n; std::cin >> n;
	while (n != 0) {
		s += n;
		k++;
		std::cin >> n;
	}
	std::cout << (double)s / k << std::endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	while (true) {
		std::cout << "Что вы хотите выполнить?\n";
		std::cout << "1.задание 1\n2.задание 2\n3.задание 3\n4.задание 4\n";
		std::cin >> choice;
		switch (choice){
			case 1:{
				int n; std::cin >> n;
				task1(n);
				break;
			}
			case 2: {
				int n; std::cin >> n;
				task2(n);
				break;
			}
			case 3: {
				task3();
				break;
			}
			case 4: {
				return 0;
			}
			default:{
				continue;
			}
		}
	}
}