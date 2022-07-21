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
void isSorted(node *head)
{
    node*p=head;
    node*q=p->next;
    int flag=0;
    while(q!=NULL)
    {
        if(p->data > q->data)
        {
            flag =1;
        }
        p=p->next;
        q=q->next;
    }
     (flag==0)?cout<<"sorted":cout<<"not sorted";
}
int main()
{
 node * head =NULL; 
 insertTail(head,0);
 insertTail(head,1);
 insertTail(head,10);
 insertTail(head,15);
 insertTail(head,125);
 insertTail(head,300);
 display(head);
 isSorted(head);
}