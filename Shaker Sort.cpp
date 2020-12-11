#include <iostream>
using namespace std;

//Shaker Sort Algorithm

void displayArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void ShakerSort(int A[], int n)
{
	int counter_swap = 0;
	int counter_compare = 0;
	bool swap = true; // ���� �������� ���� = true
	while (swap)
	{
		swap = false;

		//����������� � ������� �������
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
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
		}

		swap = false;

		//����������� � ����������� �������
		for (int j = n - 2; j > 1; j--)
		{
			if (A[j] > A[j + 1])
			{
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
	}
	cout << "�i���i��� ���i�����: " << counter_compare<<endl;
	cout << "�i���i��� ������������: " << counter_swap<<endl;
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
		ShakerSort(arr, n);
		cout << "�i���������� �����:" << endl;
		displayArray(arr, n);
		cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
		cin >> y;
	} while (y != 0);
	return 0;
}