//#include <iostream>
//#include <cstring>
//#include <vector>
//
//using std::distance;
//using std::string;
//using std::vector;
//using std::cout;
//using std::cin;
//using std::endl;
//
//struct surage{
//	string Surname;
//	int Age;
//};
//std::ostream& operator << (std::ostream& out, surage& st) {
//	out << st.Surname << " " << st.Age;
//	return out;
//}
//std::istream& operator >> (std::istream& in, surage& st) {
//	in >> st.Surname >> st.Age;
//	return in;
//}
//
//struct slave{
//	string surname;
//	string firstname;
//	int age;
//};
//std::ostream& operator << (std::ostream& out, slave& st) {
//	out << st.surname << " " << st.firstname << " " << st.age;
//	return out;
//}
//std::istream& operator >> (std::istream& in, slave& st) {
//	in >> st.surname >> st.firstname >> st.age;
//	return in;
//}
//
//template <typename T>
//vector<T> input(int count) {
//	vector<T> vec;
//	T val;
//	for (int i = 0; i < count; i++) {
//		cout << i + 1 << " элемент> ";
//		cin >> val;
//		vec.push_back(val);
//	}
//	system("cls");
//	return vec;
//}
//template <typename T>
//void output(vector<T> vec) {
//	cout << typeid(T).name() << endl;
//	for (T elem : vec) {
//		cout << elem << endl;
//	}
//}
//
//template <typename T>
//bool comp(T l, T r) {
//	return l < r;
//}
//template <>
//bool comp(slave l, slave r) {
//	if (l.surname < r.surname) return true;
//	else if (l.surname == r.surname) {
//		if (l.firstname < r.firstname) return true;
//		else if (l.firstname == r.firstname) {
//			if (l.age < r.age) return true;
//		}
//	}
//	return false;
//}
//
//template <typename T, typename Iter = typename vector<T>::Iterator>
//vector<T>& quicksort(vector<T>& array, Iter left, Iter right, bool (*flag) (T, T) = comp<T>) {
//	Iter left_new = left, right_new = right;
//	T piv = array.at(distance(array.begin(), right - distance(left, right) / 2));
//	T temp;
//	while (left <= right) {
//		while (flag(*left, piv)) left++;
//		while (flag(piv, *right)) right--;
//		if (left <= right) {
//			temp = *left;
//			*left = *right;
//			*right = temp;
//			left++;
//			right--;
//		}
//	}
//	if (left_new < right) array = quicksort<T>(array, left_new, right);
//	if (right_new > left) array = quicksort<T>(array, left, right_new);
//	return array;
//}
//template <typename T>
//void cls(int count) {
//	vector<T> vec;
//	vec = input<T>(count);
//	cout << "Отсортированная последовательность:\n";
//	output(quicksort<T>(vec, vec.begin(), --(vec.end())));
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	int choise;
//	int count = 0;
//
//	while (true) {
//		cout << "Выберите действие:\n"
//			<< "1. Массив int\n"
//			<< "2. Массив double\n"
//			<< "3. Массив char\n"
//			<< "4. Массив bool\n"
//			<< "5. Массив структуры с полями Фамилия, Имя и Возраст\n"
//			<< "6. Выход\n"
//			<< "Ваш выбор: ";
//		cin >> choise;
//
//		switch (choise) {
//		case 1:
//			cout << "Введите количество элементов в массиве: ";
//			cin >> count;
//			cls<int>(count);
//			break;
//		case 2:
//			cout << "Введите количество элементов в массиве: ";
//			cin >> count;
//			cls<double>(count);
//			break;
//		case 3:
//			cout << "Введите количество элементов в массиве: ";
//			cin >> count;
//			cls<char>(count);
//			break;
//		case 4:
//			cout << "Введите количество элементов в массиве: ";
//			cin >> count;
//			cls<bool>(count);
//			break;
//		case 5:
//			cout << "Введите количество элементов в массиве: ";
//			cin >> count;
//			cls<slave>(count);
//			break;
//		case 6:
//			return 0;
//		default:
//			std::cout << "Неправильная команда\n";
//			break;
//		}
//	}
//}