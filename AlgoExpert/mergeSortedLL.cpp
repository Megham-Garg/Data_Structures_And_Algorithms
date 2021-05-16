Node* mergeSortedLL(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    Node* prevB = b, temp = NULL;
    while(a && b){
        if(a->data >= b->data) {prevB = b; b = b->next;}
        else{
            prevB->next = a;
            while(a->next && a->next->data < b->data) a = a->next;
            temp = a->next;
            if(b != prevB) a->next = b;
            a = temp;
        }
    }return b;
}//O(1) space
// O(n+m) time