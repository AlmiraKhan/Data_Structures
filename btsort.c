#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node* root=NULL;
int arr[100],size;
struct node* create(int i)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	int x;
	scanf("%d",&x);
    arr[i]=x;
	if(x==-1)
	{

		return NULL;
	}
	else
	{
		newnode->data=x;
		printf("left node of %d:",x);
		newnode->left=create(2*i);
		printf("right node of %d:",x);
		newnode->right=create(2*i+1);
        if(i>size)
        size=i;
		return newnode;
	}
}
int main()
{
    int i,j,temp;
	printf("Enter root node:");
	root=create(1);
    for(i=1;i<=size;i++)
    {
        for(j=1;j<=size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=1;i<=size;i++)
    {
        if(arr[i]!=-1)
            printf("%d ",arr[i]);
    }
    return 0;
}
