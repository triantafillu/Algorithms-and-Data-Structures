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

//������� ���������� ������� �����
void PreFunc(char key[], int ks, int table[])
{
    //��������� �� ��������� �� -1 (����� �� �������)
    for (int i = 0; i < 256; i++)
    {
        table[i] = -1;
    }
    //��������� �������� �� �������� ���� ASCII
    for (int i = 0; i < ks; i++)
    {
        table[char(key[i])] = i;
    }
}

//������� ������ �� ���������� ��
void BM(char text[], int n, char key[], int ks)
{
    //�������� ����� ��� ������� ���������� �������
    int table[256];

    //��������� �������
    PreFunc(key, ks, table);
    int shift = 0; //�������� ������ �� ������ � �������
    bool ind=false;

    //��� �������� ���������� �� ����� ������
    while (shift <= (n-ks))
    {
        int j = ks - 1; //������� ������� ������ ���� �� 1 ����� ������� ��������

        //����������� �� ������ � ������� ���� ������� ���������� �������� ������ �����
        while (key[j] == text[shift + j] && j >= 0)
        {
            j--;
            counter_compare++;
        }

        //���� �������� ���� �������� �������, �� j ����� ����� 0
        if (j < 0)
        {
            cout << "�������� �������� �i� i������� " << shift << endl;
            ind = true;

            //���� ����� ������ �����, ������ �����, ��� ����� � �����
            if ((shift + ks) < n)
            {
                //������� ���, ��� ��������� ������� � ����� � ������� ������� � ������� ���� ���������� � ��������
                shift += ks - table[text[shift + ks]];
            }
            else
            {
                shift += 1;
            }
        }
        else
        {
            //���� ����� ������ �����, ������ �����, ��� ����� � �����
            if (j - table[key[shift + j]] > 0)
            {
                //������� ���, ��� ��������� ������� � ����� � ������� ������� � ������� ���� ���������� � ��������
                shift += j - table[text[shift + j]];
            }
            else
            {
                shift += 1;
            }
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

            BM(arr, size, key, ks);

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

            BM(arr1, size, key1, ks);

            cout << "�i���i��� ���i�����: " << counter_compare << endl;
            counter_compare = 0;

            cout << "����i�� 0, ��� ��������� ��������� ��������, ���������� - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}