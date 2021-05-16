#include<iostream>
#include<stack>
using namespace std;


// O(n) space
// O(n) time
bool balancedBrackets(string exp){
    stack<char> bracket;
    for(auto chr : exp){
        if(chr == '{' || chr == '(' ||chr == '[') bracket.push(chr);
        else{
            if(bracket.empty()) return false;
            else if(chr == ']' && bracket.top() == '[') bracket.pop();
            else if(chr == '}' && bracket.top() == '{') bracket.pop();
            else if(chr == ')' && bracket.top() == '(') bracket.pop();
            else return false;
        }
    }
    return (bracket.empty())?true:false;
}

int main(){
    cout << balancedBrackets("[()]{}{[()()]()}") << endl;
    cout << balancedBrackets("[(])") << endl;
    return 0;
}