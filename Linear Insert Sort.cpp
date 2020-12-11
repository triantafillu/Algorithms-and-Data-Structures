#include <iostream>
using namespace std;

//Linear Insert Algorithm

void displayArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void LinearInsert(int A[], int n)
{
	int counter_swap = 0;
	int counter_compare = 0;
	int i;
	int key; //Значення елементу масиву
	int index; //Індекс елементу масиву (порожнього місця)
	
	for (i = 1; i < n; i++)
	{
		key = A[i];
		index = i;

		while (index > 0 && A[index - 1] > key)
		{
			A[index] = A[index - 1]; //Здвиг елементів, що більше за key на 1 вправо
			index = index - 1; //Новий індекс порожнього місця
			counter_swap++;
			counter_compare++;
		}
		A[index] = key;

		//Виведення проміжних результатів
		displayArray(A, n);
	}
	cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
	cout << "Кiлькiсть перестановок: " << counter_swap << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int y;
	do
	{
		int n;
		cout << "Введiть кiлькiсть елементiв масиву: " << endl;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i + 1 << "] = ";
			cin >> arr[i];
			cout << endl;
		}
		LinearInsert(arr, n);
		cout << "Вiсортований масив:" << endl;
		displayArray(arr, n);
		cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1"<<endl;
		cin >> y;
	} while (y != 0);
	return 0;
}
