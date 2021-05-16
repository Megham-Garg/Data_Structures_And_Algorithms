#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class LRUCache{
    int maxSize;
    int pageFaults;
    list<int> dq;
    unordered_map<int, list<int> :: iterator> ma; 
public:
     LRUCache(int N)
    {
        maxSize = N;
        pageFaults = 0;
        dq.clear();
        ma.clear();
    }
    void set(int x) 
    {
         if(ma.find(x) == ma.end())
        {
           pageFaults+=1;
           if(dq.size() == maxSize)
           {
               int Lx = dq.back();
               dq.pop_back();
               dq.push_front(x);
               ma.erase(Lx);
               ma[x] =dq.begin();
           }
           else{
                dq.push_front(x);
                ma[x] = dq.begin();
           }
        }
        else{
            auto it = ma.find(x);
            dq.erase(it->second);
            dq.push_front(x);
            ma[x]=dq.begin();
        }
    }
    int getPF(){return pageFaults;}
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> n;
	    int pageFaults = 0;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    cin >> k;
	    LRUCache L(k);
	    for(auto ele : a) L.set(ele);
	    cout << L.getPF() << "\n";
	}
	return 0;
}
