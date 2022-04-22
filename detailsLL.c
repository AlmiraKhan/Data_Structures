#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int roll,mark;
    char name[20];
    struct node *link;
}*head,*temp,*temp2;

void insert()
{
    //int r,m;
    char str[20];
    struct node *new=(struct node*)malloc(sizeof(struct node));
   struct node *temp;
    printf("Enter Roll number:");
    scanf("%d",&new->roll);
    printf("Enter Name:");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
        new->name[i]=str[i];
    printf("Enter mark:");
    scanf("%d",&new->mark);

    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
         temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
    }
}

void delete()
{
    int r;
    temp2=head;
    
    if(head==NULL)
        printf("The list is empty");
    else
    {
        struct node *temp3=head;
        printf("Enter the roll no.of student whose details are to be deleted:");
        scanf("%d",&r);
        while(temp2 != NULL)
        {
            if(temp2->roll==r)
            {
                temp3->link=temp2->link;
                printf("The details of student %s has been deleted",temp2->name);
                free(temp2);
                break;
            }
                temp3=temp2;
                temp2=temp2->link;
        }
        if(temp2==NULL)
            printf("Student not found");
    }
}

void search()
{
    int r;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        printf("Enter the roll no.of student to be searched:");
        scanf("%d",&r);
        temp2=head;
        while(temp2!= NULL)
        {
            if(temp2->roll==r)
            {
                printf("Details:");
                printf("\nRoll number:%d\nName:%s\nMarks:%d",temp2->roll,temp2->name,temp2->mark);
                break;
            }
            else
                temp2=temp2->link;
        }
        if(temp2==NULL)
        printf("Student not found");
    }
}

void sort()
{
    printf("SORTING");
    int i,roll,mark;
    char str[20];
    if(head==NULL)
        printf("Student list is empty");
    else
    {
        struct node *i,*j;
        for(i=head;i->link!=NULL;i=i->link)
        {
            for(j=head;j->link!=NULL;j=j->link)
            {
                if(j->roll > j->link->roll)
                {
                    roll=j->roll;
                    j->roll=j->link->roll;
                    j->link->roll=roll;

                    mark=j->mark;
                    j->mark=j->link->mark;
                    j->link->mark=mark;

                    strcpy(str,j->name);
                    strcpy(j->name,j->link->name);
                    strcpy(j->link->name,str);
                
                }
            }
        }
    }

}

void display()
{
    temp2=head;
    if(temp2==NULL)
        printf("The list is empty");
    else
    {
        while(temp2!=NULL)
        {
            printf("\nRoll number:%d\nName:%s\nMarks:%d\n",temp2->roll,temp2->name,temp2->mark);
            temp2=temp2->link;
        }
    }
}

int main()
{
    int n;
    
    while(1)
    {
        printf("\nChoose an operation to perform:");
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Sort\n5.Display\n6.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            search();
            break;
            case 4:
            sort();
            break;
             case 5:
            display();
            break;
            case 6:
            printf("EXIT");
            return 0;
        }
    }
    
}