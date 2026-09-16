#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void build(int node, int left, int right, vector<int>&arr)
{
    if(left == right)
    {
        tree[node] = arr[left];
        return;
    }

    int mid = (left+right)/2;

    build(2*node+1, left, mid, arr);

    build(2*node+2, mid+1, right, arr);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node, int left, int right, int ql, int qr)
{
    if(right < ql || left > qr)
        return 0;

    if(left >= ql && right <= qr)
        return tree[node];

    int mid = (left + right)/2;
    int treeleft = query(2*node+1, left, mid,ql,qr);
    int treeright = query(2*node+2, mid+1, right,ql,qr);
    return treeleft+treeright;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int n = arr.size();
    tree.resize(4*n);

    build(0,0,n-1,arr);

    cout<<"After Sum"<<endl;

    cout<<query(0,0,n-1,0,3)<<endl;
}
