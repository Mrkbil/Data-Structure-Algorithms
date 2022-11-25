#include<bits/stdc++.h>
using namespace std;

struct items
{
    int weight;
    int price;
    float unit_price;
};
typedef struct items Item;

bool compare(Item a,Item b)
{
    return a.unit_price>b.unit_price;
}

float maximum_profit(Item arr[],int n,int cap)
{
    float profit=0;
    for (int i=0; i<n; i++)
    {
        if(cap>=arr[i].weight)
        {
            cap=cap-arr[i].weight;
            profit=profit+arr[i].price;
        }
        else
        {
            profit=profit+arr[i].price*((float)cap/arr[i].weight);
            break;
        }
    }
    return profit;
}

int main()
{
    int n,cap;
    cin>>n>>cap;
    Item items[n];
    for (int i=0; i<n; i++)
    {
        cin>>items[i].weight;
        cin>>items[i].price;
        items[i].unit_price=(float)items[i].price/items[i].weight;
    }
    sort(items,items+n,compare);
    //for (int i=0;i<n;i++){
    //    cout<<items[i].weight<<" "<<items[i].price<<" "<<items[i].unit_price<<endl;
    //}
    cout<<maximum_profit(items,n,cap);
}

//Input
/*
5 16
5 100
7 500
8 450
4 250
4 350
*/
//Output: 1156.25
