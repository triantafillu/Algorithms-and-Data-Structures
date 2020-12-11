#include <iostream>
#include <map>

using namespace  std;

//Структура "ребро"
struct Edge
{
public:
	int v1; //Вершина, з якої виходить
	int v2; //Вершина в яку входить
	int weight; //Вага вершини
};

//Функція, що друкує список ребер у форматі вершина_1 вершина_2 вага
void PrintEdgeList(Edge list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Щоб вивести порядок вершин у порядку зростання
		if (list[i].v1 < list[i].v2)
		{
			/*+1, оскільки вершини записані в масив відповідно до індексації в списку вершин
			основного графа (наприклад, вершині 1 відповідає значення 0 = [0])*/
			cout << list[i].v1 + 1 << " " << list[i].v2 + 1 << " " << list[i].weight;
			cout << endl;
		}
		else
		{
			cout << list[i].v2 + 1 << " " << list[i].v1 + 1 << " " << list[i].weight;
			cout << endl;
		}
	}
}

/*Функція, що шукає наступне ребро з мінімальною вагою
Повертає кортеж (ребро, індекс)
ребро - ребро, що входить до MST
iндекс - вершина, яку треба відмітити як "відвідану"*/
tuple <Edge, int> MinEdge(Edge array[], bool U[], int E)
{
	//Вершина, вага якої буде порівнюватися, та яку повертає функція
	Edge e;
	e.weight = INT_MAX; //для першого порівняння, оскільки точно буде більше
	int v; //Індекс відвіданої вершини

	for (int i = 0; i < E; i++)
	{
		//Якщо одна з вершин відвідана,а друга ні, та вага менше за вагу e
		if ((U[array[i].v1] && !U[array[i].v2]) && array[i].weight < e.weight)
		{
			e = array[i]; //Cтає мінімальним ребром
			v = array[i].v2; // Друга вершина відвідана
		}
		else if (U[array[i].v2] && !U[array[i].v1] && array[i].weight < e.weight)
		{
			e = array[i];
			v = array[i].v1;
		}
	}
	
	return { e, v };
}


//Функція пошуку MST за алгоритмом Прима
void Prim(Edge array[], int V, int E)
{
	//Створити вихідний масив
	Edge* MST = new Edge[V - 1];

	//true - вершина відвідана, false - невідвідана
	bool* U = new bool[V];

	//Відмітити усі вершини крім першої як невідвідані
	for (int i = 1; i < V; i++)
	{
		U[i] = false;
	}
	
	//Перша - відвідана
	U[0] = true;

	cout << "Етапи побудови дерева" << endl;
	for (int i = 0; i < V - 1; i++)
	{
		int j;
		Edge e;
		
		//Знайти мінімальне ребро
		tie(e, j) = MinEdge(array, U, E);

		//Додати ребро до MST
		MST[i] = e;

		//Відмітити вершину як відвідану
		U[j] = true;

		//Виведення проміжних результатів
		cout << i+1 << ")" << endl;
		cout << MST[i].v1 + 1 << " " << MST[i].v2 + 1 << " " << MST[i].weight;
		cout << endl;
	}
	cout << endl;
	cout << "MST:" << endl;
	cout << "Cписок ребер (вершина_1  вершина_2  вага):" << endl;
	PrintEdgeList(MST, V - 1);
}

//Функція введеня графу за допомогою списку ребер
void InputGraph(Edge input[], int n)
{
	int v1, v2, w;
	cout << "Введiть список ребер (вершина_1  вершина_2  вага):" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v1 >> v2 >> w;

		//Оскільки в функціЇ для побудови дерева вершини нумеруються 0-V
		v1 = v1 - 1;
		v2 = v2 - 1;
		input[i].v1 = v1;
		input[i].v2 = v2;
		input[i].weight = w;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int V, E;
	cout << "Введiть кiлькiсть вершин та ребер:" << endl;
	cin >> V >> E;
	Edge* arr = new Edge[E];

	InputGraph(arr, E);

	cout << endl;

	Prim(arr, V, E);
}