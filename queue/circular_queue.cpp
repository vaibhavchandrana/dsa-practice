#include<iostream>
using namespace std;
class queue{
    public:int size;
    int front,rear;
    int * arr;
    queue(int val)
    {
        size=val;
        front=0;
        rear=0;
        arr= new int [size];
    }    
};
void enqueue(queue *&q,int val)
{
    if((q->rear+1)%q->size==q->front)
    cout<<"queue overflow";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=val;
    }

}
bool isFull(queue *q)
{
    if((q->rear+1)%q->size==q->front)
    return true;
    else 
    return false;
}
int dequeue(queue *q)
{  
    int x=-1;
    if(q->front==q->rear)
    cout<<"queue is empty";
    else{
        q->front=(q->front+1)%q->size;
        x=q->arr[q->front];
    }
    return x;
}
bool isEmpty(queue *q)
{
    if(q->front==q->rear)
    return true;
    else 
    return false;
}
void print(queue *q)
{
    int temp=q->front;
    while(temp!=q->rear)
    {
       
        temp=(temp+1)%q->size;
         cout<<q->arr[temp]<<" ";
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
    dequeue(q);
    dequeue(q);
    cout<<endl<<"after deueue"<<endl;
    print(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    cout<<endl<<"after enueue"<<endl;
    print(q);
}