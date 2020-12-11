#include <iostream>
#include <algorithm>

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
			cout << list[i].v2 + 1 << " " << list[i].v1 +1<< " " << list[i].weight;
			cout << endl;
		}
	}
}

/*Допоміжна функція порівння двух ребер 
за їх вагою, що в подальшому використовується
для сортування списку ребер*/
bool CompareWeights(Edge a, Edge b)
{
	if (b.weight > a.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Функція, що перевіряє чи створює ребро цикл
bool IfCycle(int v1, int v2, int graph[])
{
	//Якщо вершини належать до однієї групи (утворюють цикл), повернути true

	//Вершини однієї групи мають однакові індекси

	//Знайти, до якої групи належить вершини
	while (graph[v1] != v1)
	{
		v1 = graph[v1];
	}
	while (graph[v2] != v2)
	{
		v2 = graph[v2];
	}

	//Якщо групи різні
	if (v1 != v2)
	{
		graph[v1] = v2;
		return false;
	}
	//Якщо одна група
	else
	{
		return true;
	}
}

int Find(int v, int graph[])
{
	if (graph[v] == v)
	{
		return v;
	}
	else
	{
		return Find(graph[v], graph);
	}
}

//Функція пошуку MST за алгоритмом Крускала
void Kruskal(Edge array[], int V, int E)
{
	//Відсортувати ребра за вагою
	sort(array, array + E, CompareWeights);

	/*Створити масив, що заповнений вершинами графа, 
	який буде містити інформацію про цикли*/
	int* graph = new int[V];
	for (int i = 0; i < V; i++)
	{
		graph[i] = i;
	}

	//Створити вихідний масив
	Edge* MST = new Edge[V - 1];

	//Рахує кількість ребер, доданих у вихідний масив
	int c = 0;

	int i = 0;
	cout << "Етапи побудови дерева" << endl;
	while (c != (V - 1))
	{
		Edge e = array[i];

		//int vertex1 = Find(e.v1, graph);
		//int vertex2 = Find(e.v2, graph);
		//Якщо не утворює цикл
		if (!IfCycle(e.v1, e.v2, graph))
		//if (vertex1!=vertex2)
		{
			//Об'єднати ребра в одну групу
			//graph[vertex1] = vertex2;

			//Додати ребро у вихідний масив
			MST[c] = e;
			c++;

			//Виведення проміжних результатів
			cout << c << ")" << endl;
			cout << e.v1 + 1 << " " << e.v2 + 1 << " " << e.weight;
			cout << endl;
		}
		i++;
	}
	cout << "MST:" << endl;
	cout << "Cписок ребер (вершина_1  вершина_2  вага):" << endl;

	//Надрукувати результат
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

	Kruskal(arr, V, E);
}