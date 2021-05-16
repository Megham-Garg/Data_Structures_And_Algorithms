#include <iostream>
using namespace std;
int binarySearch(int a[],int low,int high,int key)
{
    if(low==high)
        if(a[low]==key)return low;
        else return -1;
    else
    {
        int mid=(low+high)/2;
        if(a[mid]==key)return mid;
        else if(a[mid]<key) binarySearch(a,mid+1,high,key);
        else binarySearch(a,low,mid-1,key);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int key;cin>>key;
    int i=binarySearch(a,0,n-1,key);
    if(i!=-1)cout<<"key found at index: "<<i;
    else cout<<"key not found";
    return 0;
}
