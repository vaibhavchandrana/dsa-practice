#include<iostream>
using namespace std;
class node{
    public:int data;
           node * next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void push(node * &top,int val)
{
  node *t =new node(val);
  t->next=top;
  top=t;

}
void print(node * top)
{
    node * temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int pop(node * &top)
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"stack is null";
    }
    else{
        x=top->data;
        node *temp=top;
        top=top->next;
        delete(temp);
    }
    return x;
}

int peek(node * top,int pos)
{
    node * temp= top;
    for(int i=0;i<pos-1  && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    return 
    temp->data;
}
int main()
{
    node * top=NULL;
    push(top,10);
    push(top,20);
    push(top,30);
    push(top,40);
    push(top,50);
    print(top);
  //  cout<<"poped elemet is "<<pop(top)<<endl;
    //print(top);
    cout<<"peeked cale is "<<peek(top,2);
}

