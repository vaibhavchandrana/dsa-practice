#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node * next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
 void insert(node * & head,int val)
 {
   node * n=new node(val);
   if(head==NULL)
   {
       head=n;
   }
   else
   {
       node * temp=head;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=n;
   }
 }
  void insert2(node * & head2,int val)
 {
   node * n=new node(val);
   if(head2==NULL)
   {
       head2=n;
   }
   else
   {
       node * temp=head2;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=n;
   }
 }
void display(node *head)
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void merge(node *& first,node * &second)
{
    node * third;
    node *last;
    if(first->data<second->data)
    {
       third= first;
       last=first;
       first=first->next;
       last->next=NULL;
    }
    else{
          
       third= second;
       last=second;
       second=second->next;
       last->next=NULL;
    }
    while(first!=NULL&&second!=NULL)
    {
        if(first->data<second->data)
        {
        last->next=first;
        last=first;
        first=first->next;
        last->next=NULL;
        }
        else{
        last->next=second;
        last=second;
        second=second->next;
        last->next=NULL;
        }
    }
    if(first!=NULL)
    {
        last->next=first;
    }
    if(second!=NULL)
    {
        last->next=second;
    }
    display(third);
}
int main()
{
    node * head=NULL;
    insert(head,2);
    insert(head,8);
    insert(head,10);
    insert(head,15);
    insert(head,16);

    node * head2=NULL;
    insert2(head2,4);
    insert2(head2,7);
    insert2(head2,12);
    insert2(head2,14);
    merge(head,head2);
    

}