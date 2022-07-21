#include<bits/stdc++.h>
using namespace std;
class node{
    public: node * lchild;
    int data;
          node * rchild;
          node(int val)
          {
              lchild=NULL;
              rchild=NULL;
              data=val;
          }
};
node * createNode(int val)
{
     node *temp = new node(val);
     return temp;
}
 void preorder(node * t)
 {
     if(t!=NULL)
     {
         cout<<t->data<<" ";
         preorder(t->lchild);
         preorder(t->rchild);
     }
 }
 void inorder(node * t)
 {
     if(t!=NULL)
     {
          inorder(t->lchild);
         cout<<t->data<<" ";
         inorder(t->rchild);
     }
 }
  
   void postorder(node * t)
 {
     if(t!=NULL)
     {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
     }
 }

 void iterative_prreorder(node * t)
 {
         stack<node *> st;
         while(t!=NULL|| !st.empty())
         {
             if(t!=NULL)
             {
             cout<<t->data<<" ";
             st.push(t);
             t=t->lchild;
             }
             else
             {
                
                t=st.top();
                st.pop();
                t=t->rchild;

             }

         }
 }

void iterative_inorder(node * t)
 {
         stack<node *> st;
         while(t!=NULL|| !st.empty())
         {
             if(t!=NULL)
             {
             
             st.push(t);
             t=t->lchild;
             }
             else
             {
                 t=st.top();
                cout<<t->data<<" ";
                st.pop();
                t=t->rchild;

             }

         }
 }
void iterative_postorder(node * t)
 {
         stack<node *> st;
         long long int temp;
         while(t!=NULL|| !st.empty())
         {
             if(t!=NULL)
             {
             
             st.push(t);
             t=t->lchild;
             }
             else
             {
                 
                 temp = (long long int)st.top();
                 st.pop();
                 if(temp>0)
                 { 
                    temp=0-(long long int)st.top();
                    st.push((node*)temp);
                    t=((node*)temp)->rchild;
                 }
                 else {
                     cout<<((node *)temp)->data;
                     t=NULL;
                 }
             }

         }
 }

 void level_order( node * t)
 {
      queue<node *>q;
      q.push(t);
      while(!q.empty())
      {
          t=q.front();
          q.pop();
          cout<<t->data<<" ";
          if(t->lchild)
          {
            q.push(t->lchild);
          }
          if(t->rchild)
          {
            q.push(t->rchild);
          }
      }
 }

 int height (node * p)
 {
     int x,y;
     if(p!=NULL)
     {
         x=height(p->lchild);
         y=height(p->rchild);
          if(x>y)
          return x+1;
          else
          return y+1;
     }
     return 0;
 }
int main()
{
    node *root=createNode(8);
    root->lchild=createNode(3);
    node  * t=root->rchild=createNode(5);


    root->lchild->lchild=createNode(12);
    root->lchild->lchild->rchild=createNode(4);
    root->lchild->lchild->rchild->lchild=createNode(9);
    root->lchild->lchild->rchild->rchild=createNode(7);
    root->rchild->lchild=createNode(10);
    root->rchild->rchild=createNode(6);
    root->rchild->rchild->lchild=createNode(2);
    preorder(root); 
    cout<<endl<<"inorder is ";inorder(root);
    cout<<endl<<"postorder is ";postorder(root);
    cout<<endl<<"iterative preorder is ";iterative_prreorder(root);
    cout<<endl<<"iterative inorder is ";iterative_inorder(root);
    cout<<endl<<"iterative levelorder is ";level_order(root);

    cout<<endl<<height(root);


}