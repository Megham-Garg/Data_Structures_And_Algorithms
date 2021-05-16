#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
void removeNthfromEnd(Node* root, int n){
    Node* f,s;
    f=root;
    s=root;
    while(n && s){
        s = s->next;
        n--;
    }
    if(n) {cout << "Insufficient nodes in linked list"; return;}
    if(s->next==NULL) {
        cout << "Trying to delete root node";
        if(root->next){
            root->data = root->next->data;
            root->next = root->next->next;
        }
        else{
            root = NULL;
        }
        return;
    }
    while(s->next) {
        s=s->next;
        f=f->next;
    }
    f->next = f->next->next;
    return;
}