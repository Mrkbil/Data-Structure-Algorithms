#include<iostream>
using namespace std;

struct Pair{
    int mini;
    int maxi;
};

typedef struct Pair Pair;

Pair Minmax(int arr[],int low,int high){
    if(high<=low){
        Pair p;
        p.mini=arr[low];
        p.maxi=arr[low];
        return p;
    }else{
        int mid=(low+high)/2;
        Pair a=Minmax(arr,low,mid);
        Pair b=Minmax(arr,mid+1,high);
        Pair ab;
        if(a.maxi>=b.maxi){
            ab.maxi=a.maxi;
        }else{
            ab.maxi=b.maxi;
        }
        if(a.mini<=b.mini){
            ab.mini=a.mini;
        }else{
            ab.mini=b.mini;
        }
        return ab;

    }
}
int main()
{
    int n=10;
    int arr[]= {12,34,67,23,67,98,23,56,25,38};
    Pair min_max=Minmax(arr,0,n-1);
    cout<<"Minimum and Maximum numbers are : "<<min_max.mini<<" "<<min_max.maxi<<endl;
}
