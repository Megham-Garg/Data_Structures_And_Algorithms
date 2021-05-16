bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2) return 1;
    else if(r1 && !r2) return 0;
    else if(!r1 && r2) return 0;
    else if(r1 && r2)
        return (r1->data == r2->data)
        &&isIdentical(r1->left, r2->left)
        &&isIdentical(r1->right, r2->right);
}
