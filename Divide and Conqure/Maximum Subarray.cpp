#include<iostream>
using namespace std;

struct Subarray
{
    int low;
    int high;
    int sum;
};
typedef struct Subarray Subarray;

Subarray cross_sum(int arr[],int low,int mid,int high)
{
    int x=low;
    int y=high;
    Subarray sub;
    int max_left,max_right;
    int sum=0;
    int leftsum=-9999;
    for (int i=mid; i>=0; i--)
    {
        sum=sum+arr[i];
        if (leftsum<sum)
        {
            leftsum=sum;
            max_left=i;
        }
    }
    sum=0;
    int rightsum=-9999;
    for (int i=mid+1; i<=high; i++)
    {
        sum=sum+arr[i];
        if (rightsum<sum)
        {
            rightsum=sum;
            max_right=i;
        }
    }
    sub.low=max_left;
    sub.high=max_right;
    sub.sum=leftsum+rightsum;
    return sub;
}

Subarray maximum_subarray(int arr[],int low,int high)
{
    if (high<=low)
    {
        Subarray x;
        x.low=low;
        x.high=high;
        x.sum=arr[high];
        return x;
    }
    else
    {
        int mid=(low+high)/2;
        Subarray a=maximum_subarray(arr,low,mid);
        Subarray b=maximum_subarray(arr,mid+1,high);
        Subarray c=cross_sum(arr,low,mid,high);
        Subarray res;
        if(a.sum>=b.sum && a.sum>=c.sum)
        {
            res.low=a.low;
            res.high=a.high;
            res.sum=a.sum;
        }
        else if(b.sum>=a.sum && b.sum>=c.sum)
        {
            res.low=b.low;
            res.high=b.high;
            res.sum=b.sum;
        }
        else
        {
            res.low=c.low;
            res.high=c.high;
            res.sum=c.sum;
        }
        return res;
    }

}
int main()
{
    int n=10;
    int arr[]= {1,-2,4,-1,-2,5,-2,-2,3,-1};
    Subarray s=maximum_subarray(arr,0,n-1);
    cout<<"Maximum Subarray start: "<<s.low<<" to "<<s.high<<" & sum = "<<s.sum<<endl;
}
