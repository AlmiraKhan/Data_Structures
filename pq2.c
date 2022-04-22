#include<stdio.h>
struct node
{
    int data;
    int priority;
    struct node *link;
}*front=NULL, *rear=NULL,*ptr,*ptr1;


void penq()
{
    struct node *new =(struct node*)malloc(sizeof(struct node));
    printf("Enter the element and it's priority:");
    scanf("%d %d",&new->data,&new->priority);
    ptr=front;
    while(ptr->link!=NULL && ptr->priority<new->priority)
    {
        ptr=ptr->link;
    }
    if(ptr->link==NULL)
    {
        ptr->link=new;
        new->link=NULL;
        rear=new;
    }
    else
    {
        if(ptr->priority>=new->priority)
        {
            new->link=ptr->link;
            ptr->link=new;

        }
    }
}
int main()
{
    int k,n;
    printf("Enter the size of queue:");
    scanf("%d",&N);
    do
   { 
        printf("Enter 1 for enqueue\n2 for dequeue\n3 for display:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            penq();
            break;
            case 2:
            pdeq();
            break;
            case 3:
            display();
            break;
            default:
            exit(0);
        }
        printf("\nEnter 1 to do more operations and any other number to stop:");
        scanf("%d",&k);
    }while(k==1);
    return 0;
}