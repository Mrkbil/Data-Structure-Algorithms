#include<bits/stdc++.h>
using namespace std;
void swp(int &x,int &y){
    int tmp=x;
    x=y;
    y=tmp;
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swp(arr[j],arr[j+1]); //per iteration last element will be in correct place
            }
        }
    }
}
void selectionSort(int arr[],int n){
        for(int i=0;i<n-1;i++){
            int mini=arr[i];
            int index=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<mini){
                    mini=arr[j];
                    index=j;
                }
            }
            swp(arr[i],arr[index]);
        }
}
void insertationSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[10]= {1,3,7,3,2,5,9,6,8,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    //bubbleSort(arr,n);
    //selectionSort(arr,n);
    insertationSort(arr,n);
    for (int i:arr){
        cout<<i<<" ";
    }
}
