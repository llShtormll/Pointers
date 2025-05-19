#include<iostream>


using namespace std;

void main()
{
	int even = 0;
	int odd = 0;
	int n = 10;
	int* arr_even = new int[even];
	int* arr_odd = new int[odd];
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)even++;
		else odd++;
	}
	for (int i = 0; i < n; i++)
	{
		
	}
}