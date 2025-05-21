#include<iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, " ");
	const int n = 10;
	int even_const = 0;
	int odd_const = 0;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_const : odd_const)++;
	}

	int* arr_even = new int[even_const];
	int* arr_odd = new int[odd_const];


	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? arr_even[j++] : arr_odd[k++]) = arr[i];
	}
	Print(arr_even, even_const);
	Print(arr_odd, odd_const);

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)arr[i] = rand() % 100;
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << '\t';
cout << endl;
}