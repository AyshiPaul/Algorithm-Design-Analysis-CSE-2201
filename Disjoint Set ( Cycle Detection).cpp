#include<bits/stdc++.h>
using namespace std;

vector <int >parent;

int findOp(int u)
{
    if(parent[u] == -1)
    {
        return u;
    }

    return findOp(parent[u]);
}

void unionOp(int scRoot, int desRoot)
{
    parent[desRoot] = scRoot;
}

bool isCycle(vector<pair<int, int>> &edges)
{
    for(auto e:edges)
    {
        int sc = e.first;
        int des = e.second;

        int scRoot = findOp(sc);
        int desRoot = findOp(des);

        if (scRoot == desRoot)
        {
            return true;
        }

        unionOp(scRoot, desRoot);
    }

    return false;
}

int main()
{
      int v, e;
      int sc, des;

      cout << "Enter the value of Vertices & Edges : ";
      cin >> v >> e;

      vector<pair<int , int>> edges;

      cout << "Enter the value of Source & Destination :" << endl;

      for(int i = 0; i<e ; i++)
      {
          cin >> sc >> des;
          edges.push_back(make_pair(sc, des));
      }

      parent.resize(v,-1);

      if(isCycle(edges)) cout << "Cycle Exits ";
      else cout << "No Cycle Exits";

      return 0;
}
