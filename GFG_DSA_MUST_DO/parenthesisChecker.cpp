#include<bits/stdc++.h> 
using namespace std; 
bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 
	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
		{
			s.push(expr[i]); 
			continue; 
		}
		
		if (s.empty()) return false; 

		switch (expr[i]) 
		{ 
		case ')': 
			x = s.top(); 
			s.pop(); 
			if (x=='{' || x=='[') 
				return false; 
			break; 

		case '}':
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='[') 
				return false; 
			break; 

		case ']':
			x = s.top(); 
			s.pop(); 
			if (x =='(' || x == '{') 
				return false; 
			break; 
		} 
	}
	
	return (s.empty()); 
} 

int main() 
{ 
    int testCases = 0;
	cin >> testCases;
	for(int j =1 ; j<=testCases ;j++)
	{
	    string expr;cin>>expr;
	    if (areParanthesisBalanced(expr)) 
		    cout << "balanced\n"; 
	    else
		    cout << "not balanced\n"; 
	}
	return 0; 
} 
