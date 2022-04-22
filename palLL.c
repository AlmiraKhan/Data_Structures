#include<stdio.h>
#include<stdlib.h>

struct node
{
    char cha;
    struct node*next;
    struct node*pre;
}*head,*current,*tail,*temp,*temp1;
void push(char ch);
void display();

void main()
{
    char str[10];
    printf("enter the string ");
    gets(str);
    int i=0;
    for(i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    display();

}
void push(char ch)
{
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->cha=ch;
        head->pre=NULL;
        head->next=NULL;
        tail=head;
        current=head;
    }
    else
    {
        tail=(struct node*)malloc(sizeof(struct node));
        current->next=tail;
        tail->pre=current;
        tail->next=NULL;
        tail->cha=ch;
        current=tail;
    }
}
void display()
{
    int flag=0;
    temp=head;
    temp1=tail;
    while(temp!=NULL&&temp1!=NULL)
    {
        if(temp->cha!=temp1->cha)
        {
            flag=-1;
            printf("the given string is not palindrome");
            break;
        }
        temp=temp->next;
        temp1=temp1->pre;
    }
    if(flag==0)
    {
        printf("the given string is palindrome");
    }
}