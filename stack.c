#include<stdio.h>
#define N 6
int top=-1;
int stack[N];
void push();
void pop();
void display();
int main()
{
    
    int k,n;
    do
   { 
        printf("Enter 1 for push\n2 for pop\n3 for display:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        }
        printf("Enter 1 to do more operations and any other number to stop:");
        scanf("%d",&k);
    }while(k==1);


}
void push()
{
    int item;
    printf("Enter the item to be pushed:");
    scanf("%d",&item);
    if(top==N-1)
//
        printf("The array is full");
    else
    {
        top+=1;
        stack[top]=item;
    }
}
void pop()
{
    int temp;
    if(top==-1)
        printf("The array is empty");
    else
    {
        printf("popped element is %d",stack[top]);
        top-=1;
        
        
    }
}
void display()
{
    for (int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
        printf("\n");
    }
}
