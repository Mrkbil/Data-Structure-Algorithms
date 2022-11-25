#include<bits/stdc++.h>
using namespace std;
void Sort(float arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        float key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n;
    cout<<"Enter number of points:"<<endl;
    cin>>n;
    float arr[n];
    cout<<"Enter points: "<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    Sort(arr,n);
    int num_ofUnitLength=0;
    float current=arr[0];
    float unit_length_current=current+1.0;
    num_ofUnitLength++;
    //cout<<current<<" "<<unit_length_current<<endl;
    for(int i=1;i<n;i++){
        if(unit_length_current<arr[i]){
            current=arr[i];
            unit_length_current=current+1;
            //cout<<current<<" "<<unit_length_current<<endl;
            num_ofUnitLength++;
        }
    }
    cout<<"Output: "<<num_ofUnitLength;
}
