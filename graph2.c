#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

struct queue
{
    int front;
    int rear;
    int *arr;
    int size;
};

int isFull(struct stack *st)
{
    if(st->top >= st->size-1)
        return 1;
    return 0;
}

int isEmpty(struct stack *st)
{
    if(st->top == -1)
        return 1;
    return 0;
}

void push(struct stack *st, char x)
{
    if(isFull(st)==0)
    {
       
        st->arr[++st->top]=x;
    }
}

char pop(struct stack *st)
{
    if(isEmpty(st)==0)
    {
        char x = st->arr[st->top];
        st->top--;
        return x;
    }
}
void enqueue(struct queue *q, char x)
{
    if(q->rear != q->size-1 )
    {
        if(q->front == -1)
        {
            q->front =0;
            q->rear +=1;
            q->arr[q->rear]=x;
        }

    }
}

char dequeue(struct queue *q)
{
    if(q->front != -1)
    {
        char x= q->arr[q->front];
        if(q->front == q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->front +=1;

        return x;

    }
}
void createStack(struct stack *st,int n)
{
    st->size = (n) ;
    st->arr=(int*)malloc(st->size * sizeof(int));
    st->top = -1;
}
void dfs(int n, char mat[][n+1])
{
    struct stack *st = malloc(sizeof(struct stack));
    int count =0;
    int i=0;
    char v;
    char visit[n];

    createStack(st,n*n);

    push(st, mat[0][1]);
    while(isEmpty(st)==0)
    {
        v=pop(st);
        for(int j=0;j<n;j++)
        {
            if(visit[j]==v)
                count++;
        }
        if(count ==0)
        {
            //printf("%c ",v);
            visit[i]=v;
            i++;
            for(int j=1;i<=n;j++)
            {
                if(mat[0][j]==v)
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(mat[k][j]=='1')
                            push(st,mat[k][0]);

                        
                    }
                    break;
                }
                
            }
        }
        count=0;
    }
    for(int i=0;i<n;i++)
            printf("%c ",visit[i]);
}
//void bfs(int n, char mat[][n+1]);
int main()
{
    int n,m;
    char c;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    char mat[n+1][n+1];
    mat[0][0]=' ';

    printf("Enter the vertices\n");
    for(int i=1; i<=n;i++)
    {
        scanf("\n%c",&mat[i][0]);
        mat[0][i] = mat[i][0];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(mat[i][0] == mat[0][j])
            {
                printf("Is %c a self loop? (y/n)\n",mat[i][0]);
                scanf("\n%c",&c);
                if(c=='y')
                    mat[i][j]='1';
                else if(c=='n')
                    mat[i][j]='0';

                continue;
            }
            printf("Are %c and %c adjacent? (y/n)\n",mat[i][0],mat[0][j]);
            scanf("\n%c",&c);

            if(c=='y')
            {
                mat[i][j]=mat[j][i]='1';
            }
            else if(c=='n')
            {
                mat[i][j]=mat[j][i]='0';
            }
        }
    }
    
    printf("Adjacency matrix of the graph:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%c ",mat[i][j]);

        printf("\n");
    }

    while(1)
    {
        printf("Choose the operation\n");
        printf("1. DFS Traversal\n2. BFS Traversal\n3. Quit\n");
            scanf("%d", &m);
        
        if(m==1)
        {
            printf("\nDFS Traversal");
            dfs(n,mat);
            printf("\n");
        }
        else if(m==2)
        {
            printf("\nBFS Traversal");
            //bfs(n,mat);
            printf("\n");

        }
        else if(m==3)
            return 0;

        else
            printf("Invalid Entry");
    }


}