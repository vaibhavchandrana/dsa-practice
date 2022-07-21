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
void push(stack * &st,int val)
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

int pop(stack *&st)
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
bool isoperand(char x)
{
    if(x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9')
    return true;
    else 
    return false;
}
void evaluate(stack * &st,string exp)
{
    int op1,op2,sym,res;
    for(int i=0;i<exp.length();i++)
    {
      if(isoperand(exp[i]))
      {
          push(st,exp[i]-'0');
      }
      else{
      sym=exp[i];
      op2=pop(st);
      op1=pop(st);
      if(sym=='+')
      {
           res=op1+op2;
           push(st,res);
      }
      else if(sym=='-')
      {
           res=op1-op2;
           push(st,res);
      }
      else if(sym=='*')
      {
           res=op1*op2;
           push(st,res);
      }
      else if(sym=='/')
      {
           res=op1/op2;
           push(st,res);
      }
      
      }
    }
    cout<<"answer is "<<pop(st);
    print(st);
}
int main()
{
    string exp;
    getline(cin,exp);
    int len=exp.length();
    stack *st= new stack(len);
    evaluate(st,exp);

}