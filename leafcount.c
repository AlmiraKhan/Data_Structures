#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};

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



int count(struct node *root)
 {
    static int key=0;
    
    if(root==NULL)
    {
        return key;
    }
    else if(root->left ==NULL && root->right ==NULL)
        key++;

    else //if(root->left !=NULL && root->right !=NULL)
    {
        count(root->left);
        count(root->right);
    }
    
 }

int main()
{
    struct node *root;
    
        printf("Enter data:");
        root=create();

        printf("Number of leaf nodes are:%d",count(root));
        
    
}