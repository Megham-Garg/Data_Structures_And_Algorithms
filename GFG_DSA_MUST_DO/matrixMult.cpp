#include <iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    int a1[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a1[i][j];
    int res[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        res[i][j]=0;
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cout<<res[i][j]<<" ";cout<<endl;}
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
        res[i][j]+=a[i][k]*a1[k][j];
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cout<<res[i][j]<<" ";cout<<endl;}
    return 0;
}
