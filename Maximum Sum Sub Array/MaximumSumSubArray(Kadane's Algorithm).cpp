#include<bits/stdc++.h>
using namespace std;

int maximumsumsubarray(vector<int>&arr)
{
    int res = arr[0];
    int maxending = arr[0];

    for(int i = 1; i<arr.size(); i++)
    {
        maxending = max(arr[i], maxending + arr[i]);
        res = max(res, maxending);
    }

    return res;
}

int main()
{
    vector<int> arr = {2,3,-8,7,-2,-1,-3};
    int result = maximumsumsubarray(arr);
    cout << "Result = " << result;

    return 0;
}

