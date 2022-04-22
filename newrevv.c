#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
}*front,*rear,*top,*newnode;
void enque(int);
void deque();
void display();
void rev();
int item;
void main()
{
    int choice;
    while (1)
    {
        printf("\n\n1.Enque \n2.Deque into stack\n3.Display  queue in reverse and Exit\n");
        printf("\nEnter a choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        	printf("\nEnter data to be added\n");
        	scanf("%d", &item);
            enque(item);
            display();
			break;
        case 2:
            deque();
           display();
		    break;
            
        case 3:
        	
            rev();
            exit(0);
            break;
        }
    }
}
void enque(int item)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
   
        
        temp->data = item;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            front->link = NULL;
            rear->link = NULL;
        }
        else
        {
            rear->link = temp;
            rear = temp;
            rear->link = NULL;
        }
   
}
void deque()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("\nqueue is empty.cant dequeu\n");

    }
    else
    {	printf("\ndequeued %d",front->data);
        temp = front;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data=temp->data;
        newnode->link=top;
        top=newnode;
		front = front->link;
        free(temp);
        
    }
    temp=top;
        printf("\nstack:");
        while(temp!=NULL)
        {
            printf("%d   ",temp->data);
            temp=temp->link;
        }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\nqueue:");
        while (temp != NULL)
        {
            printf("%d   ", temp->data);
            temp = temp->link;
        }
    }
}
void rev()
{
		struct node *temp;

    	temp=top;
        while (temp != NULL)
        {
        	enque(temp->data);
        	temp=temp->link;
        }
        display();
    
}
