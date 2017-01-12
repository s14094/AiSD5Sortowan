#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>

using namespace std;

/* ######################################## BABELKOWE ########################################*/

void BubbleSort(int arr[], int n)
{
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/* ######################################## HEAPSORT ########################################*/
void Heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

/* ######################################## SZYBKIE LOMUTO ########################################*/

int Partition(int arr[], int start, int n, int pivotIndex)
{
	int pivot = arr[pivotIndex];
	do
	{
		while (arr[start] < pivot) start++;
		while (arr[n] > pivot) n--;
		if (start < n && arr[start] != arr[n])
		{
			swap(arr[start], arr[n]);
		}
		else
		{
			return n;
		}
	} while (start < n);
	return n;
}

void LomutoQuickSort(int arr[], int start, int n)
{
	if (start < n)
	{
		int pivot = (start + n) / 2;
		int pivotNew = Partition(arr, start, n, pivot);
		LomutoQuickSort(arr, start, pivotNew - 1);
		LomutoQuickSort(arr, pivotNew + 1, n);
	}
}

/* ######################################## SZYBKIE HORAE ########################################*/

void HoareQuickSort(int arr[], int start, int n)
{
	if (start >= n) return;
	int s = (start + n) / 2;
	int pivot = arr[s], i = start, j = n;
	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++; j--;
		}
	}
	if (j > start)
		HoareQuickSort(arr, start, j);
	if (i < n)
		HoareQuickSort(arr, i, n);
}

/* ######################################## GRZEBIENIOWE ########################################*/
void CombSort(int arr[], int n)
{
	int newsize = n;
	bool replace = true;

	while (newsize > 1 || replace)
	{
		newsize = newsize * 10 / 13;
		if (newsize == 0)
			newsize = 1;

		replace = false;
		for (int i = 0; i + newsize < n; i++)
		{
			if (arr[i + newsize] < arr[i])
			{
				swap(arr[i], arr[i + newsize]);
				replace = true;
			}
		}
	}
}

/* ######################################## INNE ########################################*/

// wypisywanie (do sprawdzenia dzialania)
void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// generowanie liczb randomowych
void GenerateRandomNumbers(int arr2[], int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		arr2[i] = rand() % 2147483647;
	}
}

// generowanie liczb od 0 do x
void GenerateMinMaxNumbers(int arr2[], int size) {
	for (int i = 0; i < size; ++i)
	{
		arr2[i] = i;
	}
}

// generowanie liczb od x do 0
void GenerateMaxMinNumbers(int arr2[], int size) {
	int temp;
	temp = size - 1;
	for (int i = 0; i < size; ++i)
	{
		arr2[temp] = i;
		temp = temp - 1;
	}
}

/* ######################################## WYNIKI ########################################
+----------------+-----------------+------------------+------------------+----------------+
| RANDOM         | dla 50tys [sec] | dla 100tys [sec] | dla 500tys [sec] | dla 1mil [sec] |
+----------------+-----------------+------------------+------------------+----------------+
|BubbleSort      | 9.565           | 37.878           | 952.971          | ponad 30 min   |
|HeapSort        | 0.167           | 0.373            | 2.220            | 4.553          |
|LomutoQuickSort | 0.007           | 0.016            | 0.082            | 0.195          |
|HoareQuickSort  | 0.012           | 0.031            | 0.193            | 0.469          |
|CombSort        | 0.006           | 0.015            | 0.087            | 0.188          |
+----------------+-----------------+------------------+------------------+----------------+

+----------------+-----------------+------------------+------------------+----------------+
| OD 0 DO X      | dla 50tys [sec] | dla 100tys [sec] | dla 500tys [sec] | dla 1mil [sec] |
+----------------+-----------------+------------------+------------------+----------------+
|BubbleSort      | 9.483           | 39.062           | 987.455          | ponad 30 min   |
|HeapSort        | 0.155           | 0.324            | 2.032            | 4.371          |
|LomutoQuickSort | 0.006           | 0.012            | 0.060            | 0.152          |
|HoareQuickSort  | 0.008           | 0.018            | 0.076            | 0.181          |
|CombSort        | 0.006           | 0.013            | 0.081            | 0.197          |
+----------------+-----------------+------------------+------------------+----------------+

+----------------+-----------------+------------------+------------------+----------------+
| OD X DO 0      | dla 50tys [sec] | dla 100tys [sec] | dla 500tys [sec] | dla 1mil [sec] |
+----------------+-----------------+------------------+------------------+----------------+
|BubbleSort      | 8.960           | 35.886           | 908.028          | ponad 30 min   |
|HeapSort        | 0.146           | 0.331            | 1.674            | 3.489          |
|LomutoQuickSort | 0.008           | 0.013            | 0.054            | 0.113          |
|HoareQuickSort  | 0.008           | 0.020            | 0.076            | 0.146          |
|CombSort        | 0.007           | 0.013            | 0.081            | 0.173          |
+----------------+-----------------+------------------+------------------+----------------+


*/

int main()
{
	clock_t start, stop;
	double time;
	int startquick = 0;
	int size = 50000; // rozmiar tablicy
	int * arr = new int[size];
	int * arr1 = arr;
	int * arr2 = arr;
	int * arr3 = arr;
	int * arr4 = arr;
	int * arr5 = arr;
	
	/* ######################################## SORTOWANIA ########################################*/
	GenerateRandomNumbers(arr, size);
	//GenerateMinMaxNumbers(arr, size);
	//GenerateMaxMinNumbers(arr, size);
	/* ######################################## ########## ########################################*/

	//przed sortowaniem
	//PrintArray(arr, size);

	start = clock();
	HeapSort(arr2, size);
	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas HeapSort: " << time << endl;

	start = clock();
	LomutoQuickSort(arr2, startquick, size - 1);
	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas LomutoQuickSort: " << time << endl;

	start = clock();
	HoareQuickSort(arr3, startquick, size - 1);
	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas HoareQuickSort: " << time << endl;

	start = clock();
	CombSort(arr4, size);
	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas CombSort: " << time << endl;


	start = clock();
	BubbleSort(arr5, size);
	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas BubbleSort: " << time << endl;


	//po stortowaniu
	//PrintArray(arr, size);

	getchar(), getchar();
}