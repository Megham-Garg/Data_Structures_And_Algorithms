bool detectLoop(Node* head){
 Node *t1 = head;
 Node *t2 = head;
 while(t1 && t2 && t2->next){
  t1=t1-next;
  t2=t2->next->next;
  if(t1==t2) return 1;
 }return 0;
}
