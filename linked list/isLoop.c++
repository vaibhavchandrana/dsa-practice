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

void isLoop(node * head)
{
    node * q;
    node *p;
    q=p=head;
    do{
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:q;
    }while(p&&q&&p!=q);


    if(p==q)
    cout<<" loop exist";
    else 
    cout<<" loop does not exist";
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
//  node *t1=head->next->next;
//  node *t2=head->next->next->next->next;
//  t2->next=t1;

 isLoop(head);
}