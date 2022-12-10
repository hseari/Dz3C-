#include <iostream>
int task1() 
{
	int a = 5;
	int* ptra = &a;  //создаем указатель на целочисленную переменную
	std::cout << *ptra << std::endl;
	*ptra = 100;      //присваиваем ей через указатель 100
	std::cout << *ptra << std::endl;

	int* ptr2 = ptra;     //копируем значение первого указателя во второй указатель
	std::cout << *ptr2;   

	*ptr2 = 200;        //присваеваем значение 200 через второй указатель
	std::cout << *ptr2 << std::endl;
	return 0;
}

//task2
void swap(int *a,int *b)
{
	int t;
	t = *a; *a = *b; *b = t;

}


//Дано число n. Требуется создать массив a из n целых чисел и указатели на первый pa и последний pla элементы этого массива. 
//Нужно поменять с их помощью первый и последний элементы массива местами и вывести получившийся массив.
int task3()
{
	int n = 0;
	std::cout << "Введите длину массива: " << std::endl;
	std::cin >> n;
	int *a = new int[n];   //создаем массив

	int* ptrpa = &a[0];      //создаем указатель на первый элемент
	int* ptrpla = &a[n -1];          //создаем указатель на последний элемент

	std::cout << "Введите элементы: ";  //вводим элементы массива
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int tmp = a[0];   //меняем местами первый и последний элементы
	a[0] = a[n -1];
	a[n-1] = tmp;

	std::cout << "Массив: ";
	for (int i = 0; i < n; i++)    //выводим массив
		std::cout << a[i] << " ";

	std::cout << std::endl;

	delete[] a;      //освобождаем память
	a = nullptr;
	return 0;
}

int task4()
{
	double a = 2;

	double* b = &a;   
	double** p = &b;    //указатель на указатель
	std::cout << **p;    //выводим 2 через указатель на указатель

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 5;
	int b = 0;
	swap(&a, &b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	task3();
	task4();

	return 0;
}
