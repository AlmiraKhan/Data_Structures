#include<stdio.h>
#define MAX 30
struct poly
{
    int coef;
    int exp;
}p[MAX];

void main()
{
    int i,j,m,n,k ;
    printf("enter no.of terms of 1st:");
    scanf("%d",&m);
    printf("enter COEF AND EXP in ORDER OF exp ascending:");
    for(i=0;i<m;i++)
    {
        
        scanf("%d%d",&p[i].coef,&p[i].exp);
        printf("\n");
    }
    printf("enter no.of terms of 2st:");
    scanf("%d",&n);
    printf("enter COEF AND EXP in ORDER OF exp ascending:");
    for(i=m;i<m+n;i++)
    {
        
        scanf("%d%d",&p[i].coef,&p[i].exp);
        printf("\n");
    }
    i=0;
    j=m;
    k=m+n;
    while(i<m&&j<m+n){
        if(p[i].exp<p[j].exp)
        {
            p[k].coef=p[i].coef;
            p[k].exp=p[i].exp;
            i++;
        }
        else if(p[i].exp>p[j].exp)
        {
            p[k].coef=p[j].coef;
            p[k].exp=p[j].exp;
            j++;
        }
        else
        {
            p[k].coef=p[i].coef+p[j].coef;
            p[k].exp=p[i].exp;
            i++;j++;
        }
        k++;
    }
    while(i<m){
        
            p[k].coef=p[i].coef;
            p[k].exp=p[i].exp;
            i++;k++;
        }
    while(j<m+n){
        
            p[k].coef=p[j].coef;
            p[k].exp=p[j].exp;
            j++;k++;
        }

    for(i=m+n;i<k;i++)
    {
        printf("%d(x^%d)+",p[i].coef,p[i].exp);
    }

}