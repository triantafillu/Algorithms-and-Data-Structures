#include <iostream>
using namespace std;

//Simple Choice Algorithm

void displayArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void SimpleChoice(int A[], int n)
{
	int counter_swap = 0;
	int counter_compare = 0;
	int min_index;
	for (int i = 0; i < n - 1; i++) //Останній елемент буде на своєму місці
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min_index])
			{
				//Визначити індекс найменшого елемента
				min_index = j;
				counter_compare++;
				counter_swap++;
			}
		}

		//Поміняти елементи місцями
		int temp = A[min_index];
		A[min_index] = A[i];
		A[i] = temp;
		
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
		SimpleChoice(arr, n);
		cout << "Вiсортований масив:" << endl;
		displayArray(arr, n);
		cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
		cin >> y;
	} while (y != 0);
	return 0;
}