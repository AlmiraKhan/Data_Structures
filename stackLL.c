#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*top;

void push()
{
    int value;
    struct node *new=malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&value);
    if(top==NULL)
    {
        new->data=value;
        new->link=NULL;
        top=new;
    }
    else
    {
        new->data=value;
        new->link=top;
        top=new;
    }
}

void pop()
{   
    struct node *temp;
    if(top==NULL)
        printf("The stack is empty");
    else
    {
        temp=top;
        printf("%d is deleted",temp->data);
        top=top->link;
        //temp->link=NULL;
        free(temp);

    }

}

void display()
{  
    struct node *temp;
    if(top==NULL)
        printf("Stack is empty");
    else
    {
        temp=top;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }

}
int main()
{
    int n,k;
    do
    {
        printf("Enter\n1 for push\n2for pop\n3 for display\n");
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
        printf("Enter 1 to continue");
        scanf("%d",&k);
    }while(k==1);
}