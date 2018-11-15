#include<iostream>
#define max 50
#include "stack.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Infix
{
private:
    char infix[max];
public:
    void input()
    {
        cout<<"\nEnter the infix expression::";
        gets(infix);
    }
    void convert()
    {
        Stack<char> opr(max);
        char pf[max];
        int k=0;
        for(int i=0; infix[i]!='\0'; ++i)
        {

            if(infix[i]>='0'&&infix[i]<='9')
                pf[k++]=infix[i];
            else if(infix[i]=='(')
                opr.push(infix[i]);
            else if(infix[i]==')')
            {
                char x=opr.pop();
                while(x!='(')
                {
                    pf[k++]=x;
                    x=opr.pop();
                }
            }
            else
            {


                while(!opr.isEmpty()&&priority(opr.topElement())>=priority(infix[i]))
                    pf[k++]=opr.pop();
                opr.push(infix[i]);
            }
        }
        while(!opr.isEmpty())
            pf[k++]=opr.pop();
        cout<<"\nPostfix Expression::";
        for(int j=0; j<k; j++)
            cout<<pf[j];
        cout<<"\nEvaluated Expression::";
            cout<<eval(pf,k);
    }
    int eval(char pf[],int k)
    {
        Stack<int> output(max);
        for(int i=0; i<k; ++i)
        {
            if(pf[i]>='0'&&pf[i]<='9')
                output.push(pf[i]-'0');
            else
            {
                int a=output.pop();
                int b=output.pop();
                output.push(calc(b,a ,pf[i]));
                //cout<<pf[i];
                //cout<<calc(a,b,pf[i]);

            }
        }
        return output.pop();
    }
    int calc(int a,int b,char ch)
    {
        int res;
        switch(ch)
        {
        case '+':
            res=a+b;
            break;
        case '-':
            res=a-b;
            break;
        case '*':
        case 'x':
            res=a*b;
            break;
        case '/':
            if(b==0)
            {
                cout<<"\nDivide by Zero";
                exit(0);
            }
            res=a/b;
            break;
        case '$':
        case '^':
            res=(int)pow(a,b);
            break;
        case '%':
            res=a%b;
            break;
        default:
            cout<<"\nWrong operator";
            res=0;
        }
        return res;
    }
    int priority (char a)
    {
        switch(a)
        {
        case '$':
            return 2;
        case '*':
        case '/':
            return 1;
        case '+':
        case '-':
            return 0;
        default:
            return -1;
        }
    }
};
int main()
{

    Infix o1;
    o1.input();
    o1.convert();
}

