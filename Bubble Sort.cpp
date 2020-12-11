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
	bool swap; // ���� �������� ���� = true
	for (int i = 0; i < n - 1; i++)
	{
		swap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				//������� �������� ������
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				swap = true;

				counter_swap++;
				counter_compare++;

			}

			//��������� �������� ����������
			displayArray(A, n);
		}
		if (!swap) //���� ���� �� �������� 
		{
			break;
			cout << "�i���i��� ���i�����: 0" << endl;
			cout << "�i���i��� ������������: 0"<< endl;
		}
	}
	cout << "�i���i��� ���i�����: " << counter_compare << endl;
	cout << "�i���i��� ������������: " << counter_swap << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int y;
	do
	{
		int n;
		cout << "����i�� �i���i��� �������i� ������: " << endl;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i + 1 << "] = ";
			cin >> arr[i];
			cout << endl;
		}
		BubbleSort(arr, n);
		cout << "�i���������� �����:" << endl;
		displayArray(arr, n);
		cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
		cin >> y;
	} while (y != 0);
	return 0;
}