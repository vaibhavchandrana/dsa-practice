#include<iostream>
using namespace std;
class stack{
    public:int size;
         int top;
         char * s;
    stack(int val)
    {
        size=val;
        top=-1;
        s=new char[size];
    }
    void push(char val)
    {
        if(top==size-1)
        cout<<"stack is full";
        else
        {
            top++;
            s[top]=val;
        }
    }
    void print()
    {
        int temp=top;
        while(temp!=-1)
        {
            cout<<s[temp]<<endl;
            temp--;
        }
    }
    char pop()
    {
        char x='\0';
        if(top==-1)
        {
            cout<<"empty";
            return x;
        }
        
        else
        {
          x=s[top];
          top--;
        }
        return x;
    }
};

bool isoperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^')
    return true;
    else 
    return false;
}
int outpre(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 3;
    else if(x=='^')
    return 6;
    else if(x=='(')
    return 7;
    else 
    return 0;
}
int inpre(char x)
{
    if(x=='+'||x=='-')
    return 2;
    else if(x=='*'||x=='/')
    return 4;
    else if(x=='^')
    return 5;
    else if(x=='(')
    return 0;
}
string infixtopostfix(string exp,stack * &st)
{
    string post="";
    int i=0;
    while(i<exp.length())
    {
        if(isoperator(exp[i]))
        {
            if(outpre(exp[i])>inpre(st->s[st->top]))
            {
                st->push(exp[i]);
               
            }
            
        }
        else
        post+=exp[i];
   
        i++;
    }
    //while(st->top!=-1)
    //post+=st->pop();
     st->print();
    return post;
}

int main()
{
    string exp;
    getline(cin,exp);
    int size=exp.length();
    stack *st=new stack(size);
    cout<<endl<<"answer is "<<infixtopostfix(exp,st);

}

