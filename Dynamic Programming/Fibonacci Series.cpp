#include<iostream>
using namespace std;

int fibo(int arr[],int n){
    if(n==0){
        return arr[0];
    }else if(n==1){
        return arr[1];
    }else{
        if(arr[n-1]==0){
            arr[n-1]=fibo(arr,n-1);
        }
        if(arr[n-2]==0){
            arr[n-2]=fibo(arr,n-2);
        }
        return arr[n-1]+arr[n-2];
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<n; i++)
    {
        arr[i]=0;
    }
    int nth_fibo=fibo(arr,n);
    for(auto x:arr)
    {
        cout<<x<<" ";
    }
    cout<<nth_fibo<<endl;
    cout<<n<<"th Fibonacci Number is: "<<nth_fibo<<endl;
}
