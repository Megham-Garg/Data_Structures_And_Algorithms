#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chech_prime(int x){
    for(int i = 2; i*i < x; i++){
        if(!x%i) return false;
    }
    return true;
}

int main()
{
    int n = 10;
    vector<int> arr(n);
    vector<bool> map(n+1);
    for(int i = 0; i < n+1; i++) map[i]=1;
    map[0]=0;
    map[1]=0;
    for(int i = 2; i*i < n; i++){
        if(map[i]) {
            for(int j = i; j < n+1; j++) map[j]=0;
        }
    }
    for(int i = 0; i < n; i++)
        if(map[i]) cout << i << " ";
    cout << endl;
    return 0;
}
// O(log(log(n)))
