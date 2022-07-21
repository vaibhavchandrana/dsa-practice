#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insert(node * &head,int val)
{
    node * n=new node(val);
    if(head==NULL)
    {
        head=n;
    }
    else
    {
    node * temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    }
}
void circular(node * head)
{
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
}

void display(node * head)
{
    
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    
}
void circularDisplay(node * head)
{
   node * temp=head; 
   do{
       cout<<temp->data<<" ->";
       temp=temp->next;
   }while(temp!=head);
    
}
void deletionAtbegin( node * &head)
{
  node *p=head->next;
  node *q=head;
  while(p->next!=head)
  {
      p=p->next;
  }
    p->next=head->next;
    head=head->next;
    delete(q);


}
void deletionAtMiddle(node * head,int val)
{
    node *p=head;
    node *temp=head->next;
     node * q=NULL;
     while(temp->next!=head)
     {
         if(p->data!=val)
         {
             q=p;
             p=p->next;
             
         }
         else{
             q->next=p->next;
             delete(p);
         }
           temp=temp->next;
     }
}
int main()
{
    node * head=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    insert(head,60);
    circular(head);
    circularDisplay(head);
    cout<<endl<<" after removing head"<<endl;
   // deletionAtbegin(head);
    deletionAtMiddle(head,40);
    circularDisplay(head);
    
    
}