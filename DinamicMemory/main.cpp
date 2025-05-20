#include<iostream>

using namespace std;

void FillRand(int arr[], int size);
void FillRand(double arr[], int size);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template <typename T> void Print(T arr[], const int size);
template <typename T> void Print(T** arr, const int rows, const int cols);
//----------------------------одномерные масивы-------------------
template <typename T> T* push_f_i_b(T* arr, int& size, const T volue, int index = 0, int k = 0);
template <typename T> T* pop_f_e_b(T* arr, int& size, int index = 0, int k = 0);
//---------------------------двумерные масивы---------------------
template <typename T> T** push_row_f_i_b(T** arr, int& rows, const int cols, const int index = 0, int k = 0);
template <typename T> void push_col_f_i_b(T** arr, const int rows, int& cols, const int index = 0, int k = 0);

template <typename T> T** pop_row_f_e_b(T** arr, int& rows, const int cols, const int index = 0, int k = 0);
template <typename T> void pop_col_f_e_b(T** arr, const int rows, int& cols, int index = 0, int k = 0);

template <typename T> void Allocate(T** &arr, const int rows, const int cols);
template <typename T> void Clear(T** &arr, const int rows);

#define tab "\t"
//#define STATIX_ARRYAS
#define DINAMYC_ARRYAS
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef STATIX_ARRYAS
	int size;
	int index = 2;
	double volue = 4.5;
	cout << "Введие количество элементов масива :"; cin >> size;
	double* arr = new double[size];
	FillRand(arr, size);
	Print(arr, size);
	Print(arr = push_f_i_b(arr, size, volue, index), size);
	Print(arr = pop_f_e_b(arr, size, index), size);
#endif // STATIX_ARRYAS
#ifdef DINAMYC_ARRYAS
	int rows;
	int cols;
	int i_index_2 = 2;
	double** i_arr_2;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "\nВведие количество элементов строки :"; cin >> cols;
	Allocate(i_arr_2, rows, cols);
	FillRand(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);
	Print(i_arr_2 = push_row_f_i_b(i_arr_2, rows, cols, i_index_2), rows, cols);
	push_col_f_i_b(i_arr_2, rows, cols, i_index_2);
	Print(i_arr_2, rows, cols);
	Print(i_arr_2 = pop_row_f_e_b(i_arr_2, rows, cols, i_index_2), rows, cols);
	pop_col_f_e_b(i_arr_2, rows, cols, i_index_2);
	Print(i_arr_2, rows, cols);
	Clear(i_arr_2, rows);
#endif // DINAMYC_ARRYAS

}

void FillRand(int arr[], int size){
	for (int i = 0; i < size; i++)arr[i] = rand() % 100;
}
void FillRand(double arr[], int size){
	for (int i = 0; i < size; i++) { arr[i] = rand(); arr[i] /= 100; }
}
void FillRand(int** arr, const int rows, const int cols){
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
	}
}void FillRand(double** arr, const int rows, const int cols){
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) { arr[i][j] = rand(); arr[i][j] /= 100; }
	}
}
template<typename T> void Print(T arr[], int size){
	for (int i = 0; i < size; i++)cout << arr[i] << tab;
	cout << endl;
}
template <typename T> void Print(T** arr, const int rows, const int cols){
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << tab;
		cout << endl;
	}cout << endl;
}
//----------------------------одномерные масивы-------------------
template <typename T> T* push_f_i_b(T* arr, int& size, const T volue, int index, int k){
	cout << "Для добавления элемента в ( начало/по индексу/конец ) нажмите ( 0/1/2 ) :"; cin >> k;
	T* buffer = new T[size + 1];
	switch (k)
	{
	case 0:	for (int i = 0; i < size; i++)buffer[i + 1] = arr[i];
		buffer[0] = volue;
		break;
	case 1:	for (int i = 0; i < index; i++)buffer[i] = arr[i];
		for (int i = index; i < size; i++)buffer[i + 1] = arr[i];
		buffer[index] = volue;
		break;
	case 2:	for (int i = 0; i < size; i++)buffer[i] = arr[i];
		buffer[size] = volue;
	}delete[] arr;
	size++;
	return buffer;
}
template <typename T> T* pop_f_e_b(T* arr, int& size, int index, int k){
	cout << "Для удаления элемента с ( начала/по индексу/конеца ) нажмите ( 0/1/2 ) :"; cin >> k;
	T* buffer = new T[--size];
	switch (k)
	{
	case 0:for (int i = 0; i <= size; i++)buffer[i] = arr[i + 1];
		break;
	case 1:for (int i = 0; i < index; i++)buffer[i] = arr[i];
		  for (int i = index; i <= size; i++)buffer[i] = arr[i + 1];
		  break;
	case 2:for (int i = 0; i < size; i++)buffer[i] = arr[i];
	}delete[] arr;
	return buffer;
}
//---------------------------двумерные масивы---------------------
template <typename T> T** push_row_f_i_b(T** arr, int& rows, const int cols, const int index, int k){
	cout << "Для добавления строки в ( начало/по индексу/конец ) нажмите ( 0/1/2 ) :"; cin >> k;
	T** buffer = new T * [rows + 1];
	switch (k)
	{
	case 0:for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
		buffer[0] = new T[cols]{};
		break;
	case 1:for (int i = 0; i < index; i++)buffer[i] = arr[i];
		for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
		buffer[index] = new T[cols]{};
		break;
	case 2:for (int i = 0; i < rows; i++)buffer[i] = arr[i];
		buffer[rows] = new T[cols]{};
	}delete[] arr;
	rows++;
    return buffer;
}
template <typename T> void push_col_f_i_b(T** arr, const int rows, int& cols, const int index, int k){
	cout << "Для добавления столбца в ( начало/по индексу/конец ) нажмите ( 0/1/2 ) :"; cin >> k;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		switch (k)
		{
		case 0:for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j]; break;
		case 1:for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
			for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j]; break;
		case 2:for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}cols++;
}
template <typename T> T** pop_row_f_e_b(T** arr, int& rows, const int cols, const int index, int k){
	cout << "Для удаления строки с ( начала/по индексу/конеца ) нажмите ( 0/1/2 ) :"; cin >> k;
	T** buffer = new T* [--rows];
	switch (k)
	{
	case 0:for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
		delete[] arr[0];
		break;
	case 1:for (int i = 0; i < index; i++)buffer[i] = arr[i];
		for (int i = index; i <= rows; i++)buffer[i] = arr[i + 1];
		delete[] arr[index];
		break;
	case 2:for (int i = 0; i < rows; i++)buffer[i] = arr[i];
		delete[] arr[rows];
	}delete arr;
	return buffer;
}
template <typename T> void pop_col_f_e_b(T** arr, const int rows, int& cols, int index, int k){
	cout << "Для удаления столбца с ( начала/по индексу/конеца ) нажмите ( 0/1/2 ) :"; cin >> k;
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		switch (k)
		{
		case 0:for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1]; break;
		case 1:for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
			for (int j = index; j <= cols; j++)buffer[j] = arr[i][j + 1]; break;
		case 2:for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template <typename T> void Allocate(T** &arr, const int rows, const int cols)
{
	arr = new T* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new T[cols];
}
template <typename T> void Clear(T** &arr, const int rows)
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete arr;
}