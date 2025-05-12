#include<iostream>

using namespace std;
void FillRand(int arr[], int size);
void Print(int arr[], int size);

int* push_front(int arr[], int& size, const int value);
int* push_back(int arr[], int& size, const int value);
int* insert(int arr[], int& size,const int value, int index);

int* pop_front(int arr[], int& size);
int* pop_back(int arr[], int& size);
int* erase(int arr[], int& size, int index);

#define tab "\t"
//#define STATICS_ARRYAS
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef STATICS_ARRYAS
	int size;
	cout << "Введие количество элементов масива :"; cin >> size;
	int* arr = new int[size];
	FillRand(arr, size);
	Print(arr, size);
	arr = push_front(arr, size, 10);
	Print(arr, size);
	arr = push_back(arr, size, 10);
	Print(arr, size);
	arr = insert(arr, size, 10, 3);
	Print(arr, size);
	arr = pop_front(arr, size);
	Print(arr, size);
	arr = pop_back(arr, size);
	Print(arr, size);
	arr = erase(arr, size, 2);
	Print(arr, size);
#endif // STATICS_ARRYAS
	int rows;
	int cols;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "\nВведие количество элементов строки :"; cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

}

void FillRand(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << tab;
	}cout << endl;
}
int* push_front(int arr[], int& size, const int value)
{
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	size++;
	return buffer;
}
int* push_back(int arr[], int& size, const int value)
{
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[size] = value;
	size++;
	return buffer;
}
int* insert(int arr[], int& size, const int value, int index)
{
	int* buffer = new int[size + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < size; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = value;
	size++;
	return buffer;
}
int* pop_front(int arr[], int& size)
{
	int* buffer = new int[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	size--;
	return buffer;
}
int* pop_back(int arr[], int& size)
{
	int* buffer = new int[--size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& size, int index)
{
	int* buffer = new int[size];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < size; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	size--;
	return buffer;
}