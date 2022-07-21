#include<iostream>
using namespace std;
class queue{
    public:int size;
    int front;
    int rear;
    int * arr;
    queue(int val)
    {
        size=val;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

};

bool isFull(queue * q)
{
    if(q->rear==q->size-1)
    return true;
    else 
    return false;
}

bool isEmpty(queue * q)
{
    if(q->rear==q->size)
    return true;
    else 
    return false; 
}

void enqueue(queue * &q,int val)
{
    if(isFull(q))
    {
        cout<<"queue overflow";
    }
    else 
    {
        q->rear++;
        q->arr[q->rear]=val;
    }

}
int dequeue(queue * &q)
{
    int x=-1;
    if(isEmpty(q))
    cout<<"queue underflow";
    else
    {
        q->front++;
        x=q->arr[q->front];
    }
    return x;

}
void print(queue * &q)
{
    int i=q->front+1;
    while(i<=q->rear)
    {
        cout<<q->arr[i]<<"  ";
        i++;
    }
}
int main()
{
    int size;
    cout<<"enter the size";
    cin>>size;
    queue *q=new queue(size);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    print(q);
    cout<<"after dequeue";
    cout<<endl<<"element removed is "<<dequeue(q)<<endl;
    cout<<endl<<"element removed is "<<dequeue(q)<<endl;

    print(q);
}