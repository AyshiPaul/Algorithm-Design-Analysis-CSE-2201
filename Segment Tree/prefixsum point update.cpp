#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    int n;

    cout << "Enter number of n (array element)  : ";
    cin >> n;

    vector<int>arr(n);

    cout << "The array is : ";

    for( int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int>prefixsum(n);

    prefixsum[0] = arr[0];

    for( int i = 1; i<n; i++)
    {
        prefixsum[i] = prefixsum[i-1] + arr[i];
    }

    int ql, qr, sum;

    cout << "Number of query : ";
    cin >> t;

    while(t--)
    {
        cout << "Query Range : ";
        cin >> ql >> qr;

        if(ql != 0)
        {
            cout << "Sum : ";
            cout << prefixsum[qr] - prefixsum[ql-1] << endl;
        }

        else
        {
              cout << "Sum : ";
            cout << prefixsum[qr] << endl;
        }
    }

    return 0;
}
