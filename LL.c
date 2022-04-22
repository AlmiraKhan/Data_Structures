//LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* head= NULL;
void display()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
        printf("The list is empty\n");
    else
    {
        printf("This is the linked list:");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
    

}
void ins_beg()
{
    int data;
    struct node* new=malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&data);
    new->data=data;
    // new->link=head;
    // head=new;
    new->link=NULL;
    if(head==NULL)
        head=new;
    else
    {
        new->link=head;
        head=new;
    }
}
void ins_end()
{
    int data;
    struct node* new,*temp;
    new=malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&data);
    new->link=NULL;
    new->data=data;
    temp=head;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;

    }
    
}
void ins_pos()
{
    struct node *temp,*new;
    int pos, data, i=1;
    new=malloc(sizeof(struct node));
    printf("Enter position and data:");
    scanf("%d %d",&pos,&data);
    if(pos<0)
    {
        printf("Invalid position");
    }
    else{
     if(head==NULL)
    {
        head=new;
        new->data=data;
        new->link=NULL;
    }
    else{
        temp=head;
    new->data=data;
    new->link=NULL;
    while(i<pos-1)
    {
        temp=temp->link;
        i++;
    }
    new->link=temp->link;
    temp->link=new;
    }
    } 
}

void del_beg()
{
    struct node *temp;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        temp=head;
        printf("%d is deleted",temp->data);
        head=head->link;
        free(temp);
    }
}
void del_end()
{
    struct node *temp,*current;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        temp=head;

        while(temp->link != 0)
        {
            current=temp;
            temp=temp->link;
        }
        printf("%d is deleted",temp->data);

        free(temp);
        current->link=NULL;
    }
}
void del_pos()
{
    struct node *temp,*pos;
    int i=1,j;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        printf("Enter the position");
        scanf("%d",&j);
        if(j<0)
        {
            printf("Invalid position");
        }
        else
        {
            pos=malloc(sizeof(struct node));
        temp=head;
        while(i<j-1)
        {
            temp=temp->link;
            i++;
        }
        pos=temp->link;
        temp->link=pos->link;
        printf("%d is deleted",pos->data);

        free(pos);
        }
        
    }
}
int main()
{
    int n;
    int k;
    

    do{
        printf("Enter\n1 for Display\n2 for Insertion at beginning\n3 for  Insertion at end\n4 for Insertion at any position\n5 Deletion at beginning\n6 for Deletion at end\n7 for Deletion at any position\n");
        scanf("%d",&n);
        switch(n)
    {
        case 1:
        display();
        break;
        case 2:
        ins_beg();
        break;
        case 3:
        ins_end();
        break;
        case 4:
        ins_pos();
        break;
        case 5:
        del_beg();
        break;
        case 6:
        del_end();
        break;
        case 7:
        del_pos();
        break;
        default:
        printf("invalid input");
    }
    printf("\nEnter 1 to continue:");
    scanf("%d",&k);
    }while(k==1); 
}
