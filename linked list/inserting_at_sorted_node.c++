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
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void insertsort(node * head,int val)
{
    node * p=head;
    node * q=NULL;

    node * n=new node(val);
    while(p!=NULL)
    {
        if(p->data <val)
        {
         q=p;
         p=p->next;
        }
        else
        {
            
            q->next=n;
            n->next=p;
            break;
        }
    }
}
int main()
{
 node * head =NULL; 
 insertTail(head,1);
 insertTail(head,3);
 insertTail(head,10);
 insertTail(head,15);
 insertTail(head,20);
 insertTail(head,30);
 display(head);
 insertsort(head,21);
 cout<<"-------------------------------------------";
 display(head);
}