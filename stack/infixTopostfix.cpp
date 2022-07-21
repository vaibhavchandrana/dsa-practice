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
char pop(stack * &st)
{ 
    char x='\0';
    if(st->top==-1)
    return x;
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
    
}
char stackTop(stack *st)
{
    if(st->top==-1)
    return '\0';
    else return st->s[st->top];
      
}
bool isEmpty(stack *st)
{
    if(st->top==-1)
    return true;
    else
    return false;
}
bool isoperator(char x)
{
    if(x=='+'||x=='*'||x=='/'||x=='-')
    return true;
    else 
    return false;
}
int pre(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
    else 
    return 0;
}
string infixToPost(stack * &st, string exp)
{
    string post="";
    int i=0;
    while(i<exp.length())
    {
        if(isoperator(exp[i]))
        {
            while(pre(exp[i])<=pre(stackTop(st)))
            {
                
                post+=pop(st);
            }
            push(st,exp[i]);
        }
        else 
        {
            post+=exp[i];
        }
        i++;
        
    }
    while(st->top!=-1)
        {
          post+=pop(st);  
        }
    return post;
}
int main()
{
    string exp;
    cout<<"enter your expression : ";
    getline(cin,exp);
    int si=exp.length();
    stack *st=new stack(si);
    cout<<infixToPost(st,exp);
    print(st);
    
}