#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*rear,*front;

void enq()
{
    int value;
    printf("\nEnter value to be inserted:");
    scanf("%d",&value);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->link=NULL;
    if(rear==NULL)
    {
        front=rear=new;
    }
    else
    {
        rear->link=new;
        rear=new;
    }

}
void deq()
{
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
        {
            front=rear=NULL;
            free(rear);
            printf("%d is deleted",rear->data);
        }

     else
    {
        temp=front;
        front=front->link;
        temp->link=NULL;
        printf("%d is deleted",temp->data);
        free(temp);
        
    }
}

void display()
{
    struct node *temp=front;
    if(front>=rear)
    {
        printf("The queue is empty");
    }
    else
    {
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
        printf("Enter\n1for enqueue\n2 for dequeue\n3for display\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            enq();
            break;
            case 2:
            deq();
            break;
            case 3:
            display();
            break;
        }
        printf("\nEnter 1 to repeat:");
        scanf("%d",&k);
    }while(k==1);
}