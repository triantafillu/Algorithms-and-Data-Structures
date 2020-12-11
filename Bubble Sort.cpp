#include <iostream>
using namespace std;

//Bubble Algorithm

void displayArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int A[], int n)
{
	int counter_swap = 0;
	int counter_compare = 0;
	bool swap; // Якщо відбулася зміна = true
	for (int i = 0; i < n - 1; i++)
	{
		swap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				//Поміняти елементи місцями
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				swap = true;

				counter_swap++;
				counter_compare++;

			}

			//Виведення проміжних результатів
			displayArray(A, n);
		}
		if (!swap) //Якщо зміна не відбулась 
		{
			break;
			cout << "Кiлькiсть порiвнянь: 0" << endl;
			cout << "Кiлькiсть перестановок: 0"<< endl;
		}
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
		BubbleSort(arr, n);
		cout << "Вiсортований масив:" << endl;
		displayArray(arr, n);
		cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
		cin >> y;
	} while (y != 0);
	return 0;
}