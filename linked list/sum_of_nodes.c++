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
int sum(node * head)
{
    node*temp=head;
    int s=0;
    while(temp!=NULL)
    {
        s=s+temp->data;     
           temp=temp->next;
    }
    return s;
}
int main()
{
 node * head =NULL; 
 insertTail(head,8);
 insertTail(head,1);
 insertTail(head,10);
 insertTail(head,15);
 insertTail(head,125);
 insertTail(head,300);
 cout<<sum(head);
}