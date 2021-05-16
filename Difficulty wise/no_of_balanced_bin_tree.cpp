#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (pow(10,9)+7)
ll totslBalanced(ll h, ll* cache){
    if(cache[h]) return cache[h];
    ll n1=0, n2=0;
    if(cache[h-1]) n1 = cache[h-1];
    else {
        n1 = totslBalanced(h-1, cache);
        cache[h-1] = n1;
    }
    if(cache[h-2]) n2 = cache[h-2];
    else {
        n2 = totslBalanced(h-2, cache);
        cache[h-2] = n2;
    }
    cache[h] =  ((n1*n1)%MOD + (2*n1*n2)%MOD)%MOD;
    return cache[h];
}
int main()
{
    ll h=5, cache[11]={0};
    cache[0]=1;
    cache[1]=1;
    cout << totslBalanced(h, cache);
    return 0;
}
