#include<iostream>
using namespace std;
class node{
    public:
    node * lchild;
    int data;
    node * rchild;
    node(int val)
    {
        data=val;
        lchild=rchild=NULL;

    }
};


void insert(node * p,int key)
{
    node * t,*r=NULL;
    while(p!=NULL)
    {
        r=p;
        if(key==p->data)
        return;
        else if(key<p->data)
        {
            p=p->lchild;
        }
        else{
               p=p->rchild;
        }
    }
    t=new node(key);
    if(t->data<r->data)
    {
        r->lchild=t;
    }
    else
    r->rchild=t;

    
}

void inorder(node * p)
{
    if(p!=NULL)
    {
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
    }
}
int main()
{
   node * root=new node(30);
   insert(root,20);
   insert(root,40);
   insert(root,10);
   insert(root,25);
   insert(root,35);
   insert(root,50);
   insert(root,38);
   inorder(root);
}