#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int counter_compare = 0;

//�������, �� �������� �����
void displayArray(char A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
    cout << endl;
}

//�������� �����
bool NativeTextSearch(char text[], int n, char key[], int ks)
{
    for (int i = 0; i <= n - ks; i++)
    {
        int j;
        //��������� �������� ��������� ��� ������� �
        for (j = 0; j < ks; j++)
        {
            //���� ���� � ���������� �������� �� ������� ����� �������� � ��������
            if (text[i + j] != key[j])
            {
                break;
            }
            counter_compare++;
        }

        //���� �������� ������� ��������
        if (j == ks)
        {
            cout << "�������� �������� �i� i������� [" << i <<"]"<< endl;
            return true;
        }
    }
    return false;
}

//�������, �� �������� �������� �����
void RandArray(char A[], int n)
{
    //�����, � ���� ���������� ����� (���������� ������)
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        //��������� ����� 0-1000
        A[i] = alphabet[rand() % 26]; 
    }
}

//�������, �� �������� ����������� ������ ����� 
void InputArray(char A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int y;
    cout << "���i� ������i�:" << endl;
    cout << "1. ��������� �����" << endl << "2. ������ �����" << endl;
    int n;
    int size, ks;

    do
    {
        cin >> n;

        if (n == 1)
        {
            cout << "����i�� ������� �����: " << endl;
            cin >> size;
            char* arr = new char[size];

            RandArray(arr, size);
            displayArray(arr, size);

            cout << "����i�� ������� ���������, ���� ������ ������:" << endl;
            cin >> ks;
            char* key = new char[ks];
            cout << "����i�� ��������, ���� ������ ������:" << endl;
            InputArray(key, ks);

            bool ind = NativeTextSearch(arr,size, key, ks);
            if (!ind)
            {
                cout << "�������� �� ��������" << endl;
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
            char* arr1 = new char[size];

            InputArray(arr1, size);

            cout << "����i�� ������� ���������, ���� ������ ������:" << endl;
            cin >> ks;
            char* key1 = new char[ks];

            cout << "����i�� ��������, ���� ������ ������:" << endl;
            InputArray(key1, ks);

            bool ind = NativeTextSearch(arr1, size, key1, ks);
            if (!ind)
            {
                cout << "�������� �� ��������" << endl;
            }

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            counter_compare = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}