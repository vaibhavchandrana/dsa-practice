#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void enqueue(node *&front, node * &rear,int val )
{
    node *t= new node(val);
    if(t==NULL)
    {
        cout<<"queue is full";
    }
    else{
        if(front==NULL)
        {
            front=rear=t;
        }
        else 
        {
            rear->next=t;
            rear=t;
        }
    }
}

void print(node * front, node * rear)
{
    node * temp=front;
    while(temp!=rear->next)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int dequeue(node * &front)
{
    int x=-1;
    node * temp;
    if(front==NULL)
    cout<<"queue empty";
    else{
        temp=front;
        x=front->data;
        front=front->next;
        delete(temp);
    }
    return x;
}
int main()
{
    node * front,*rear;
    front=rear=NULL;
    enqueue(front,rear,10);
    enqueue(front,rear,20);
    enqueue(front,rear,30);
    enqueue(front,rear,40);
    enqueue(front,rear,50);
    enqueue(front,rear,60);
    print(front,rear);
    dequeue(front );
    dequeue(front);
    cout<<endl<<" after dequeue"<<endl;
    print(front,rear);
    
}