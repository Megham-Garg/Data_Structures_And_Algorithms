#include <iostream>
using namespace std;
void InsertionSort(int a[],int n){
    int p=1;
    while(p<n){
        if(a[p]<a[p-1]){
            int i=p;
            while(i>0 && a[i]<a[i-1]){swap(a[i],a[i-1]);i--;}
        }
        p++;
    }
}
int main()
{
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    InsertionSort(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
