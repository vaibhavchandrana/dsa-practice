#include<iostream>
using namespace std;
class node{
    public :int data;
   public: node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertTail(node * &head,int val){
    node* n =new node(val);
    
    if(head==NULL)
    {
        head=n;
        return;
    }
    node*temp=head;
   while(temp->next!=NULL)
   {
       temp=temp->next;
   }
   temp->next =n;

}
void display(node * head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void removedup(node * head)
{
    node * p=head;
    node *q=head->next;
    while(p&&q)
    {
        
        if(p->data==q->data)
        {
            p->next=q->next;

        }
        p=p->next;
        q=p->next;
    }
}
int main()
{
 node * head =NULL; 
 insertTail(head,8);
 insertTail(head,1);
 insertTail(head,1);
 insertTail(head,15);
 insertTail(head,125);
 insertTail(head,300);
 display(head);
 removedup(head);
 cout<<endl;
 display(head);
}