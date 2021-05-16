#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void printKMax(int arr[], int n, int k) 
{
    std::deque<int> Qi(k);
    int i; 
    for (i = 0; i < k; ++i) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); // Remove from rear 
        Qi.push_back(i); 
    } 
  
    for (; i < n; ++i) { 
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k) 
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
        Qi.push_back(i); 
    }
    cout << arr[Qi.front()] << "\n"; 
}
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n,k; cin >> n >> k;
	    int a[n]={0};
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    printKMax(a, n, k);
	}
	return 0;
}
