#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int N,top=-1;
char stack[70],item;
char pre[70],inf[70],temp[70];
// (O^P)*W/U/V*T+Q 
//((H*((((A+((B+C)*D))*F)*G)*E))+J)

void push(char item)
{
    top+=1;
    stack[top]=item;
}

char pop()
{
    if(top!=-1)
    {
        top-=1;
        return stack[top+1];
    }
}

int isOperator(char item)
{
    if(item =='^' || item == '*' ||item == '/' || item =='+' || item =='-')
        return 1;
    return 0;
}

int precedence(char item)
{
    if(item == '^')
        return 3;
    else if(item=='*' || item =='/')
        return 2;
    else if(item=='+' || item == '-')
        return 1;
    else
        return 0;
}

void intopre(char inf[],char pre[])
{
    int i=N-1,j=0;
    char item,result;

    push(')');
    

    for(;i>=0;i--)
    {
            item=inf[i];
            if(item == ')')
                push(item);
            else if(item >= 65 && item <=90 || item>=97 && item <= 122 )
            {
                pre[j]=item;
                j++;
            }
            else if(isOperator(item)==1)
            {
                result=pop();
                while(isOperator(result)==1 && precedence(result)>precedence(item))
                {
                    pre[j]=result;
                    j++;
                    result=pop();
                }
                push(result);
                push(item);

            }
            else if(item =='(')
            {
                result=pop();
                while(result != ')')
                {
                    pre[j]=result;
                    j++;
                    result=pop();
                }
            }
           
    }
    if(top!=-1)
    {
        result=pop();
        while(isOperator(result)==1 && precedence(result)>precedence(item))
        {
            pre[j]=result;
            j++;
            result=pop();
        }
    }
    
}
int main()
{
    int i;
    
    printf("Enter the size of the stack:");
    scanf("%d",&N);

    printf("Enter the infix expression:");
    scanf("%s",inf);

    
    intopre(inf,pre);
    printf("Prefix expression:");
    for(i=N-1;i>=0;i--)
        printf("%c",pre[i]);

    return 0;

    
}