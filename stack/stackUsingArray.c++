#include<iostream>
using namespace std;
class stack{
    public:
    int size;
    int top;
    int * s;
    stack(int si)
    {
        size=si;
        top=-1;
        s=new int[size];
    }
};
void push(stack *st,int val)
{
    if(st->top==st->size-1)
    {
        cout<<"stack overflow";
    }
    else
    {
        st->top++;
        st->s[st->top]=val;
    }
}

void print(stack *st)
{
    int t=st->top;
    while(t!=-1)
    {
        cout<<st->s[t]<<endl;
        t--;
    }
}

int pop(stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        cout<<"stack underflow";
    }
    else
    {
      x=st->s[st->top];
      st->top--;
    }
    return x;
}


int peek(stack *st, int pos)
{
    int x=-1;
    if(pos>=0&&pos<=st->size)
    {
        int ind=st->top-pos+1;
         x=st->s[ind];
    }
    return x;
}


int stackTop(stack *st)
{
    return st->s[st->top];
}

bool isStackFull(stack *st)
{
     if(st->top==st->size-1)
     return true;
     else
     return false;

}
bool isStackEmpty(stack *st)
{
     if(st->top==-1)
     return true;
     else
     return false;

}
int main()
{
    stack *st=new stack(5);
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    push(st,50);
    print(st);
   // cout<<pop(st);
    //print(st);
    cout<<"-----"<<endl;
    //cout<<peek(st,4);
    cout<<stackTop(st);

}
