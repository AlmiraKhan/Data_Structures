#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//(A+(B*C-(D/E^F)*G)*H)

int N,top=-1;
char stack[40],item;
int eval[40];

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

void infixtopost(char inf[],char postf[])
{
    int i=0,j=0;
    char item,result;

    push('(');
    item=inf[i];

    while(item != '\0') 
    {
        if(item == '(')
            push(item);
        else if(item >= 65 && item <=90 || item>=97 && item <= 122 )
        {
            postf[j]=item;
            j++;
        }
        else if(isOperator(item)==1)
        {
            result=pop();
            while(isOperator(result)==1 && precedence(result)>=precedence(item))
            {
                postf[j]=result;
                j++;
                result=pop();
            }
            push(result);
            push(item);

        }
        else if(item ==')')
        {
            result=pop();
            while(result != '(')
            {
                postf[j]=result;
                j++;
                result=pop();
            }
        }
        else
        {
            printf("Invalid expression");
            exit(0);
        }
        i++;
        item=inf[i];
    }

}
void evaluate(char postf[])
{
    int i=0,j=0;
    while(postf[i]!='\0')
    {
        if(isOperator(postf[i])==0)
        {
            printf("Enter the value for %c:",postf[i]);
            scanf("%d",&eval[j]);
        }
        else
        {
            switch(postf[i])
            {
                case '+':
					eval[j-2]=eval[j-2]+eval[j-1];
					break;
				case '-':
					eval[j-2]=eval[j-2]-eval[j-1];
					break;
				case '*':
					eval[j-2]=eval[j-2]*eval[j-1];
					break;
				case '/':
					eval[j-2]=eval[j-2]/eval[j-1];
					break;
				case '^':
					eval[j-2]=pow(eval[j-2],eval[j-1]);
					break;
            }
            j=j-2;
        }
        i++;
        j++;
    }
    printf("Answer: %d",eval[0]);
}
int main()
{
    char postf[40],inf[40];
    printf("Enter the size of the stack:");
    scanf("%d",&N);

    printf("Enter the infix expression:");
    scanf("%s",inf);

    infixtopost(inf,postf);
    printf("Postfix expression:");
    puts(postf);

    printf("Postfix evaluation:\n");
    evaluate(postf);
    return 0;

    
}