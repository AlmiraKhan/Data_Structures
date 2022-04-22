#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
};

struct node *table[10];

void init()
{
	for(int i=0;i<10;i++)
		table[i] = NULL;
}

void insert(int value)
{
	int hkey = value%10;
	int i,index;
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]==NULL)
		{
			table[index] = newnode;
			break;
		}
	}
	if(i==10)
		printf("Element cannot be inserted\n");
}

void delete(int value)
{
	int i,index;
	int hkey = value%10;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]!=NULL)
		{
			if(table[index]->data==value)
			{
				table[index] = NULL;
				break;
			}
		}
	}
	if(i==10)
		printf("Value not found\n");
}

void search(int value)
{
	int i,index;
	int hkey = value%10;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]!=NULL)
		{
			if(table[index]->data==value)
			{
				printf("Value %d found at index %d\n",value,index);
				break;
			}
		}
	}
	if(i==10)
		printf("Value not found\n");
}

void display()
{
	printf("Hash Table\n");
	for(int i=0;i<10;i++)
	{
		if(table[i]!=NULL)
			printf("Index - %d  Value - %d\n",i,table[i]->data);
		else
			printf("Index - %d  Value - NULL\n",i);
	}
}

int main()
{
	int n,value;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            printf("Enter value to be inserted:");
            scanf("%d",&value);
            insert(value);
            break;

            case 2:
            printf("Enter value to be deleted:");
            scanf("%d",&value);
            delete(value);
            break;

            case 3:
            printf("Enter value to be searched:");
            scanf("%d",&value);
            search(value);
            break;

            case 4:
            display();
            break;

            case 5:
            return 0;


        }
    }
	
}