#include<iostream>
#include<ctime>

//заполнения массивов случайными элементами
int* fullarrnum(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
	return arr;
}
char* fullarrchar(char* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 26) + 97;
	}
	return arr;
}

//сортировки чисел/буквенных символов
int* bubblesort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int k;
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}

		}
	}
	return arr;
}
void charsort(char* arr, int n) {
	int countchar[26]{ 0 };
	for (int i = 0; i < n; i++) {
		int j = arr[i] - 'a';
		countchar[j]++;
	}
	int i = 0;
	for (int j = 0; j < 26;) {
		if (countchar[j] > 0) {
			arr[i] = char(int('a') + j);
			i++;
			countchar[j]--;
		}
		else {
			j++;
		}
	}
}
int* merge(int* arr, int first, int last) {
	//задаются позиции для отсчета массивов
	int middle, start, stop;
	middle = (first + last) / 2; //средний элемент
	start = first; //начало первого массива
	stop = middle + 1; //начало второго массива
	int* mas = new int[1001];

	for (int j = first; j <= last; j++) {
		//(точка позиции первого массива не перешла за его конец) И
		//((точка позиции второго массива перешла за конец) ИЛИ (значение в точке, в первом массиве меньше чем во втором))
		if ((start <= middle) and ((stop > last) or (arr[start] < arr[stop]))) {
			//добавление элемента из первого массива
			mas[j] = arr[start];
			start++;
		}
		else {
			//добавление элемента из второго массива
			mas[j] = arr[stop];
			stop++;
		}
	}

	//переносим массив mas в исходный, после удаляем его
	for (int j = first; j <= last; j++) {
		arr[j] = mas[j];
	}
	delete[]mas;
	return arr;
}
int* mergesort(int* arr, int first, int last) {
	if (first < last) {
		mergesort(arr, first, (first + last) / 2); //сортировка первого массива
		mergesort(arr, (first + last) / 2 + 1, last); //сортировка второго массива
		merge(arr, first, last); //слияние массивов
	}
	return arr;
}

//начало главной функции
int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	while (true) {
		//Меню выбора команды
		std::cout << "Что вы хотите выполнить?\n";
		std::cout << "1 - числовой массив, пузырьковая сортировка" << std::endl << "2 - символьный массив, сортировка подсчетом"
			<< std::endl << "3 - числовой массив, сортировка слиянием" << std::endl << "4 - Выйти, закончить" << std::endl;
		std::cout << "Введите номер команды для выполнения: " << std::endl; std::cin >> choise;

		//Команды для выполнения
		switch (choise) {
			//Сортировка чисел пузырьковым методом
		case 1: {
			//создание пустого массива
			std::cout << "\nВедите желаемое кол-во чисел: ";
			int n; std::cin >> n;
			int arr[1000]{};

			//заполнение(и вывод) массива
			std::cout << "Заполнить массив самостоятельно или случайными числами? \n1 - самостоятельно\nлюбое другое число - заполнить случайными числами\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 0; i < n; i++) {
					std::cout << i + 1 << " элемент > "; std::cin >> arr[i];
				}
				std::cout << "Хотите увидеть массив введенных чисел?";
			}
			else {
				fullarrnum(arr, n);
				std::cout << "Хотите увидеть созданный массив случайных чисел?";
			}

			std::cout << std::endl << "1 - Да, вывести массив\nлюбое другое число - нет, не нужно\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Созданный массив: \n";
				for (int i = 0; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//Сортировка и вывод массива
			std::cout << "Отсортированный масссив: \n";
			bubblesort(arr, n);
			for (int i = 0; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "Создание и сортировка массива выполнены\n" << std::endl;
			break;
		}
			  //Сортировка буквенных символов методом перебора
		case 2: {
			//Создание пустого массива
			std::cout << "\nВедите желаемое кол-во буквенных символов: ";
			int n; std::cin >> n;
			char arr[1000];

			//заполнение (и вывод) массива случайными буквенными символами
			std::cout << "Заполнить массив самостоятельно или случайными буквенными символами? \n1 - самостоятельно\nлюбое другое число - заполнить случайными числами\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 0; i < n; i++) {
					std::cout << i + 1 << " элемент > "; std::cin >> arr[i];
				}
				std::cout << "Хотите увидеть массив введенных буквенных символов?";
			}
			else {
				fullarrchar(arr, n);
				std::cout << "Хотите увидеть созданный массив случайных буквенных символов?";
			}


			fullarrchar(arr, n);
			std::cout << std::endl <<
				"1 - Да, вывести массив\nлюбое другое число - нет, не нужно\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Созданный массив:\n";
				for (int i = 0; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//Сортировка и вывод массива
			std::cout << "Отсортированный масссив: \n";
			charsort(arr, n);
			for (int i = 0; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "Создание и сортировка массива выполнены\n" << std::endl;
			break;
		}
			  //Сортировка чисел методом слияния
		case 3: {
			//создание массива и его заполнение
			int n;
			int arr[1001]{ 0 };
			std::cout << "\nВедите размер массива: " << std::endl;
			std::cin >> n;
			std::cout << "Заполнить массив самостоятельно или случайными числами? \n1 - самостоятельно\nлюбое другое число - заполнить случайными числами\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 1; i <= n; i++) {
					std::cout << i << " элемент > "; std::cin >> arr[i];
				}
				std::cout << "Хотите увидеть массив введенных чисел?";
			}
			else {
				fullarrnum(arr, n);
				std::cout << "Хотите увидеть созданный массив случайных чисел?";
			}

			//вывод массива чисел
			std::cout << std::endl <<
				"1 - да, вывести массив\nлюбое другое число - нет, не нужно\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Созданный массив:\n";
				for (int i = 1; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//сортировка массива и его удаление после вывода
			mergesort(arr, 1, n - 1); // 1 ставится чтобы упростить работу с делением на 2(для нахождения где нужно делить массив пополам)
			std::cout << "Отсортированный массив: \n";
			for (int i = 1; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "Создание и сортировка массова выполнены\n" << std::endl;
			break;
		}
			  //Завершение программы
		case 4: {
			return 0;
		}
		default:
			std::cout << "\nНеправильное действие\n";
			continue;
		}
	}
}
