#include <bits/stdc++.h>
using namespace std;

// O(1) time operations
// O(n) space
class minMaxStack{
    vector<int> my_stack;
    vector<int> minStack;
    vector<int> maxStack;
public:
    minMaxStack(){
        my_stack = {};
        minStack = {};
        maxStack = {};
    }
    void push(int data){
        my_stack.push_back(data);
        if(minStack.size() == 0 || minStack.back() >= data){
            minStack.push_back(data);
        }
        if(maxStack.size() == 0 || maxStack.back() <= data){
            maxStack.push_back(data);
        }
    }
    int pop(){
        if(my_stack.size()==0) return INT_MIN;
        if(minStack.back() == my_stack.back()){
            minStack.pop_back();
        }
        if(maxStack.back() == my_stack.back()){
            maxStack.pop_back();
        }
        int data = my_stack.back();
        my_stack.pop_back();
        return data;
    }
    int peek(){
        if(my_stack.size()==0) return INT_MIN;
        return my_stack.back();
    }
    int getMin(){
        if(minStack.size()==0) return NULL;
        return minStack.back();
    }
    int getMax(){
        if(maxStack.size()==0) return NULL;
        return maxStack.back();
    }
    void show(){
        for(auto ele : my_stack){
            cout << ele << " ";
        }cout << "\n";
    }
};

int main()
{
    minMaxStack* stk = new minMaxStack();
    stk->push(5);
    cout << stk->peek() << " " << stk->getMax() << " " << stk->getMin() << "\n";
    stk->push(7);
    cout << stk->peek() << " " << stk->getMax() << " " << stk->getMin() << "\n";
    stk->push(2);
    cout << stk->peek() << " " << stk->getMax() << " " << stk->getMin() << "\n";
    return 0;
}
