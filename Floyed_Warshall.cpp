#include<iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices : ";
    cin >> n;

    int  D[100][100];

    cout << "Enter Distance Matrix : " << endl;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> D[i][j];
        }
    }

    //Floyed Warshall Formula

    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    cout << endl << "Shortest Distance Matrix : " << endl;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << D[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
