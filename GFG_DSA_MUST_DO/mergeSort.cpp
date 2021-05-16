#include <iostream>
using namespace std;
void merge(int a[],int low,int mid,int high)
{
    int n1=mid-low+1, L[n1];
    int n2=high-mid, R[n2];
    for(int i=0;i<n1;i++)L[i]=a[i+low];
    for(int i=0;i<n2;i++)R[i]=a[i+mid+1];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(L[i]<R[j])a[k]=L[i++];
        else a[k]=R[j++];
        k++;
    }
    while(i<n1)a[k++]=L[i++];
    while(j<n2)a[k++]=R[j++];
}
void mergeSort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
