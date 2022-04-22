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
        printf("%d ",root->data);
        
    }
 }

void insert(struct node *root)
{
    struct node *ptr=root;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    struct node *ptr1;
    int flag=0;
    int item;
    printf("Enter item to be inserted:");
    scanf("%d",&item);
    while(ptr!=NULL && flag==0)
    {
        if(item<ptr->data)
        {
            ptr1=ptr;
            ptr=ptr->left;
        }
        else if(item>ptr->data)
        {
            ptr1=ptr;
            ptr=ptr->right;
        }
        else if(item==ptr->data)
        {
            flag=1;
            printf("Element already exits");
        }
    }
    if(ptr==NULL)
    {
        newnode->data=item;
        newnode->left=newnode->right=NULL;
    }
    if(ptr1->data<item)
        ptr1->right=newnode;
    else
        ptr1->left=newnode;

}
struct node* succ(struct node *ptr)
{
    struct node* ptr1=ptr->right;
    if(ptr1!=NULL)
    {
        while(ptr1->left != NULL)
            ptr1=ptr1->left;
        return(ptr1);
    }
}
struct node* delete(struct node *root,int item)
{
    struct node *ptr=root,*parent;
    int flag=0;
    
    while(ptr!=NULL && flag==0)
    {
        if(item<ptr->data)
        {
            parent=ptr;
            ptr=ptr->left;
        }
        else if(item>ptr->data)
        {
            parent=ptr;
            ptr=ptr->right;
        }
        else
        {
            flag=1;
        }
        
    }
    if(flag==0)
        printf("The item doesnt exist");
    
    if(ptr->left==NULL && ptr->right==NULL) //leaf node deletion
    {
        if(parent->left==ptr)
            parent->left=NULL;
        
        else
            parent->right=NULL;

        ptr=NULL;
    }

   else if(ptr->left!=NULL && ptr->right!=NULL) //node with 2 children deletion
    {
        parent=succ(ptr);
        item=parent->data;
        delete(root,parent->data);
        ptr->data=item;

    }
    
    else //node with 1 child deletion
    {
        if(parent->left == ptr)
        {
            if(ptr->left == NULL)
                parent->left=ptr->right;
            else
                parent->left=ptr->left;
        }
        else
        {
            if(ptr->right == NULL)
                    parent->right=ptr->left;
            else
                parent->right=ptr->right;
        }
    }
}

int main()
{
    struct node *root=NULL;
     
     printf("--BINARY SEARCH TREE--\n");
     int n,val;
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
        printf("Enter item to be deleted");
        scanf("%d",&val);
        delete(root,val);
        break;

        case 6:
        insert(root);
        break;

        case 7:
        return 0;
        }
     }
}
/*

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

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
        printf("%d ",root->data);
        
    }
 }

 void delete(int item)
 {

 }

struct node* insert()
 {
     int x,flag=0;
     struct node* newnode,*parent,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&x);

    if(temp==NULL)
    {
        newnode->data=x;
        newnode->left=newnode->right=NULL;
    }
    while(temp!=NULL && flag==0)
    {
        if(temp->data>x)
        {
            parent=temp;
            temp=temp->left;
        }
        if(temp->data<x)
        {
            parent=temp;
            temp=temp->right;
        }
        else if(x==temp->data)
        {
            flag=1;
            printf("element exits");
        }
    }
    
    if(parent->data>x)
    {
        parent->left=newnode;
    }
    else
       parent->right=newnode;

       return newnode;

   

 }

 int main()
{
    struct node *root=NULL;
     
     printf("--BINARY SEARCH TREE--\n");
     
     int n,val;
     while(1)
     {
        printf("\nEnter\n1.Insertion of new node\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Delete a node\n6.EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
        printf("enter data:");
        root=insert();
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

        // case 5:
        // printf("Enter item to be deleted");
        // scanf("%d",&val);
        // delete(root,val);
        // break;

        case 6:
        return 0;
        }
     }
}
*/