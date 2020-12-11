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
	for (int i = 0; i < n - 1; i++) //������� ������� ���� �� ����� ����
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min_index])
			{
				//��������� ������ ���������� ��������
				min_index = j;
				counter_compare++;
				counter_swap++;
			}
		}

		//������� �������� ������
		int temp = A[min_index];
		A[min_index] = A[i];
		A[i] = temp;
		
		//��������� �������� ����������
		displayArray(A, n);
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
		SimpleChoice(arr, n);
		cout << "�i���������� �����:" << endl;
		displayArray(arr, n);
		cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
		cin >> y;
	} while (y != 0);
	return 0;
}