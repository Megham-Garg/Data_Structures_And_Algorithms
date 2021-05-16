#include <iostream>
using namespace std;
int part(int a[],int low,int high){
    int i=low-1;
    int pivot=a[high];
    for(int j=low;j<high;j++)
    if(a[j]<=pivot){
        i++;
        swap(a[i],a[j]);
    }
    swap(a[i+1],a[high]);
    return i+1;
}
int KthSmall(int a[],int low,int high,int k){
    if(low==high){
        if(high==k) return  a[k];
        else return -1;
    }
    else
    {
        int pi = part(a,low,high);
        if(pi==k)return a[pi];
        else{
            if(pi>k) KthSmall(a,low,pi-1,k);
            else KthSmall(a,pi+1,high,k);
        }
    }
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k;cin>>k;
    int x=KthSmall(a,0,n-1,k-1);
    cout<<k<<" smallest = "<<x;
    cout<<endl;
    return 0;
}
