#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//Оскільки в кожній функції root - це локальна зміннна, то root - це поточний елемент

//Функція, що перевіряє дерево на порожність
bool ifEmpty1(Node* root)//для застосування всередині інших функцій
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ifEmpty2(Node* root)//для консольного застосування
{
	if (root == NULL)
	{
		cout << "Дерево пусте" << endl;
	}
	else
	{
		cout << "Дерево має елементи" << endl;
	}
}

//Функція, що вставляє елемент в дерево
Node* insertNode(Node*root, int info)
{
	//Якщо дерево пусте (немає корня), то вставлений елемент стає корнем
	if (root == NULL)
	{ 
		root->data = info;
		root->left = NULL;
		root->right = NULL;
	}

	//Якщо новий вузол менше корня, то рекурсія за лівою гілкою
	else if (info <= root->data)
	{
		root->left = insertNode(root->left, info);
	}

	//Якщо новий вузол більше корня, то рекурсія за правою гілкою
	else
	{
		root->right = insertNode(root->right, info);
	}
	return root;
}

//Функція, що шукає найменший елемент дерева
Node* minNode(Node* root)
{
	Node* el = new Node();
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте" << endl;
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	el->data = root->data;
	return el;
}

//Функція, що видаляє елемент з дерева
Node* deleteNode(Node* root, int info)
{
	//Якщо в дереві немає вузлів
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте" << endl;
		return root;
	}

	//Пошук елемента за допомогою рекурсії:

	//Якщо вузол з лівої гілки:
	else if (info < root->data)
	{
		root->left = deleteNode(root->left, info);
	}

	//Якщо вузол з правої гілки:
	else if (info > root->data)
	{
		root->right = deleteNode(root->right, info);
	}

	//Коли елемент знайдено:
	else
	{
		//Якщо елемент - листок:
		if (root->left == NULL && root->right == NULL)
		{
			delete root; //Видалення вузла
			root = NULL; //Оскільки root все ще має адресу
			return root; 
		}

		//Якщо елемент має 1 дитину:

		//Справа (зліва = NULL):
		else if (root->left == NULL)
		{
			Node* temp = root; //Тимчасовий вузол на позначення видаляємого вузла
			root = root->right; //Переміщення правого вузла наверх
			delete temp; //Видалення вузла
			return root;
		}

		//Зліва (справа = NULL):
		else if (root->right == NULL)
		{
			Node* temp = root; //Тимчасовий вузол на позначення видаляємого вузла
			root = root->left; //Переміщення лівого вузла наверх
			delete temp; //Видалення вузла
			return root;
		}

		//Якщо елемент має 2 дитини:
		else
		{
			Node* temp = minNode(root->right); //Пошук найменшого елемента з правої гілки дерева
			root->data = temp->data; //Переміщення знайденого значення на місце видаляємого елемента
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

//Функція, що шукає елемент в дереві та присвоює його значення змінній var
void findNode(Node* root, int info)
{
	int x;
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте" << endl;
	}

	//Якщо введене значення відповідає кореневому елементу:
	else if (root->data == info)
	{
		cout << "Елемент знайдено" << endl;
		x = root->data;
		cout << "x = " << x << endl;
	}

	//Рекурсивний пошук за лівою гілкою
	else if (info <= root->data)
	{
		findNode(root->left, info);
	}

	//Рекурсивний пошук за правою гілкою
	else
	{
		findNode(root->right, info);
	}
}

//Функція, що видаляє дерево
void deleteTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте  " << endl;
	}
	else
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete (root);
		cout << "Дерево видалено" << endl;
	}
}

//Функція, що копіює дерево
Node*copyTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте" << endl;
		return NULL;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = root->data;
		newNode->left = copyTree(root->left);
		newNode->right = copyTree(root->right);
		cout << "Дерево скопiйовано" << endl;
		return newNode;
	}
}
 
//Функція, що виводить всі елементи дерева на екран в порядку зростання
void displayTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "Дерево пусте" << endl;
	}
	else
	{
		//Якщо є менший елемент, ніж поточний (тобто елемент зліва)
		if (root->left != NULL)
		{
			displayTree(root->left);
		}
		cout << root->data << " ";
		if (root->right != NULL)
		{
			displayTree(root->right);
		}
	}
}

//Обхід в ширину: root - left - right
void Preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data <<endl;
	Preorder(root->left);
	Preorder(root->right);
}

//Симетричний обхід: left - root - right
void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data <<endl;
	Inorder(root->right);
}

//Обхід в глубину: left - right - root
void Postorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, a, x;
	string y, z; //індикатори кінця циклу
	int n;
	Node* root = NULL;
	cout << "Набiр операцiй:" << endl;
	cout << "1. Створити бiнарне дерево " << endl << "2. Додати елементи до бiнарного дерева" << endl << "3. Перевiрка бiнарного дерева на порожнiсть" << endl << "4. Видалення елемента з бiнарного дерева" << endl << "5. Видалення дерева" << endl<<"6. Знаходження та видобування даних"<<endl<<"7. Скопiювати дерево"<<endl<<"8. Вивести на консоль всi елементи дерева"<<endl<<"9. Симетричний обхiд"<<endl<<"10. Обхiд в ширину "<<endl<<"11. Обхiд в глибину "<<endl;

	do
	{
		cout << "Введiть номер операцiї: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "Бiнарне дерево створено" << endl;
			break;

		case 2:
			do
			{
				i++;
				cout << "Введiть елемент " << endl;
				cin >> a;
				root = insertNode(root,a);
				cout << "Введiть у (yes), якщо хочете зупинити заповнення стеку. Продовжити - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			cout << "Введiть елемент " << endl;
			cin >> a;
			deleteNode(root,a);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			ifEmpty2(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			deleteTree(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 6:
			cout << "Введiть елемент " << endl;
			cin >> a;
			findNode(root, a);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 7:
			copyTree(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 8:
			cout << "Елементи дерева:" << endl;
			displayTree(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 9:
			cout << "Симетричний обхiд:"<< endl;
			Inorder(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 10:
			cout << "Обхiд в ширину:"<< endl;
			Preorder(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 11:
			cout << "Обхiд в глибину " << endl;
			Postorder(root);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

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