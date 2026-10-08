#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;

    cout<< "Enter number of element : ";
    cin >> n;

    int a[n] , length[n];

    cout << "Enter element : ";
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        length[i] = 1;
    }

   //Formula
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(a[i] > a[j])
            {
                length[i] = max(length[i], length[j]+1);
            }
        }
    }

    //totalLength
    int sum = 0;

    for(int i = 0; i<n; i++)
    {
        sum = max(sum, length[i]);
    }

    cout << "Maximum Length of LIS = " << sum;

    return 0;
}
