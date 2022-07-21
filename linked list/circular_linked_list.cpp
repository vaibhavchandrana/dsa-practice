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
void recDisplay(node * temp,node * head)
{
    static int flag=0;
    if(temp!=head || flag==0)
    {
        flag=1;
        cout<<temp->data<<" ";
        recDisplay(temp->next,head);

    }
    else
    return;

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
    display(head);
    circular(head);
    circularDisplay(head);
    cout<<endl<<"By recursion";
    recDisplay(head);
    
}