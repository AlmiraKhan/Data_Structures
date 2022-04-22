#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,exp;
    struct node *link;
}*head1=NULL,*head2=NULL,*head=NULL,*temp;

void sum()
{
    struct node *temp1,*temp2;
    //printf("\nSum of polynomials:");
	temp1=head1;
	temp2=head2;
    
    
	while(temp1!=NULL&&temp2!=NULL)
	{
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            temp=new;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
		if(temp1->exp==temp2->exp)
		{
            temp->coeff=temp1->coeff+temp2->coeff;
            temp->exp=temp1->exp;
			
			temp1=temp1->link;
			temp2=temp2->link;
		}
		else if(temp1->exp>temp2->exp)
		{
            temp->coeff=temp1->coeff;
            temp->exp=temp1->exp;

			temp1=temp1->link;
		}
		else 
		{
            temp->coeff=temp2->coeff;
            temp->exp=temp2->exp;
            
			temp2=temp2->link;
		}
		
	}
	while(temp1!=NULL)
	{
        temp->coeff=temp1->coeff;
        temp->exp=temp1->exp;
		//printf("%dx^%d",temp1->coeff,temp1->exp);
		temp1=temp1->link;
		
	}
	while(temp2!=NULL)
	{
        temp->coeff=temp2->coeff;
        temp->exp=temp2->exp;
		//printf("%dx^%d",temp2->coeff,temp2->exp);
		temp2=temp2->link;
		
	}

}
void display(struct node *head)
{
    struct node *current=head;
    while(current->link != NULL)
    {
        printf("%dx^%d ",current->coeff,current->exp);
        current=current->link;
        if(current!=NULL)
        {
            printf("+");
        }
    }
    printf("%dx^%d",current->coeff,current->exp);
}
int main()
{
    int n1,n2;
    int c,e;
    
    printf("\nEnter the number of terms in polynomial 1:");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("Enter the coeff and exp:");
        scanf("%d %d",&c,&e);
        // create(c,e,head1);
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->coeff = c;
        new->exp = e;
        new->link = NULL;
        if(head1==NULL)
        {
            head1=new;
            temp=head1;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
    }
    printf("Polynomial 1:");
    display(head1);

    printf("\nEnter the number of terms in polynomial 2:");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter the coeff and exp:");
        scanf("%d %d",&c,&e);
        //create(c,e,head2);
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->coeff = c;
        new->exp = e;
        new->link = NULL;
        if(head2==NULL)
        {
            head2=new;
            temp=head2;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
    }
    printf("Polynomial 2:");
    display(head2);
    printf("\nSum:");
    sum();
    display(head);
}