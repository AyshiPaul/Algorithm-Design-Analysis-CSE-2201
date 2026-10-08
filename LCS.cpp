#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string x, y;

    cout << "Enter 1st string : ";
    cin >> x;

    cout << "Enter 2nd string : ";
    cin>>y;

    int m = x.length();
    int n = y.length();

    int B[m+1][n+1];

    //1st column
     for(int i = 0; i<m; i++)
    {
        B[i+1][0] = 0;
    }

    //1st row
    for(int j = 0; j<n; j++)
    {
        B[0][j+1] = 0;
    }

    //Formula
    for(int i = 1; i<=m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                B[i][j] = B[i-1][j-1] +1;
            }
            else
            {
                B[i][j] = max(B[i-1][j] , B[i][j-1]);
            }
        }
    }

    cout << "Maximum Length = " << B[m][n];

    return 0;
}
