#include<bits/stdc++.h>
using namespace std;

int maximumcrosssum(vector<int>&arr,int start, int mid, int last)
{
    int left_sum = INT_MIN;
    int sum = 0;

    for(int i=mid; i>=start; i--)
    {
        sum = sum +arr[i];
        left_sum = max(sum, left_sum);
    }

    int right_sum = INT_MIN;
     sum = 0;

    for(int i=mid+1; i<=last; i++)
    {
        sum = sum +arr[i];
        right_sum = max(sum, right_sum);
    }

    return left_sum + right_sum;
}

int maximumsumsubarray(vector<int>&arr, int start, int last)
{
    if (start == last)
    {
        return arr[start];
    }

    int mid = (start + last)/2;
    int leftsum = maximumsumsubarray(arr,start, mid);
    int rightsum = maximumsumsubarray(arr,mid+1,last);
    int crosssum = maximumcrosssum(arr,start,mid,last);

    return max({leftsum,rightsum,crosssum});
}

int main()
{
    vector<int> arr = {2,3,-8,7,2,-1,3};
    int n = arr.size();
    int result = maximumsumsubarray(arr,0,n-1);
    cout << "Result = " << result;

    return 0;
}
