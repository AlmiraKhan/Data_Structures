#include<stdio.h>
int stack[20],q[20];
int r=-1,f=-1;
int top=-1,N;

void push(int item)
{
    top+=1;
    stack[top]=item;
}
int pop()
{
    if(top!=-1)
    {
        top-=1;
        return stack[top+1];
    }
}
void enq(int item)
{
    if(r==N-1)
        printf("Overflow!");
    else if(r==-1 && f==-1)
    {
        f=r=0;
        q[r]=item;
    }
    else
    {
        r+=1;
        q[r]=item;
    }

}
int deq()
{
    int temp;
    if(r==-1 && f==-1)
        printf("Underflow!");
    else if(f==r)
    {
        temp=f;
        //printf("The dequeued element is %d\n",q[f]);
        f=-1;
        r=-1;
        return q[temp];
    
    }
    else
    {
        //printf("The dequeued element is %d\n",q[f]);
        f+=1;
        return q[f-1];
        
    }

}
void display()
{
    int i;
    for(i=f;i<=r;i++)
        printf("%d ",q[i]);

}
int main()
{
    int n,k,i;
    int item;
    printf("Enter the size of queue");
    scanf("%d",&N);
    printf("Enter the queue elements:");
    for(i=0;i<N;i++)
    {
        scanf("%d",&item);
       enq(item);
    }
    for(i=0;i<N;i++)
    {
        push(deq());
    }

    for(i=0;i<N;i++)
    {
        enq(pop());
    }
    display();
    
}