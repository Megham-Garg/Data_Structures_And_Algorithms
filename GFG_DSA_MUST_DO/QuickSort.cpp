#include <iostream>
using namespace std;
int part(int a[],int low,int high){
    cout<<"low "<<low<<" high "<<high<<endl;
    int i=low-1;
    int pivot=a[high];
    for(int j=low;j<high;j++)
    if(a[j]<=pivot){
        i++;
        swap(a[i],a[j]);
    }
    swap(a[i+1],a[high]);
    cout<<"after iteration\n";
    for(int i=low;i<=high;i++)cout<<a[i]<<" ";
    cout<<endl;
    return i+1;
}
void qsort(int a[],int low,int high){
    if(low<high)
    {
        int pi = part(a,low,high);
        qsort(a,low,pi-1);
        qsort(a,pi+1,high);
    }
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    qsort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
