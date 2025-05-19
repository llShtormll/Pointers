#include<iostream>

using namespace std;

void FillRand(int arr[], int size);
void FillRand(double arr[], int size);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template <typename T> void Print(T arr[], int size);
template <typename T> void Print(T** arr, const int rows, const int cols);
//----------------------------одномерные масивы-------------------
template <typename T> T* push_front(T arr[], int& size, const T value);
template <typename T> T* push_back(T arr[], int& size, const T value);
template <typename T> T* insert(T arr[], int& size,const T value, int index);

template <typename T> T* pop_front(T arr[], int& size);
template <typename T> T* pop_back(T arr[], int& size);
template <typename T> T* erase(T arr[], int& size, int index);
//---------------------------двумерные масивы---------------------
template <typename T> T** push_row_front(T** arr, int& rows, const int cols);
template <typename T> T** push_row_back(T** arr, int& rows, const int cols);
template <typename T> T** insert_row(T** arr, int& rows, int& cols, int index);

template <typename T> T** push_col_front(T** arr, const int rows, int& cols);
template <typename T> T** push_col_back(T** arr, const int rows, int& cols);
template <typename T> T** insert_col(T** arr, const int rows, int& cols, int index);

template <typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T> T** erase_row(T** arr, int& rows, const int cols, int index);

template <typename T> T** pop_col_front(T** arr, const int rows, int& cols);
template <typename T> T** pop_col_back(T** arr, const int rows, int& cols);
template <typename T> T** erase_col(T** arr, const int rows, int& cols, int index);

template <typename T> void Allocate(T** &arr, const int rows, const int cols);
template <typename T> void Clear(T** &arr, const int rows);

#define tab "\t"
#define STATIX_ARRYAS
#define DINAMYC_ARRYAS
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef STATIX_ARRYAS
	int size;
	int index = 3;
	double volue = 4.5;
	cout << "Введие количество элементов масива :"; cin >> size;
	double* arr = new double[size];
	FillRand(arr, size);
	Print(arr, size);
	Print(arr = push_front(arr, size, volue), size);
	Print(arr = push_back(arr, size, volue), size);
	Print(arr = insert(arr, size, volue, index), size);
	Print(arr = pop_front(arr, size), size);
	Print(arr = pop_back(arr, size), size);
	Print(arr = erase(arr, size, index), size);
#endif // STATIX_ARRYAS
#ifdef DINAMYC_ARRYAS
	int rows;
	int cols;
	int i_index_2 = 2;
	double** i_arr_2;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "\nВведие количество элементов строки :"; cin >> cols;

	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//Print(arr = push_row_front(arr, rows, cols), rows, cols);
	//Print(arr = push_row_back(arr, rows, cols), rows, cols);
	//Print(arr = insert_row(arr, rows, cols, index), rows, cols);
	//Print(arr = push_col_front(arr, rows, cols), rows, cols);
	//Print(arr = push_col_back(arr, rows, cols), rows, cols);
	//Print(arr = insert_col(arr, rows, cols, index), rows, cols);
	//Print(arr = pop_row_front(arr, rows, cols), rows, cols);
	//Print(arr = pop_row_back(arr, rows, cols), rows, cols);
	//Print(arr = erase_row(arr, rows, cols, index), rows, cols);
	//Print(arr = pop_col_front(arr, rows, cols), rows, cols);
	//Print(arr = pop_col_back(arr, rows, cols), rows, cols);
	Print(arr = erase_col(arr, rows, cols, index), rows, cols);
	Clear(arr, rows);
#endif // DINAMYC_ARRYAS

}

void FillRand(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}void FillRand(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
		arr[i] /= 100;
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
}void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
			arr[i][j] /= 100;
		}
	}
}
template<typename T> void Print(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << tab;
	}cout << endl;
}
template <typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}cout << endl;
	}cout << endl;
}
//----------------------------одномерные масивы-------------------
template <typename T> T* push_front(T arr[], int& size, const T value)
{
	T* buffer = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	size++;
	return buffer;
}
template <typename T> T* push_back(T arr[], int& size, const T value)
{
	T* buffer = new T[++size];
	for (int i = 0; i < size - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[size] = value;
	return buffer;
}
template <typename T> T* insert(T arr[], int& size, const T value, int index)
{
	T* buffer = new T[size + 1];
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
template <typename T> T* pop_front(T arr[], int& size)
{
	T* buffer = new T[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	size--;
	return buffer;
}
template <typename T> T* pop_back(T arr[], int& size)
{
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
template <typename T> T* erase(T arr[], int& size, int index)
{
	T* buffer = new T[size];
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

//---------------------------двумерные масивы---------------------

template <typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [++rows];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new T[cols] {};
	return buffer;
}
template <typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template <typename T> T** insert_row(T** arr, int& rows, int& cols, int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new T[cols] {};
	rows++;
	return buffer;
}



template <typename T> T** push_col_front(T** arr, const int rows,  int& cols)
{
	T** buffer;
	cols++;
	Allocate(buffer, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		} 
		buffer[i][0] = rand();
		buffer[i][0] /= 100;
	}
		Clear(arr, rows);
	return buffer;
}
template <typename T> T** push_col_back(T** arr, const int rows, int& cols)
{
	T** buffer;
	cols++;
	Allocate(buffer, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		buffer[i][cols - 1] = rand();
		buffer[i][cols - 1] /= 100;
	}
	Clear(arr, rows);
	return buffer;
}
template <typename T> T** insert_col(T** arr, const int rows, int& cols, int index)
{
	T** buffer;
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



template <typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}
template <typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	rows--;
	return buffer;
}
template <typename T> T** erase_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows];
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



template <typename T> T** pop_col_front(T** arr, const int rows, int& cols)
{
	T** buffer;
	Allocate(buffer, rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	Clear(arr, rows);
	return buffer;
}
template <typename T> T** pop_col_back(T** arr, const int rows, int& cols)
{
	T** buffer;
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
template <typename T> T** erase_col(T** arr, const int rows, int& cols, int index)
{
	T** buffer;
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

template <typename T> void Allocate(T** &arr, const int rows, const int cols)
{
	arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
}
template <typename T> void Clear(T** &arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}delete arr;
}