#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

bool sortbyratio(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n , capacity;

    cout << "Enter number of items : ";
    cin >> n;

    cout << "Enter Maximum Capacity : ";
    cin >> capacity;

    Item item[n];

    cout << "Enter weights & values : "<<endl;
    for(int i = 0; i<n; i++)
    {
        cin >> item[i].weight >> item[i].value;
        item[i].ratio = (double)item[i].value / item[i].weight;
    }

    sort(item, item+n, sortbyratio);

    int totalvalue = 0;

    for(int i = 0; i<n; i++)
    {
        if(capacity >= item[i].weight)
        {
            totalvalue += item[i].value;
            capacity -= item[i].weight;
        }
        else
        {
            totalvalue += item[i].ratio*capacity;
        }
    }

    cout << "Maximum Profit = " << totalvalue;

    return 0;
}
