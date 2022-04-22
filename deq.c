#include<stdio.h>
#define N 6
int d[N],r=-1,f=-1;
void insR();
void insF();
void delR();
void delF();
void display();

int main()
{
    int k,n;
    do
   { 
        printf("Enter 1 for insert at front\n2 for insert at rear\n3 for delete from front\n4 for delete from rear\n5 for display:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            insF();
            break;
            case 2:
            insR();
            break;
            case 3:
            delF();
            break;
            case 4:
            delR();
            break;
            case 5:
            display();
            break;
        }
        printf("Enter 1 to do more operations and any other number to stop:");
        scanf("%d",&k);
    }while(k==1);
    return 0;
    
}
void insR()
{
    int item;
    printf("Enter the element to be inserted:");
    scanf("%d",&item);
    if(f==0 && r==N-1)
        printf("Array is full");
    else if(f==-1 && r==-1)
    {
        f=r=0;
        d[r]=item;
    }
    else-
    {
        r=(r+1)%N;
        d[r]=item;
    }
    
}

void insF()
{
    int item;
    printf("Enter the element to be inserted:");
    scanf("%d",&item);
    if((f==0 && r==N-1) || f==r+1 )
        printf("The array is full");
    else if(f==-1 && r==-1)
    {
        f=0;
        r=0;
        d[f]=item;
    }
    else if(f==0)
    {
        f=N-1;
        d[f]=item;
    }
    else
    {
        f-=1;
        d[f]=item;
    }

}

void delR()
{
    if(f==-1 && r==-1)
        printf("Queue is empty");
else if(f==r)
{
    printf("The dequeued element is %d\n",d[r]);
    f=r=-1;

}
else if(r==0)
{
    printf("The dequeued element is %d\n",d[r]);
    r=N-1;
}
else
{
    printf("The dequeued element is %d\n",d[r]);
    r-=1;
}

}

void delF()
{
    if(r==-1 && f==-1)
        printf("Underflow!");
    else if(f==r)
    {
        printf("The dequeued element is %d\n",d[f]);
        f=-1;
        r=-1;
    }
    else
    {
        printf("The dequeued element is %d\n",d[f]);
        f=(f+1)%N;
        
    }
    
}
void display()
{
    int i=f;
    while(i!=r)
    {
        printf("%d",d[i]);
        i=(i+1)%N;

    }
    printf("%d ",d[r]);

}