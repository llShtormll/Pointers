#include<iostream>

using namespace std;

void FillRand(int arr[], int size);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], int size);
void Print(int** arr, const int rows, const int cols);

int* push_front(int arr[], int& size, const int value);
int* push_back(int arr[], int& size, const int value);
int* insert(int arr[], int& size,const int value, int index);

int* pop_front(int arr[], int& size);
int* pop_back(int arr[], int& size);
int* erase(int arr[], int& size, int index);

int** push_row_front(int** arr, int& rows, const int cols);
int** push_row_back(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, int& cols, int index);

int** push_col_front(int** arr, const int rows, int& cols);
int** push_col_back(int** arr, const int rows, int& cols);
int** insert_col(int** arr, const int rows, int& cols, int index);

int** pop_row_front(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

int** pop_col_front(int** arr, const int rows, int& cols);
int** pop_col_back(int** arr, const int rows, int& cols);
int** erase_col(int** arr, const int rows, int& cols, int index);

void Allocate(int** &arr, const int rows, const int cols);
void Clear(int** &arr, const int rows);

#define tab "\t"
//#define STATIX_ARRYAS
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef STATIX_ARRYAS
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
#endif // STATIX_ARRYAS
	int rows;
	int cols;
	int index = 2;
	int** arr;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "\nВведие количество элементов строки :"; cin >> cols;

	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//Print(arr = push_row_front(arr, rows, cols), rows, cols);
	//Print(arr = push_row_back(arr, rows, cols), rows, cols);
	//Print(arr = insert_row(arr, rows, cols,index), rows, cols);
	//Print(arr = push_col_front(arr, rows, cols), rows, cols);
	//Print(arr = push_col_back(arr, rows, cols), rows, cols);
	//Print(arr = insert_col(arr, rows, cols,index), rows, cols);
	//Print(arr = pop_row_front(arr, rows, cols), rows, cols);
	//Print(arr = pop_row_back(arr, rows, cols), rows, cols);
	//Print(arr = erase_row(arr, rows, cols, index), rows, cols);
	//Print(arr = pop_col_front(arr, rows, cols), rows, cols);
	//Print(arr = pop_col_back(arr, rows, cols), rows, cols);
	//Print(arr = erase_col(arr, rows, cols,index), rows, cols);
	Clear(arr, rows);
}

void FillRand(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << tab;
	}cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}cout << endl;
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



int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

int** push_col_front(int** arr, const int rows,  int& cols)
{
	int** buffer;
	cols++;
	Allocate(buffer, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		} 
		buffer[i][0] = rand() % 100;
	}
		Clear(arr, rows);
	return buffer;
}
int** push_col_back(int** arr, const int rows, int& cols)
{
	int** buffer;
	cols++;
	Allocate(buffer, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		buffer[i][cols - 1] = rand() % 100;
	}
	Clear(arr, rows);
	return buffer;
}
int** insert_col(int** arr, const int rows, int& cols, int index)
{
	int** buffer;
	cols++;
	Allocate(buffer, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		buffer[i][index] = rand() % 100;
	}
	Clear(arr, rows);
	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	rows--;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}

int** pop_col_front(int** arr, const int rows, int& cols)
{
	int** buffer;
	Allocate(buffer, rows, cols - 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			buffer[i][j - 1] = arr[i][j];
		}
	}
	Clear(arr, rows);
	cols--;
	return buffer;
}
int** pop_col_back(int** arr, const int rows, int& cols)
{
	int** buffer;
	Allocate(buffer, rows, cols - 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	cols--;
	return buffer;
}
int** erase_col(int** arr, const int rows, int& cols, int index)
{
	int** buffer;
	Allocate(buffer, rows, cols - 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	Clear(arr, rows);
	cols--;
	return buffer;
}

void Allocate(int** &arr, const int rows, const int cols)
{
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}
void Clear(int** &arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}delete arr;
}