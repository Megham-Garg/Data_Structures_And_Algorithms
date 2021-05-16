void StackQueue :: push(int x){ s1.push(x); }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop(){
    while(!s1.empty()) {s2.push(s1.top()); s1.pop();}
    int ans = -1;
    if(!s2.empty()) {ans = s2.top(); s2.pop();}
    while(!s2.empty()) {s1.push(s2.top()); s2.pop();}
    return ans;
}
