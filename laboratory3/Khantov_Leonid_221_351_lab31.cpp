#include<iostream>
#include<ctime>

//���������� �������� ���������� ����������
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

//���������� �����/��������� ��������
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
	//�������� ������� ��� ������� ��������
	int middle, start, stop;
	middle = (first + last) / 2; //������� �������
	start = first; //������ ������� �������
	stop = middle + 1; //������ ������� �������
	int* mas = new int[1001];

	for (int j = first; j <= last; j++) {
		//(����� ������� ������� ������� �� ������� �� ��� �����) �
		//((����� ������� ������� ������� ������� �� �����) ��� (�������� � �����, � ������ ������� ������ ��� �� ������))
		if ((start <= middle) and ((stop > last) or (arr[start] < arr[stop]))) {
			//���������� �������� �� ������� �������
			mas[j] = arr[start];
			start++;
		}
		else {
			//���������� �������� �� ������� �������
			mas[j] = arr[stop];
			stop++;
		}
	}

	//��������� ������ mas � ��������, ����� ������� ���
	for (int j = first; j <= last; j++) {
		arr[j] = mas[j];
	}
	delete[]mas;
	return arr;
}
int* mergesort(int* arr, int first, int last) {
	if (first < last) {
		mergesort(arr, first, (first + last) / 2); //���������� ������� �������
		mergesort(arr, (first + last) / 2 + 1, last); //���������� ������� �������
		merge(arr, first, last); //������� ��������
	}
	return arr;
}

//������ ������� �������
int main() {
	setlocale(LC_ALL, "ru");
	int choise = 0;

	while (true) {
		//���� ������ �������
		std::cout << "��� �� ������ ���������?\n";
		std::cout << "1 - �������� ������, ����������� ����������" << std::endl << "2 - ���������� ������, ���������� ���������"
			<< std::endl << "3 - �������� ������, ���������� ��������" << std::endl << "4 - �����, ���������" << std::endl;
		std::cout << "������� ����� ������� ��� ����������: " << std::endl; std::cin >> choise;

		//������� ��� ����������
		switch (choise) {
			//���������� ����� ����������� �������
		case 1: {
			//�������� ������� �������
			std::cout << "\n������ �������� ���-�� �����: ";
			int n; std::cin >> n;
			int arr[1000]{};

			//����������(� �����) �������
			std::cout << "��������� ������ �������������� ��� ���������� �������? \n1 - ��������������\n����� ������ ����� - ��������� ���������� �������\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 0; i < n; i++) {
					std::cout << i + 1 << " ������� > "; std::cin >> arr[i];
				}
				std::cout << "������ ������� ������ ��������� �����?";
			}
			else {
				fullarrnum(arr, n);
				std::cout << "������ ������� ��������� ������ ��������� �����?";
			}

			std::cout << std::endl << "1 - ��, ������� ������\n����� ������ ����� - ���, �� �����\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "��������� ������: \n";
				for (int i = 0; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//���������� � ����� �������
			std::cout << "��������������� �������: \n";
			bubblesort(arr, n);
			for (int i = 0; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "�������� � ���������� ������� ���������\n" << std::endl;
			break;
		}
			  //���������� ��������� �������� ������� ��������
		case 2: {
			//�������� ������� �������
			std::cout << "\n������ �������� ���-�� ��������� ��������: ";
			int n; std::cin >> n;
			char arr[1000];

			//���������� (� �����) ������� ���������� ���������� ���������
			std::cout << "��������� ������ �������������� ��� ���������� ���������� ���������? \n1 - ��������������\n����� ������ ����� - ��������� ���������� �������\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 0; i < n; i++) {
					std::cout << i + 1 << " ������� > "; std::cin >> arr[i];
				}
				std::cout << "������ ������� ������ ��������� ��������� ��������?";
			}
			else {
				fullarrchar(arr, n);
				std::cout << "������ ������� ��������� ������ ��������� ��������� ��������?";
			}


			fullarrchar(arr, n);
			std::cout << std::endl <<
				"1 - ��, ������� ������\n����� ������ ����� - ���, �� �����\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "��������� ������:\n";
				for (int i = 0; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//���������� � ����� �������
			std::cout << "��������������� �������: \n";
			charsort(arr, n);
			for (int i = 0; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "�������� � ���������� ������� ���������\n" << std::endl;
			break;
		}
			  //���������� ����� ������� �������
		case 3: {
			//�������� ������� � ��� ����������
			int n;
			int arr[1001]{ 0 };
			std::cout << "\n������ ������ �������: " << std::endl;
			std::cin >> n;
			std::cout << "��������� ������ �������������� ��� ���������� �������? \n1 - ��������������\n����� ������ ����� - ��������� ���������� �������\n";
			int lop; std::cin >> lop;
			if (lop == 1) {
				for (int i = 1; i <= n; i++) {
					std::cout << i << " ������� > "; std::cin >> arr[i];
				}
				std::cout << "������ ������� ������ ��������� �����?";
			}
			else {
				fullarrnum(arr, n);
				std::cout << "������ ������� ��������� ������ ��������� �����?";
			}

			//����� ������� �����
			std::cout << std::endl <<
				"1 - ��, ������� ������\n����� ������ ����� - ���, �� �����\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "��������� ������:\n";
				for (int i = 1; i < n; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}

			//���������� ������� � ��� �������� ����� ������
			mergesort(arr, 1, n - 1); // 1 �������� ����� ��������� ������ � �������� �� 2(��� ���������� ��� ����� ������ ������ �������)
			std::cout << "��������������� ������: \n";
			for (int i = 1; i < n; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl << "�������� � ���������� ������� ���������\n" << std::endl;
			break;
		}
			  //���������� ���������
		case 4: {
			return 0;
		}
		default:
			std::cout << "\n������������ ��������\n";
			continue;
		}
	}
}
