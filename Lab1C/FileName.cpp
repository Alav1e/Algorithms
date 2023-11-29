#include <iostream>

using namespace std;
#include <ctime>

#include "array.h"

void print_data(Array* arr) {
	for (size_t i = 0; i < array_size(arr); i++) {
		cout << array_get(arr, i) << " ";
	}
	cout << endl;
}

Array* random_full() {
	size_t size;
	cin >> size;
	Array* newArray = NULL;
	newArray = array_create(size);
	for (size_t i = 0; i < size; i++) {
		array_set(newArray, i, 1 + rand() % 10);
	}

	return newArray;
}
//
//void bubble_sort(int* arr, int n) {
//	for (size_t i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - i - 1; j++) {
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//		}
//}

Array* delete_elements() {
	Array* newArray = NULL;
	newArray = random_full();

	print_data(newArray);

	int n;
	int m;
	cin >> n;
	cin >> m;

	for (size_t i = 0; i < array_size(newArray); i++) {
		if (array_get(newArray, i) >= n && array_get(newArray, i) <= m) {
			array_set(newArray, i, 0);
		}
	}

	return newArray;
}


void sum_elements() {
	Array* newArray = NULL;
	newArray = random_full();

	print_data(newArray);

	int sum = 0;

	for (size_t i = 0; i < array_size(newArray); i++) {
		if (array_get(newArray, i) % 2 == 0 && array_get(newArray, i) > 0) 
		{
			sum += array_get(newArray, i);
		}
	}

	cout << sum;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//����������������

	cout << "��������� ������" << endl;
	Array* a = NULL;
	a = random_full();
	print_data(a);

	cout << "������� ���������� ��������� �������, ����� �������� �������� ����� �������" << endl;
	Array* b = NULL;
	b = delete_elements();
	print_data(b);

	cout << "������� ���������� ��������� �������, ������� ����� ������" << endl;
	Array* c = NULL;
	sum_elements();
	print_data(c);

	return 0;
}