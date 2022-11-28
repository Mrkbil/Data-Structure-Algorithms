#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[],int low,int mid,int high)
{
    int n=mid-low+1;
    int m=high-mid;
    int A[n],B[m];
    int c=0;
    for (int i=low; i<=mid; i++)
    {
        A[c]=arr[i];
        c++;
    }
    c=0;
    for(int i=mid+1; i<=high; i++)
    {
        B[c]=arr[i];
        c++;
    }

    int x=0,y=0;
    int i=low;
    while(x<n && y<m)
    {
        if(A[x]>B[y])
        {
            arr[i]=B[y];
            y++;
        }
        else
        {
            arr[i]=A[x];
            x++;
        }
        i++;
    }
        while(y<m)
        {
            arr[i]=B[y];
            y++;
            i++;
        }
        while(x<n)
        {
            arr[i]=A[x];
            x++;
            i++;
        }
}
void mergeSort(int arr[],int low,int high)
{
    if(high==low)
    {
        return;
    }
    else
    {
        int mid=(high+low)/2;
        mergeSort(arr,mid+1,high);
        mergeSort(arr,low,mid);
        Merge(arr,low,mid,high);
    }
}
int main()
{
    int arr[10]= {1,3,7,3,2,5,9,6,8,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int high=n-1;
    int low=0;
    cout<<"Before Sorting: ";
    for (int i:arr){
        cout<<i<<" ";
    }
    mergeSort(arr,low,high);
    cout<<"\nAfter Sorting: ";
    for (int i:arr){
        cout<<i<<" ";
    }
}
