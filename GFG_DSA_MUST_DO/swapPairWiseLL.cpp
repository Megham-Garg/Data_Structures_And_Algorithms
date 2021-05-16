Node* pairWiseSwap(struct Node* head) {
    Node* cur = head;
    while(cur && cur->next){
        int temp = cur->next->data;
        cur->next->data = cur->data;
        cur->data = temp;
        cur = cur->next->next;
    }
    return head;
}
