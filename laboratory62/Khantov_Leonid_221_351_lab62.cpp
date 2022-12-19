#include<iostream>
#include<deque>
#include<string>

void palindrom() {
	std::deque<char> deque;
	std::string s;
	bool ans = true;
	std::cout << "Введите строку: "; std::getline(std::cin, s);
	for (char ch : s) {
		deque.push_front(ch);
	}
	int mid = deque.size() / 2;
	for (int i = 0; i < mid; i++) {
		if (deque.front() != deque.back()) { ans = false; }
	}
	ans ? std::cout << "Является палиндромом\n" : std::cout << "Не является палиндромом\n";
}

struct Position{ int x; int y; };
int rotate(Position A, Position B, Position C) {
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

void sort(std::deque<int>& P, Position *pos) {
	int t, j;
	for (int i = 2; i < P.size(); i++) {
		j = i;
		while (j > 1 and rotate(pos[P[0]], pos[P[j - 1]], pos[P[j]]) < 0) {
			t = P[j];
			P[j] = P[j - 1];
			P[j - 1] = t;
			j--;
		}
	}
}

void grehem() {
	int n;
	std::cout << "Введите кол-во точек: "; std::cin >> n;
	Position *pos = new Position[n];
	std::deque<int> P, S;
	std::cout << "Введите координаты точек:\n";
	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << " точка\n";
		std::cout << "x = "; std::cin >> pos[i].x;
		std::cout << "y = "; std::cin >> pos[i].y;
	}
	int min = 0;
	for (int i = 1; i < n; i++) {
		if (pos[i].x < pos[min].x) { min = i; }
	}
	P.push_front(min);
	for (int i = 0; i < n; i++) {
		if (i != min) { P.push_back(i); }
	}
	sort(P, pos);
	S.push_back(P[0]);
	S.push_back(P[1]);
	for (int i = 2; i < P.size(); i++) {
		while (rotate(pos[S[S.size() - 2]], pos[S[S.size() - 1]], pos[P[i]]) < 0) { S.pop_back(); }
		S.push_back(P[i]);
	}
	for (auto x : S) {
		std::cout << "x = " << pos[x].x << ", y = " << pos[x].y << "\n";
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	while (true) {
		std::cout << "1 - проверка на палиндром\n2 - алгоритм Грэхема\n3 - выход\nВведите команду: ";
		std::cin >> choise; std::cin.get();
		switch (choise) {
		case 1: {
			system("cls");
			palindrom();
			break;
		}
		case 2: {
			system("cls");
			grehem();
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