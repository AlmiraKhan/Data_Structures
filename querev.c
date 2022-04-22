#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
}*tail;
struct node* head=NULL;
struct node* stack_head=NULL;

void display()
{
	printf("\n");
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

void enqueue(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	if(tail==NULL)
        {
        	head=tail=newnode;
    	}
    	else
    	{
       		tail->link=newnode;
        	tail=newnode;
    	}
}

int dequeue()
{   int x;
    struct node *temp;
    if(head==tail)
    {
        printf("Queue is empty");
    }
     else
    {
        temp=head;
        head=head->link;
        temp->link=NULL;
        x=temp->data;
      
        free(temp);
        
    }
    return x;
}
void push(int data)
{
	struct node* temp=stack_head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=data;
	
	newnode->link=NULL;
	
	if(temp!=NULL)
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;

	}else
	{	
		
		stack_head=newnode;
	}
}

int pop()
{
	struct node* temp=stack_head;
	int val=-1;
	if(temp==NULL)
	{
		printf("\nThe Linked List is empty\n");
	}else
	{
		if(stack_head->link!=NULL)
		{
			while(temp->link->link!=NULL)
			{
				temp=temp->link;
			}
			val=temp->link->data;
			temp->link=NULL;

		}else
		{
			val=stack_head->data;
			stack_head=NULL;
		}
	}
	return val;
}

void reverse()
{	
	printf("\nReversed Queue");
	while(head->link!=NULL)
	{
		push(dequeue());
	}
	while(stack_head!=NULL)
	{
		enqueue(pop());
	}
	display();
	printf("\n");
}
int main()
{	
	while(1)
	{	
		int choice;
		printf("\nChoose an operation to perform:");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Reverse the Queue\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:
			{
				int temp;
				printf("\nEnter the number to enqueue: ");
				scanf("%d",&temp);
				enqueue(temp);
				break;
			}
			case 2:
			{
				int temp=dequeue();
				if(temp!=-1)
				{
					printf("\n%d Dequeued\n",temp);
				}
				break;
			}
			case 3:
				display();
				break;
			case 4:
			{
				reverse();
				break;
			}
			case 5:
			{
				return 0;
			}
		}	
	}
	return 0;
}