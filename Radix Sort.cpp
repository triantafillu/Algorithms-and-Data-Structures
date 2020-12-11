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
void CountingSort(int A[], int n, int digit)
{
    int* out_A = new int [n]; //�����, �� ����� ������ ���
    int i, count_A[10] = { 0 }; //�����, �� �������� ������� �������� ��������  � ������� �����, ��������� ������

    //ϳ��������� ������� �������� �������� � � ������� �����
    for (i = 0; i < n; i++)
    {
        count_A[(A[i] / digit) % 10]++;
    }    

    cout << "����� ��� �i��������:" << endl;
    displayArray(count_A, 10);

    //���������� ��������� �������� � ��������� �����
    for (i = 1; i < 10; i++)
    {
        count_A[i] += count_A[i - 1];
    }    

    cout << "����� ��� �i�������� �i��� �i����������:" << endl;
    displayArray(count_A, 10);

    //��������� �������� �����
    for (i = n - 1; i >= 0; i--)
    {
        out_A[count_A[(A[i] / digit) % 10] - 1] = A[i];
        count_A[(A[i] / digit) % 10]--;
    }

    //��������� �������� ����� � ������� �����
    for (i = 0; i < n; i++)
    {
        A[i] = out_A[i];
    }     
}

//���������� ���������� 
void RadixSort(int arr[], int n)
{
    //������ ������������ ������� 
    int k = FindMax(arr, n);

    //��� ������� ������� (� ������������� �������� ������������ ������� �������)
    for (int i = 1; k / i > 0; i *= 10)
    {
        CountingSort(arr, n, i);
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
            RadixSort(arr, size);
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
            RadixSort(arr1, size);
            cout << "�i���������� �����:" << endl;
            displayArray(arr1, size);

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

