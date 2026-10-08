#include<iostream>
using namespace std;

int n, graph[100][100], vertices[100];

void DFS(int node)
{
    vertices[node] = 1;

    for(int i = 0; i<n; i++)
    {
        if(graph[node][i] == 1 && vertices[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    cout << "Enter number of vertices : ";
    cin >> n;

    cout << "Enter adjancey matix : " << endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int count = 0;

    for(int i = 0; i<n; i++)
    {
        if(vertices[i] == 0)
        {
            DFS(i);
            count ++;
        }
    }

    cout << "Connected Component = " << count;

    return 0;
}

