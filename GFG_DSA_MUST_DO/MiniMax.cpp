#include <iostream>
#include<limits.h>
using namespace std;
int minInd=INT_MAX,maxInd=INT_MIN;
int great(int a,int b){
    if(a>b)return a;
    return b;
}
int small(int a,int b){
    if(a<b)return a;
    return b;
}
void miniMax(int a[],int st,int en)
{
    cout<<st<<" ** "<<en<<endl;
    int mid=(en+st)/2;
    if(en-st>1){
        miniMax(a,st,mid);
        miniMax(a,mid+1,en);
    }
    else{
        int a1[2]={0};
        a1[0]=a[st];
        if(en-st==1){
            a1[1]=a[en];
            maxInd=great(maxInd,great(a1[0],a1[1]));
            minInd=small(minInd,small(a1[0],a1[1]));
        }
        else{
            maxInd=great(maxInd,a1[0]);
            minInd=small(minInd,a1[0]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    miniMax(arr,0,n-1);
    cout<<minInd<<" "<<maxInd;
    return 0;
}
