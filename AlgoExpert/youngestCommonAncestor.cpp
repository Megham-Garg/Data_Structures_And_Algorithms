char youngAncestorCommon(Node* x, Node* y){
    map<Node*, bool> visited;
    while(x->ancestor){
        visited[x]=1;
        x = x->ancestor;
    }
    while(!visited[y]) y = y->ancestor;
    return y->data;
}  
// O(max (depth(x), depth(y))) space and time

char youngAncestorCommon_v2(Node* x, Node* y){
    Node* first = x;
    Node* sec = y;
    int a = 0, b = 0;
    while(x){
        a++;
        x = x->ancestor;
    }
    while(y){
        b++;
        y = y->ancestor;
    }
    
    while(first != sec){
        if(a > b) {first = first->ancestor; a--;}
        else if(b > a) {sec = sec->ancestor; b--;}
        else{sec = sec->ancestor; first = first->ancestor;}
    }

    return first->data;
}  
// O(max (depth(x), depth(y))) time
// O(1) space