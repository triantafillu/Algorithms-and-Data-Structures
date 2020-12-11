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

//��������� �������
void PreFunc(char key[], int ks, int pref[])
{
    int length = 0; //���������, �� ���� ������������ � �����
    pref[0] = 0; //�������� �� [0] ������ = 0
    int i = 1;
    while (i < ks)
    {
        //���� ���� �������==������
        if (key[i] == key[length])
        {
            length++;
            pref[i] = length;
            i++;
            counter_compare++;
        }
        else
        {
            if (length != 0)
            {
                length = pref[length - 1];
            }
            //���� �� ���� - 0
            else
            {
                pref[i] = 0;
                i++;
            }
        }
    }
    

    
}

//������� ������ �� ���������� ���
void KMP(char text[], int n, char key[], int ks)
{
    //�������� ����� ��� ��������� �������
    int *pref = new int[ks];

    //������ ��������� �������
    PreFunc(key, ks, pref);
    for (int i = 0; i < ks; i++)
    {
        cout << pref[i];
    }
    cout << endl;
    int i = 0, j = 0;
    bool ind;
    while (i < n)
    {
        //���� ������ ��������� �������� � �������� ������ - �������� i �� j
        if (key[j] == text[i])
        {
            i++;
            j++;
            counter_compare++;
        }
        //���� ���� �������� ��������
        if (j == ks)
        {
            cout << "�������� �������� �i� i������� " << (i - j) << endl;
            j = pref[j - 1];
            ind = true;
        }
        //���� �������� �� ��������
        else if (i < n && key[j] != text[i])
        {
            //�������� �� �������� � ����������� ������
            if (j != 0)
            {
                j = pref[j - 1];
            }
            //���� j==0, �������� ���� �� 1
            else
            {
                i++;
            }
            ind = false;
        }
    }
    
    if (!ind)
    {
        cout << "�������� �� ��������" << endl;
    }
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

            KMP(arr, size, key, ks);

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

            KMP(arr1, size, key1, ks);

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            counter_compare = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}