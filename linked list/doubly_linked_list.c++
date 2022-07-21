#include<iostream>
using namespace std;
class node{
    public:
    node * prev;
    int data;
    node * next;
    node (int val)
    {
        prev=NULL;
        data=val;
        next=NULL;
    }
};
void create(node * & head,int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
    }
    else{
        node * temp=head;
        node * q=head;
        while(temp->next!=NULL)
        {
           q=temp->next;
           temp=temp->next;
        }
        temp->next=n;
        temp=temp->next;
        temp->prev=q;
    }
}

void display(node * head)
{
    node * temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void ulta(node * head)
{
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node * last=temp;
    while(last!=NULL)
    {
         cout<<last->data<<" ";
         last=last->prev;
    }

}

void deleteAtBegin(node *&head)
{
    node * p=head;
    head=head->next;
    head->prev=NULL;
    delete(p);
}
void deletionAtMiddle(node * head,int val)
{
    node * temp=head;
    node * q;
   
    while(temp->data!=val)
    {
        temp=temp->next;
    }
     node *t=temp;
    if(temp->next!=NULL)
    {
    q=temp->prev;
    q->next=temp->next;
    temp=temp->next;
    temp->prev=q;
    delete(t);
    }
    else
    { 
     node * d= temp->prev;
     d->next=NULL;
     delete(temp);
    }
}
int main()
{
    node *head=NULL;
    create(head,6);
    create(head,10);
    create(head,15);
    create(head,20);
    create(head,30);
    display(head);
    cout<<endl<<" ulta hone se phle"<<endl;
    ulta(head);
     cout<<endl<<"phla eleemnt delete krne se baad"<<endl;
      deletionAtMiddle(head,30);
     display(head);
    cout<<endl<<" ulta hone se phle"<<endl;
    ulta(head);
}