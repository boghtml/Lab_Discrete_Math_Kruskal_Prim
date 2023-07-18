// Алгоритм Крускала готовий.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cstdio>
#include <fstream>
#include <Windows.h>
#include <algorithm>

const int MAXN = 100; // максимальна кількість вершин

using namespace std;

struct Edge
{
    int u, v, weight;
};

Edge edges[MAXN * MAXN]; // масив ребер
int parent[MAXN]; // масив батьківських вершин

bool cmp(Edge a, Edge b);
int find(int x);
void merge(int a, int b);
void kruskalMST(int** array_weight_Krus, int n);

int main()
{
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int kil_vertix_Krus;
    cout << "Введіть кількість вершин: ";
    cin >> kil_vertix_Krus;
    int** array_weight_Krus = new int* [kil_vertix_Krus];
    for (int i = 0; i < kil_vertix_Krus; i++)
    {
        array_weight_Krus[i] = new int[kil_vertix_Krus];
        for (int j = 0; j < kil_vertix_Krus; j++)
        {
            cin >> array_weight_Krus[i][j];
        }
    }
    kruskalMST(array_weight_Krus, kil_vertix_Krus);
}

void kruskalMST(int** array_weight_Krus, int kil_vertix_Krus)
{
    int edgeCount = 0;
    for (int i = 0; i < kil_vertix_Krus; i++)
    {
        for (int j = i; j < kil_vertix_Krus; j++)
        {
            if (array_weight_Krus[i][j] > 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = array_weight_Krus[i][j];
                edgeCount++;
            }
        }
    }
    cout << "Вивід списка перед сортуванням:" << endl;
    for (int i = 0; i < kil_vertix_Krus; i++)
    {
        cout << edges[i].u + 1 << " - " << edges[i].v + 1 << "\t" << edges[i].weight << endl;
    }
    sort(edges, edges + edgeCount, cmp);
    cout << "Після" << endl;
    for (int i = 0; i <= kil_vertix_Krus; i++)
    {
        cout << edges[i].u + 1 << " - " << edges[i].v + 1 << "\t" << edges[i].weight << endl;
    }
    cout << endl;
    for (int i = 0; i < kil_vertix_Krus; i++)
    {
        parent[i] = i;
    }
    int sum_min_edges_Krus = 0;
    for (int i = 0; i < edgeCount; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            merge(edges[i].u, edges[i].v);
            cout << edges[i].u + 1 << " - " << edges[i].v + 1 << "\t" << edges[i].weight << endl;
            sum_min_edges_Krus += edges[i].weight;
        }
    }
    for (int i = 0; i < edgeCount; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << "Weight of MST: " << sum_min_edges_Krus << endl;
}

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(int x)
{
    if (x == parent[x])
        return x;
    return find(parent[x]);
}

void merge(int a, int b)
{
    parent[find(a)] = find(b);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
