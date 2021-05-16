#include<iostream>
using namespace std;
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 
void merge(int *arr1, int *arr2, int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    {
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
        if (j < m) 
        { 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
} 
int main()
 {
	int testCases = 0;
	cin >> testCases;
	for(int i =1 ; i<=testCases ;i++)
	{
	    int s1;cin>>s1; int a1[s1]={0};
	    int s2;cin>>s2; int a2[s2]={0};
	    for(int j=0; j<s1; j++) cin>>a1[j]; for(int j=0; j<s2; j++) cin>>a2[j];
        merge(a1,a2,s1,s2);
        for(int j=0; j<s1; j++) cout<<a1[j]<<" "; for(int j=0; j<s2; j++) cout<<a2[j]<<" ";
        cout<<"\n";
	}
	return 0;
}
