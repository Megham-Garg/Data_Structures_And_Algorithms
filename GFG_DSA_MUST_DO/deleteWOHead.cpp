void deleteNode(Node *node)
{
   Node * temp = node->next;
   node->data = node->next->data;
   node->next = node->next->next;
   delete temp;
}
