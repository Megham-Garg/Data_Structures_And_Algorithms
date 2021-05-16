class Solution{
	public:
	using ll  = unsigned long long int ;
	ll powm(ll x,ll n,ll M){
		    ll result=1;
		    while(n>0)
		    {
		        if(n % 2 ==1)
		            result=(result * x)%M;
		        x=(x*x)%M;
		        n=n/2;
		    }
		    return result;
	}
   	int Nth_term(int a, int r, int n){
   		ll mod = 1e9 + 7;
   		ll res = powm(r, n-1, mod);
   		res *= a;
   		res %= mod;
   		return int(res);
   	}    
};

// task is to complete the function Nth_term() which takes A, R and N as input parameter ans returns Nth term of the GP series modulo 109 + 7.