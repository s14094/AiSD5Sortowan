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

// generowanie liczb
void GenerateNumbers(int arr2[], int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		{
			arr2[i] = rand() % 2147483647;
		}
	}
}

/* ######################################## WYNIKI ########################################
+----------------+-----------------+------------------+------------------+----------------+
| NAZWA          | dla 50tys [sec] | dla 100tys [sec] | dla 500tys [sec] | dla 1mil [sec] |
+----------------+-----------------+------------------+------------------+----------------+
|BubbleSort      | 1min :34.357sec | 6 min:40.651sec  | 100 min+         | ?              |
|HeapSort        | 0.151           | 0.344            | 1.699            | 3.605          |
|LomutoQuickSort | 0.037           | 0.071            | 0.384            | 0.784          |
|HoareQuickSort  | 0.040           | 0.086            | 0.490            | 1.080          |
|CombSort        | 0.076           | 0.141            | 0.750            | 1.441          |
+----------------+-----------------+------------------+------------------+----------------+

*/

int main()
{
	clock_t start, stop;
	double time;
	int startquick = 0;
	int size = 500000; // rozmiar tablicy
	int * arr = new int[size];
	GenerateNumbers(arr, size);

	//przed sortowaniem
	//PrintArray(arr, size);

	start = clock();

	/* ######################################## SORTOWANIA ########################################*/
	//BubbleSort(arr, size);   //dla 40k liczy 60 sec
	//HeapSort(arr, size);
	//LomutoQuickSort(arr, startquick, size - 1);
	//HoareQuickSort(arr, startquick, size - 1);
	//CombSort(arr, size);
	/* ######################################## ########## ########################################*/

	stop = clock();
	time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas: " << time << endl;

	//po stortowaniu
	//PrintArray(arr, size);

	getchar(), getchar();
}