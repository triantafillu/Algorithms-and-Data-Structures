#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

//�������, �� ��������� ������������ ������� � �����
int FindMax(int A[], int n)
{
    int max_el = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max_el)
        {
            max_el = A[i];
        }
    }
    return max_el;
}
//���������� ����������
void CountingSort(int A[], int n)
{
    //������ ������������ �������
    int k = FindMax(A, n);

    int* out_A = new int[n]; //�����, �� ����� ������ ���
    int* count_A = new int[k+1]; //�����, �� �������� ������� �������� ��������  � ������� �����

    //��������� ����� ��� ��������� ������
    for (int i = 0; i <= k; i++)
    {
        count_A[i] = 0;
    }
        
    //ϳ��������� ������� �������� �������� � � ������� �����
    for (int j = 0; j < n; j++)
    {
        count_A[A[j]] = count_A[A[j]] + 1;
    }
        
    cout << "����� ��� �i��������:" << endl;
    displayArray(count_A, k + 1);

    //���������� ��������� �������� � ��������� �����	
    for (int i = 1; i <= k; i++)
    {
        count_A[i] = count_A[i] + count_A[i - 1];
    }
        
    cout << "����� ��� �i�������� �i��� �i����������:" << endl;
    displayArray(count_A, k + 1);

    //��������� �������� �����
    for (int j = n - 1; j >= 0; j--) 
    {
        out_A[count_A[A[j]] - 1] = A[j];
        count_A[A[j]] = count_A[A[j]] - 1;
    }

    //��������� �������� ����� � ������� �����
    for (int i = 0; i < n; i++)
    {
        A[i] = out_A[i];
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
            CountingSort(arr, size);
            cout << "�i���������� �����:" << endl;
            displayArray(arr, size - 1);

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
            CountingSort(arr1, size);
            cout << "�i���������� �����:" << endl;
            displayArray(arr1, size);

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

