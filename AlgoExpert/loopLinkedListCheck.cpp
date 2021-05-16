#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
Node* loopCheck(Node* root){
    Node* f,s;
    f=root;
    s=root;
    while(f && s->next){
        s = s->next->next;
        f = f->next;
        if(f==s) break;
    }
    if(!f) return f;
    f = root;
    while(f != s){
        f = f->next;
        s = s->next;
    }
    return f;
}