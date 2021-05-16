#include <iostream>

using namespace std;

class Node{
    int data;
public:
    Node* next;
    Node(){}
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
    int getData(){return this->data;}
};

class LinkedList{
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void AppendNode(int data){
        Node *newNode = new Node(data,NULL);
        if(!head)
            head = newNode;
        else
        {
            Node* curr = head;
            while(curr->next)
            {
                curr=curr->next;
            }
            curr->next = newNode;
        }
    }
    void displayList(void){
        Node* curr = head;
        cout<<"list : ";
        while(curr){
                cout<<curr->getData()<<" ";
                curr=curr->next;
        }cout<<endl;
    }
    void deleteAltNodes(void){
        Node* curr = head;
        while(curr->next && curr){
            Node* temp = curr->next;
            curr->next=curr->next->next;
            delete temp;
            if(curr->next)curr=curr->next;
        }
    }
    int NodeCount(void){
        int total=0;
        Node* curr = head;
        while(curr){
                total++;
                curr=curr->next;
        }
        return total;
    }
    int sumLastN(int N){
        int hop=NodeCount()-N;
        Node* curr = head;
        while(hop--){
            curr=curr->next;
        }
        int sum=0;
        while(curr){
            sum+=curr->getData();
            curr=curr->next;
        }
        return sum;
    }
    Node* getHead(void){return head;}
    void setHead(Node* head){this->head=head;}
    void reverseLinkedList(){
        Node* t1 = NULL;
        Node* t2;
        Node* t3;
        if(head) t2=head;
        else t2=NULL;
        if(head->next) t3 = head->next;
        else t3 = NULL;
        while(t2){
            if(t1) t2->next = t1;
            else t2->next = NULL;
            t1=t2;
            if(t3)t2=t3;
            else t2=NULL;
            if(t3) t3=t3->next;
            else t3=NULL;
        }
        head=t1;
    }
};

bool areIdentical(Node *head1, Node *head2){
    bool flag=true;
    Node* curr1 = head1;
    Node* curr2 = head2;
    while((curr1 || curr2) && flag){
        if(!(curr1 && curr2)) flag = false;
        else{
            if(curr1->getData() != curr2->getData()) flag = false;
            else{
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }
    }
    return flag;
}

class Stack : public LinkedList{
    Node* top;
    using LinkedList::deleteAltNodes;
    using LinkedList::AppendNode;
public:
    Stack():LinkedList(){
        top=getHead();
    }
    void push(int data){
        AppendNode(data);
        top = getHead();
        while(top->next){top=top->next;}
    }
    int pop(void){
        Node* curr = getHead();
        if(!curr){
            cout<<"\nempty stack\n";
            return -1;
        }
        while(curr->next->next){
                curr=curr->next;
        }
        Node* temp;
        if(curr->next)temp=curr->next;
        else{
            int d = curr->getData();
            delete curr;
            return d;
        }
        curr->next=NULL;
        int d=temp->getData();
        delete temp;
        top = curr;
        return d;
    }
};

class Queue : public LinkedList{
    Node* front;
    Node* rear;
    using LinkedList::deleteAltNodes;
    using LinkedList::AppendNode;
public:
    Queue():LinkedList(){
        front=getHead();
        rear=getHead();
    }
    void push_rear(int data){
        AppendNode(data);
        rear = getHead();
        front =  getHead();
        while(rear->next){rear=rear->next;}
    }
    int pop_front(void){
        if(!front){
            cout<<"\nempty queue\n";
            return -1;
        }
        Node* temp = front;
        if(front==rear){
            delete temp;
            return front->getData();
        }
        front = front->next;
        setHead(front);
        int d = temp->getData();
        delete temp;
        return d;
    }
};

Node* addTwoLists_asNumbers(Node* first, Node* second) {
    LinkedList result;
    if(first==NULL && second==NULL) return result.getHead();
    int carry=0;
    while(first || second){
        int i=0;
        if(first) i+=first->getData();
        if(second) i+=second->getData();
        if(carry) i+=carry;
        carry=0;
        result.AppendNode(i%10);
        carry = i/10;
        if(first && first->next)first=first->next;
        else first=NULL;
        if(second && second->next)second=second->next;
        else second=NULL;
    }
    if(carry)
        result.AppendNode(carry);
    return result.getHead();
}

Node* rotateLinkedList(Node* head, int k) {
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next = head;
    temp=head;
    Node* prev = head;
    while(k--){
        temp=temp->next;
        if(k==0) prev->next=NULL;
        else prev=prev->next;
    }
    return temp;

}
int main()
{
    LinkedList l1;
    l1.AppendNode(8);
    l1.AppendNode(9);
    l1.AppendNode(3);/*
    l1.AppendNode(2);
    l1.AppendNode(1);*/

    LinkedList l2;
    l2.AppendNode(9);
    l2.AppendNode(2);
    l2.AppendNode(8);/*
    l2.AppendNode(2);
    l2.AppendNode(3);*/

    LinkedList l3;
    l3.setHead(addTwoLists_asNumbers(l1.getHead(),l2.getHead()));
    l1.displayList();
    l2.displayList();
    l3.displayList();
/*
    Stack s1;
    s1.push(456);
    s1.push(46);
    s1.push(45);
    s1.push(56);
    s1.displayList();
    cout<<"after stack pop  "<<s1.pop()<<endl;
    s1.displayList();
    cout<<endl;

    Queue q1;
    q1.push_rear(456);
    q1.push_rear(46);
    q1.push_rear(45);
    q1.push_rear(56);
    q1.displayList();
    cout<<"after queue pop  "<<q1.pop_front()<<endl;
    q1.displayList();

    cout<<"\nreversed linked ";
    q1.reverseLinkedList();
    q1.displayList();
*/
    return 0;
}
