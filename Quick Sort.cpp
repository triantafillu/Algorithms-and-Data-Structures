#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//�������� ���� (��� ����� ���� ����������� � ����-��� ������� ��������)
int counter_swap = 0;
int counter_compare = 0; 

//�������, �� �������� �����
void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

//�������, �� ���� �������� ������
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int A[], int low, int high, int n) //n - ��� �������� ������ ����������
{
    int pivot = A[high];
    int j = low; //������ ���������

    for (int i = low; i < high; i++)
    {
        if (A[i] <= pivot)
        {
            //������� ������for (int i = low; i < high; i++)
            swap(&A[i], &A[j]);
            j++;
            counter_swap++;
        }
        counter_compare++;
    }

    //������� ������ �������� ��������� � ��������
    swap(&A[j], &A[high]);
    counter_swap++;

    //��������� �������� ����������
    displayArray(A, n);
    cout << endl;

    return j;   
}

//������ ����������
void QuickSort(int A[], int low, int high, int n)
{
    if (low < high)
    {
        int j = Partition(A, low, high,n);
        QuickSort(A, low, j - 1,n);
        QuickSort(A, j + 1, high,n);
    }
    
}

//�������, �� �������� �������� �����
void RandArray(int A[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        //��������� ����� 0-1000
        A[i] = rand() % 1000;
    }
}

//�������, �� �������� ����������� ������ ����� 
void InputArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "] = ";
        cin >> A[i];
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int y;
    cout << "���i� ������i�:" << endl;
    cout << "1. ��������� �����" << endl << "2. ������ �����" << endl;
    int n;
    int size;

    do
    {
        cin >> n;

        if (n == 1)
        {
            cout << "����i�� �i���i��� �������i� ������: " << endl;
            cin >> size;
            int* arr = new int[size];

            //��������� �� ���������� ������
            RandArray(arr, size);
            QuickSort(arr, 0, size-1,  size);
            cout << "�i���������� �����:" << endl;
            displayArray(arr, size-1);

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            cout << "�i���i��� ������������: " << counter_swap << endl;

            //��������� ���������
            counter_compare = 0;
            counter_swap = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }
        else
        {
            cout << "����i�� �i���i��� �������i� ������: " << endl;
            cin >> size;
            int* arr1 = new int[size];

            //��������� �� ���������� ������
            InputArray(arr1, size);
            QuickSort(arr1, 0, size-1, size);
            cout << "�i���������� �����:" << endl;
            displayArray(arr1, size);

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            cout << "�i���i��� ������������: " << counter_swap << endl;

            //��������� ���������
            counter_compare = 0;
            counter_swap = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

