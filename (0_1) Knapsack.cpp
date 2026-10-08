#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, capacity;

    cout << "Enter number of items : ";
    cin >> n;

    cout << "Enter Maximum Capacity : ";
    cin >> capacity;

    int weight[100], value[100];

    cout << "Enter weights : ";
    for(int i = 1; i<=n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter values : ";
    for(int i = 1; i<=n; i++)
    {
        cin >> value[i];
    }

    int B[100][100] = {0};

    //Formula
    for(int i = 1; i<=n; i++)
    {
        for(int w = 1; w<=capacity; w++)
        {
            if(weight[i] <= w)
               {
                    B[i][w] = max(B[i-1][w], B[i-1][w-weight[i]]+value[i]);
               }
            else
              {
                   B[i][w] = B[i-1][w];
              }
        }
    }

    cout << "Maximum values : " << B[n][capacity];

    return 0;
}
