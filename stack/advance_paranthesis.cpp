#include<iostream>
using namespace std;
class stack{
    public:
    int size;
    int top;
    char *s;
    stack(int si)
    {
        size=si;
        top=-1;
        s=new char[size];
    }
};
void push(stack * &st,char val)
{
    if(st->top==st->size-1)
    cout<<"stack is full";
    else
    st->top++;
    st->s[st->top]=val;

}
void print(stack * st)
{
    while(st->top!=-1)
    {
        cout<<st->s[st->top]<<endl;
        st->top--;
    }
}
void pop(stack * &st)
{
    if(st->top==-1)
    cout<<"empty";
    else
    {
        st->top--;
    }
    
}
bool isEmpty(stack *st)
{
    if(st->top==-1)
    return true;
    else
    return false;
}

bool isBalance(stack * st,string exp,int si)
{
    for(int i=0;i<si;i++)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            push(st,exp[i]);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if(isEmpty(st))
            return false;
            else
            {
              if((int)exp[i]-(int)st->s[st->top]==1||(int)exp[i]-(int)st->s[st->top]==2)
              {
                  pop(st);
              }
              else
              return false;
            }
           
        }
    
    }
    if(isEmpty(st))
    return true;
    else
    return false;
}
int main()
{
    string exp;
    cout<<"enter your expression : ";
    getline(cin,exp);
    int si=exp.length();
    stack *st=new stack(si);
    if(isBalance(st,exp,si))
    {
        cout<<endl<<"matched ";
    }
    else
      cout<<endl<<"notttt  matched ";

}