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
void concat(node *& head1,node * &head2)
{
    node * temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    head2=NULL;
}
int main()
{
    node * head=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);

    node * head2=NULL;
    insert2(head2,11);
    insert2(head2,12);
    insert2(head2,13);
    insert2(head2,14);
    concat(head,head2);
    display(head);
}