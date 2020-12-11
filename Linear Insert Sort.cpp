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
	int key; //�������� �������� ������
	int index; //������ �������� ������ (���������� ����)
	
	for (i = 1; i < n; i++)
	{
		key = A[i];
		index = i;

		while (index > 0 && A[index - 1] > key)
		{
			A[index] = A[index - 1]; //����� ��������, �� ����� �� key �� 1 ������
			index = index - 1; //����� ������ ���������� ����
			counter_swap++;
			counter_compare++;
		}
		A[index] = key;

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
		LinearInsert(arr, n);
		cout << "�i���������� �����:" << endl;
		displayArray(arr, n);
		cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1"<<endl;
		cin >> y;
	} while (y != 0);
	return 0;
}
