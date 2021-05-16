int middleEleLL(Node* head){
  Node* h1=head;
  Node* h2=head;
  if(!head)return -1;
  while(h1 && h2 && h2->next){
    h1=h1->next;
    h2=h2->next->next;
  }
  return h1->data;
}
