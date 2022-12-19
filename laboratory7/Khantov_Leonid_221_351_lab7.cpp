#include <iostream>
#include <cstring>
#include <vector>

using std::distance;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

struct slave {
	string surname;
	string firstname;
	int age;
};
std::ostream& operator << (std::ostream& out, slave& st) {
	out << st.surname << " " << st.firstname << " " << st.age;
	return out;
}
std::istream& operator >> (std::istream& in, slave& st) {
	in >> st.surname >> st.firstname >> st.age;
	return in;
}

template <typename T>
vector<T> input(int count) {
	vector<T> vec;
	T val;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << " элемент> ";
		cin >> val;
		vec.push_back(val);
	}
	system("cls");
	return vec;
}
template <typename T>
void print(vector<T> vec) {
	cout << typeid(T).name() << endl;
	for (T elem : vec) {
		cout << elem << endl;
	}
}


template <typename T>
bool comp(T l, T r, int t = 0) {
	return l < r;
}
template<>
bool comp(slave l, slave r, int t) {
	if (t == 1) {
		if (l.surname < r.surname) return true;
	}
	if (t == 2) {
		if (l.firstname< r.firstname) return true;
	}
	if (t == 3) {
		if (l.age < r.age) return true;
	}
	return false;
}

template <typename T, typename Iter = typename vector<T>::Iterator>
vector<T>& quicksort(vector<T>& array, Iter left, Iter right, int t = 0) {
	//bool(*flag) = comp<T>(T, T, int);
	Iter left_new = left, right_new = right;
	T piv = array.at(distance(array.begin(), right - distance(left, right) / 2));
	T temp;
	while (left <= right) {
		while (comp<T>(*left, piv, t)) left++;
		while (comp<T>(piv, *right, t)) right--;
		if (left <= right) {
			temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;
		}
	}
	if (left_new < right) array = quicksort<T>(array, left_new, right, t);
	if (right_new > left) array = quicksort<T>(array, left, right_new, t);
	return array;
}
template <typename T>
void cls(int count, int t = 0) {
	vector<T> vec;
	vec = input<T>(count);
	cout << "Отсортированная последовательность:\n";
	print(quicksort<T>(vec, vec.begin(), --(vec.end()), t));
}

int main() {
	setlocale(LC_ALL, "ru");
	int choise;
	int count = 0;

	while (true) {
		cout << "Выберите действие:\n"
			<< "1 Массив int\n"
			<< "2 Массив double\n"
			<< "3 Массив char\n"
			<< "4 Массив bool\n"
			<< "5 Сортировка класса по фамилии\n"
			<< "6 Сортировка класса по имени\n"
			<< "7 Сортировка класса по возрасту\n"
			<< "8 Выход\n"
			<< "Ваш выбор: ";
		cin >> choise;

		switch (choise) {
		case 1:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<int>(count);
			break;
		case 2:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<double>(count);
			break;
		case 3:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<char>(count);
			break;
		case 4:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<bool>(count);
			break;
		case 5:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<slave>(count, 1);
			break;
		case 6:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<slave>(count, 2);
			break;
		case 7:
			cout << "Введите количество элементов в массиве: ";
			cin >> count;
			cls<slave>(count, 3);
			break;
		case 8:
			return 0;
		default:
			std::cout << "Неправильная команда\n";
			break;
		}
	}
}