#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
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

//˳����� �����
int LinearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
        counter_compare++;
    }
    return -1;
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
            int key;
            
            RandArray(arr, size);
            displayArray(arr, size);

            cout << "����i�� �������, ���� ������ ������:" << endl;
            cin >> key;
            int ind = LinearSearch(arr, size, key);
            if (ind != -1)
            {
                cout << "������� " << key << " �������� �i� i������� [" << ind << "]" << endl;
            }
            else
            {
                cout << "������� �� ��������" << endl;
            }

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            counter_compare = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }
        else
        {
        cout << "����i�� �i���i��� �������i� ������: " << endl;
        cin >> size;
        int* arr1 = new int[size];
        int key;

        InputArray(arr1, size);
        cout << "����i�� �������, ���� ������ ������:" << endl;
        cin >> key;
        int ind = LinearSearch(arr1, size, key);
        if (ind != -1)
        {
            cout << "������� " << key << " �������� �i� i������� [" << ind << "]" << endl;
        }
        else
        {
            cout << "������� �� ��������" << endl;
        }
        cout << "�i���i��� ���i�����: " << counter_compare << endl;
        counter_compare = 0;

        cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
        cin >> y;
        }

    } while (y != 0);

    return 0;
}