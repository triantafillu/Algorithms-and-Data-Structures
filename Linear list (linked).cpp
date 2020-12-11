#include <iostream>
using namespace std;

//Вузол списку
struct Node
{
    int data;
    Node* link;
};

Node* head = NULL;

//Функція, що перевіряє список на пустоту
bool IfEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Функція, що спустошує список
void ToEmpty()
{
    head = NULL;
    cout << "Список пустий" << endl;
}

//Функція, що вставляє елемент в початок списку
void Insert_beg(int el)
{
    Node* ptr = new Node();
    ptr->data = el;
    ptr->link = head;
    head = ptr;
}

//Функція, що вставляє елемент в кінець списку
void Insert_end(int el)
{
    Node* ptr = new Node();
    ptr->data = el;
    ptr->link = NULL;
    if (IfEmpty())
    {
        head = ptr;
    }
    else
    {
        Node* temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

//Функція, що вставляє елемент на вказану позицію
void Insert_ind(int el, int pos)
{
    Node* element = new Node;
    element->data = el;
    element->link = NULL;
    Node* curr = head;
    if (pos == 1)
    {
        element->link = head;
        head = element;
    }
    else
    {
        for (int i = 1; i < (pos - 1); i++)
        {
            if ((curr != NULL) && (curr->link != NULL))
            {
                curr = curr->link;
            }
        }
        if ((curr != NULL) && (curr->link != NULL))
        {
            element->link = curr->link;
            curr->link = element;
        }
        else
        {
            cout << "Неможливо вставити елемент" << endl;
        }
    }
}

//Функція, що видаляє елемент з кінці списку
void Delete_end()
{
    Node* ptr = new Node();
    Node* prev = new Node();

    if (IfEmpty())
    {
        cout << "Список пустий" << endl;
    }
    else if (head->link == NULL)//Лише один вузол в списку
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

//Функція, що видаляє елемент за вказаною позицією
void Delete_ind(int pos)
{
    if (IfEmpty())
    {
        cout << "Список пустий" << endl;
    }
    else
    {
        Node* curr = head;
        for (int i = 1; i < pos; i++)
        {
            if (curr != NULL)
            {
                curr = curr->link;
            }
        }
        if (curr != NULL)
        {
            if (curr == head)
            {
                head = head->link;
                delete(curr);
                curr = head;
            }
            else
            {
                Node* tmp = head;
                while (tmp->link != curr)
                {
                    tmp = tmp->link;
                }
                tmp->link = curr->link;
                delete(curr);
                curr = tmp;
            }
        }

    }  
}

//Функція, що шукає елемент в списку
string FindEl(int el)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        if (el = tmp->data)
        {
            return "Елемент знайдено\n";
            break;
        }
        else
        {
            tmp = tmp->link;
        }
    }
    return "Eлемент не знайдено\n";
}
 
//Допоміжна функція для визначення кількості елементів в списку
int Length()
{
    int length = 0;
    Node*tmp = head;
    while (tmp != NULL)
    {
        length++;
        tmp = tmp->link;
    }
    return length;
}

//Фуекція, що сортує список
void Sort()
{
    int length, l, ptr;
    Node*tmp = head;
    length = Length();
    l = length;
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (l - 1); j++)
        {
            if (tmp->data > tmp->link->data)
            {
                ptr = tmp->data;
                tmp->data = tmp->link->data;
                tmp->link->data = ptr;
            }
            tmp = tmp->link;
        }
        l--;
        tmp = head;
    } 
}

//Функція, що виводить список на екран
void Display()
{
    Node*tmp = head;
    cout << "Cписок: "<<endl;
    while (tmp!= NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int i = 0, a, pos;
    string y, z;

    cout << "Набiр операцiй:" << endl;
    cout << "1. Додати елемент в кiнець списку" << endl << "2. Додати елемент в початок списку "<< endl << "3. Додати елемент на задану позицiю"<< endl<< "4. Видалити елемент з кiнця списку" << endl << "5. Видалити елемент за його індексом"<<endl<<"6. Знаходження елементу" << endl << "7. Виведення списку на екран" << endl <<"8. Сортування списку"<<endl<< "9. Спустошення списку" << endl;

    do
    {
        cout << "Введiть номер операцiї: ";
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 1:
            do
            {
                i++;
                cout << "Введiть " << i << " елемент списку: " << endl;
                cin >> a;
                Insert_end(a);
                cout << "Введiть у (yes), якщо хочете зупинити заповнення списку. Продовжити - n(no)" << endl;
                cin >> y;
            } while (y != "y");
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 2:
            do
            {
                cout << "Введiть елемент списку: " << endl;
                cin >> a;
                Insert_beg(a);
                cout << "Введiть у (yes), якщо хочете зупинити заповнення списку. Продовжити - n(no)" << endl;
                cin >> y;
            } while (y != "y");
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 3:
            cout << "Введiть елемент списку: " << endl;
            cin >> a;
            cout << "Введiть позицiю: " << endl;
            cin >> pos;
            Insert_ind(a, pos);
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 4:
            Delete_end();
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 5:
            cout << "Введiть позицiю: " << endl;
            cin >> pos;
            Delete_ind(pos);
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 6:
            cout << "Введiть елемент списку: " << endl;
            cin >> a;
            cout<< FindEl(a)<<endl;
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 7:
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 8:
            Sort();
            Display();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 9:
            ToEmpty();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;

        default:
            cout << "Невизначена операцiя" << endl;
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;
        }
    } while (z != "y");
    return 0;

}