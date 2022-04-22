#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,exp;
    struct node *link;
}*head1=NULL,*head2=NULL,*head=NULL,*head3=NULL,*temp,*t,*temp3,*current,*new3, *temp1,*temp2;

void pdt()
{
	temp1=head1;
	while(temp1!=NULL)
    {
        temp2=head2;
        
        while(temp2!=NULL)
        {
            new3=(struct node*)malloc(sizeof(struct node));
            new3->link=NULL;
            new3->coeff=temp1->coeff*temp2->coeff;
            new3->exp=temp1->exp+temp2->exp;
            if(head3==NULL)
            {
                head3=new3;
                temp3=head3;
            }
            else
            {
                temp3->link=new3;
                temp3=new3;
            }
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
    
    temp3=head3;
    while(temp3->link!=NULL)
    {
        current=temp3->link;
        while(current!=NULL)
        {
            if(current->exp==temp->exp)
            {
                temp3->coeff+=current->coeff;
                t=head3;
                while(t->link!=current)
                {
                    t=t->link;
                }
                current=current->link;
                free(t->link);
                t->link=current;
            }
            else
            {
                current=current->link;
            }
        }
        temp3=temp3->link;
    }
    int x,y;
    for(temp3=head3;temp3->link!=NULL;temp3=temp3->link)
    {
        for(t=head3;t->link!=NULL;t=t->link)
        {
            if(t->exp < t->link->exp)
            {
                x=t->exp;
                y=t->coeff;
                t->coeff=t->link->coeff;
                t->exp=t->link->exp;
                t->link->coeff=y;
                t->link->exp=x;
            }
        }
    }
    printf("\nProduct polynomial:");
    
    

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
    
    pdt();
    display(head3);
	
    
}