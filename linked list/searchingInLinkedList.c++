#include<iostream>
using namespace std;  
class node{
    public: int data;
    public: node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
node * head=NULL;
void insert(node * &head, int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}
void  search(int key,node *p)
{
    node * q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            cout<<"key is found";
            q->next=p->next;
            p->next=head;
            head=p;
        }
        q=p;
        p=p->next;
    }
  }
  void display(node * head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" --->";
        temp=temp->next;
    }
}
int main()
{
    
    insert(head,10);
    insert(head,5);
    insert(head,15);
    insert(head,9);
    insert(head,11);
    insert(head,20);
    cout<<"diplay before search"<<endl;
    display(head);
    search(15,head);
    cout<<"diplay after search"<<endl;
    display(head);
}