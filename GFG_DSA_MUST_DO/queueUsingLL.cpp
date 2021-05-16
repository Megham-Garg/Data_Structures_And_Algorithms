/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x){
    QueueNode* node = new QueueNode(x);
    if(!front && !rear){ front = node; rear = node; return;}
    rear->next = node;
    rear = node;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop(){
    if(!front && !rear) return -1;
    int x = front->data;
    if(front->next) front = front->next;
    else {front = NULL; rear = NULL;}
    return x;
}
