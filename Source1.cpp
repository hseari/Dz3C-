#include <iostream>

template <typename T>
void bubbleSort(T arr[], int size)
{
	int temp; //временная переменная

	for (int i = 0; i < size - 1; i++)    
	{
		for (int j = size - 1; j > i; j--)  //идем с конца массива, помещая наименьший за проход элемент в начало массива, пока не закончатся
		{       
			if (arr[j] < arr[j - 1])
			{
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

template <typename T>
void insertionSort(T arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];  //начинаем сортировку с 1 элемента, т.к. 0 элемент считается уже отсортированной послед-ью.
		j = i - 1;
		
		while (j >= 0 && arr[j] > key) //если левый элемент больше правого
		{
			arr[j + 1] = arr[j]; //то меняем их местами
			j = j - 1;           
		}
		arr[j + 1] = key;      
	}
}

template <typename T>
void swap(T* x, T* y)  //меняем местами функции
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

template <typename T>
void selectionSort(T arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;               //находим минимальный элемент в неотсортированном массиве
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		if (min_idx != i)        //меняем местами найденный минимальный и первый элементы
			swap(&arr[min_idx], &arr[i]);
	}
}

template <typename T>
void printArray(T arr[], int n)    //вывод массивов
{
	int i;
	for (i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//bubble сортировка

	double arr[] = { 5.5,3,7,9,2,6,4 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, arrSize);

	std::cout << "Bubble sort: ";
	printArray(arr, arrSize);
	
	//insertion сортировка
	
	int arr2[] = {5,6,8,2,0,1,8,3,11};
	int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
	insertionSort(arr2, arrSize2);

	std::cout << "Insertion sort: ";
	printArray(arr2, arrSize2);

	//selection сортировка

	double arr3[] = { 0.8, 0, 5, 8, 9 };
	int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
	selectionSort(arr3, arrSize3);

	std::cout << "Selection array: ";
	printArray(arr3, arrSize3);
	
	return 0;
}


