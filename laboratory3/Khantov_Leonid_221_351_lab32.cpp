//#include<iostream>
//#include<ctime>
//
////заполнение числами
//void fullarrnum(int* arr, int n) {
//	srand(time(NULL));
//	for (int i = 0; i < n; i++) {
//		arr[i] = rand();
//	}
//}
//int evenodd(int num) {
//	//находение суммы цифр на четных местах
//	int oddSum = 0, evenSum = 0, count = 1;
//	while (num != 0) {
//		if (count % 2 == 0) {
//			evenSum += num % 10;
//			num /= 10;
//		}
//		else {
//			oddSum += num % 10;
//			num /= 10;
//		}
//		count++;
//	}
//
//	if (count % 2 == 0) {
//		int k = oddSum;
//		oddSum = evenSum;
//		evenSum = k;
//	}
//	return oddSum;
//}
//
////ввод и вывод массова
//int* arrinput(int *arr, int *pn) {
//	std::cout << "Ведите размер массива: ";
//	std::cin >> (*pn);
//	delete[]arr;
//	int* mas = new int[*pn];
//	std::cout << "Заполнить массив самостоятельно или случайными числами?\n";
//	std::cout << "1 - случайные числа\nлюбое другое число - самостоятельно\n";
//	int ans; std::cin >> ans; std::cout << std::endl;
//	
//	if (ans == 1) {
//		fullarrnum(mas, *pn);
//	}
//	else {
//		for (int i = 0; i < *pn; i++) {
//			std::cout << i + 1 << " элемент > "; std::cin >> mas[i];
//		}
//		std::cout << std::endl;
//	}
//	system("cls");
//	return mas;
//}
//void arrout(int* arr, int n) {
//	for (int i = 0; i < n; i++) {
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
////вспомогательные сортировки
//void bubblesort(int* arr, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int k;
//				k = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = k;
//			}
//		}
//	}
//}
//void reversesort(int* arr, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (arr[j] < arr[j + 1]) {
//				int k;
//				k = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = k;
//			}
//		}
//	}
//}
//
////основные сортировки
//void evenplaces(int* arr, int n) {
//	//заранее сортируем масив, когда будут одинаковые суммы, числа все равно будут отсортированы
//	bubblesort(arr, n);
//	//создание массива, в котором будут храниться суммы
//	int* mas = new int[n];
//	for (int i = 0; i < n; i++) {
//		mas[i] = evenodd(arr[i]);
//	}
//	//сортировка
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (mas[j] > mas[j + 1]) {
//				int k;
//				k = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = k;
//				int m;
//				m = mas[j];
//				mas[j] = mas[j + 1];
//				mas[j + 1] = m;
//			}
//		}
//	}
//	delete[]mas;
//}
//void lastnum(int* arr, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if ((arr[j] % 10) > (arr[j + 1] % 10)) {
//				int k;
//				k = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = k;
//			}
//		}
//	}
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	int choise = 0;
//
//	//создание и заполнение первого массива
//	int n = 1;
//	int* pn = &n;
//	int* arr = new int[n];
//	arr = arrinput(arr, pn);
//
//	while (true) {
//		//меню выбора команды
//		std::cout << "Что вы хотите выполнить?\n";
//		std::cout << "1 - Ввод массива\n2 - Вывод массива в консоль\n";
//		std::cout << "3 - Сортровка по сумме цифр, стоящих на четных местах\n";
//		std::cout << "4 - Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию\n5 - выход\n";
//		std::cout << "Введите номер команды для выполнения: " << std::endl; std::cin >> choise;
//		switch (choise) {
//		case 1: {
//			arr = arrinput(arr, pn);
//			break;
//		}
//		case 2: {
//			system("cls");
//			std::cout << "Массив: \n";
//			arrout(arr, n);
//			std::cout << std::endl;
//			break;
//		}
//		case 3: {
//			system("cls");
//			evenplaces(arr, n);
//			std::cout << "Сортировка выполнена\n\n";
//			break;
//		}
//		case 4: {
//			system("cls");
//			reversesort(arr, n);
//			lastnum(arr, n);
//			std::cout << "Сортировка выполнена\n\n";
//			break;
//		}
//		case 5: {
//			delete[]arr;
//			return 0;
//		}
//		default:
//			std::cout << "\nНеправильное действие\n";
//			continue;
//		}
//	}
//}