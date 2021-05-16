Node* reverse(Node * head) 
{
    Node* current = head; 
    Node *prev = NULL, *next = NULL; 

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next; 
    } 
    return prev; 
}
bool isPalindrome(Node *head){
    Node* a;
    Node* b;
    if(!head) return 1;
    a=b=head;
    while(b && b->next) {a= a->next; b = b->next->next;}
    if(b) a = a->next;
    Node* temp; bool f = true;
    temp = reverse(a);
    while(temp) {
        if(head->data!=temp->data) return 0;
        head = head->next; temp = temp->next;
    }return 1;
}
