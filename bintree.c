#include<stdio.h>
#include<stdlib.h>
 struct node 
 {
     int data;
     struct node *left,*right;
 };
 struct node* root=NULL;
 int r=-1,f=-1,N=50;
 struct node* q[50];

 struct node *create()
 {
     int x;
     struct node *newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     
     scanf("%d",&x);
     if(x==-1)
        return NULL;
    else
    {
        newnode->data=x;
        printf("Enter left node of %d:",x);
        newnode->left=create();
        printf("Enter right node of %d:",x);
        newnode->right=create();
        
        return newnode;
    }
     
 }
 void preorder(struct node *root)
 {
     if(root==NULL)
        return;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
 }
 void inorder(struct node *root)
 {
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
 }
 void postorder(struct node *root)
 {
     if(root==NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d s",root->data);
        
    }
 }

 void enq(struct node* item)
{
    if(f==-1 || r==-1)
    {
        f++;
        r++;
        q[f]=item;
    }
    else
    {
        r+=1;
        q[r]=item;
    }
}

struct node* deq()
{
    if(f==-1 || f>r)
    {
        return NULL;
    }
    else
    {
        
        return q[f++];
    }
}

void insert()
{
    struct node *temp=root,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    f=r=-1;
    
    printf("Enter value to be inserted:");
    scanf("%d",&(newnode->data));
    newnode->left=NULL;
    newnode->left=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        while(f<=r)
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                
                return;
            }
            if(temp->right==NULL)
            {
                temp->right=newnode;
                
                return;
            }
            if(temp->left!=NULL)
                enq(temp->left);
            if(temp->right!=NULL)
                enq(temp->right);
            temp=deq();
        }
    }
}

void delete_last_node(struct node* last,struct node *root)
{
	struct node* tempnode=root;
	f=r=-1;
	if(last==root)
	{
		root=NULL;
		return;
	}
	while(f<=r)
	{
		if(tempnode->left==last)
		{
			tempnode->left=NULL;
			return;
		}
		if(tempnode->right==last)
		{
			tempnode->right=NULL;
			return;
		}
		if(tempnode->left!=NULL)
			enq(tempnode->left);
		if(tempnode->right!=NULL)
			enq(tempnode->right);
		tempnode=deq();

	}
}

void delete(int value)
{
	struct node* tempnode=root,*ptr=root;
	struct node* node_to_delete=NULL;
	f=r=-1;
	if(root==NULL)
	{
		printf("\nTree empty");
		return;
	}
	else 
	{
		enq(root);
		
		while(f<=r)
		{
			
			tempnode=deq();
			if(tempnode->data==value)
			{
				node_to_delete=tempnode;
			}
			
			if(tempnode->left!=NULL)
				enq(tempnode->left);
			if(tempnode->right!=NULL)
				enq(tempnode->right);
			
		}
	}
	
	if(node_to_delete==NULL)
	{
		printf("\n%d not found in tree",value);
	}
	else
	{
		node_to_delete->data=tempnode->data;
	
		delete_last_node(tempnode,root);
			
	}
}

 int main()
 {
     //struct node *root=NULL;
     
     int n;
     while(1)
     {
        printf("\nEnter\n1.Creation of new node\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Delete a node\n6.Insertion of a node\n7.EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
        printf("enter data:");
        root=create();
        break;

        case 2:
        printf("Preorder traversal:");
        preorder(root);
        break;

        case 3:
        printf("Inorder traversal:");
        inorder(root);
        break;

        case 4:
        printf("postorder traversal:");
        postorder(root);
        break;

        case 5:
        printf("Enter the element to delete:");
        int x;
        scanf("%d",&x);
        delete(x);
        break;

        case 6:
        insert();
        break;

        case 7:
        return 0;

        }
     }
 }