#include<stdio.h>
struct poly
{
  int coeff;
  int exp;
}p[30];

int main()
{
  int n1,n2,i,j,k;
  printf("Enter the no.of terms in the 1st polynomial:");
  scanf("%d",&n1);

  printf("Enter the coefficients and exponents of polynomial 1:");
  for(i=0;i<n1;i++)
  {
    scanf("%d %d",&p[i].coeff,&p[i].exp);
    //printf("\n");
  }
  
  printf("Enter the no.of terms in the 2nd polynomial:");
  scanf("%d",&n2);

  printf("Enter the coefficients and exponents of polynomial 2:");
  for(i=n1;i<n1+n2;i++)
  {
    scanf("%d %d",&p[i].coeff,&p[i].exp);
    //printf("\n");
  }
  
  i=0;
  j=n1;
  k=n1+n2;
  while(i<n1 && j<n1+n2)
  {
    if(p[i].exp < p[j].exp)
    {
      p[k].coeff=p[i].coeff;
      p[k].exp=p[i].exp;
      i++;
    }
    else if(p[i].exp > p[j].exp)
    {
      p[k].coeff=p[j].coeff;
      p[k].exp=p[j].exp;
      j++;
    }
    else
    {
      p[k].coeff=p[i].coeff+p[j].coeff;
      p[k].exp=p[i].exp;
      j++;
      i++;
    }
    k++;
  }
  while(i<n1)
  {
    p[k].exp=p[i].exp;
    p[k].coeff=p[i].coeff;
    i++;
    k++;
  }
  while(j<n1+n2)
  {
    p[k].exp=p[j].exp;
    p[k].coeff=p[j].coeff;
    j++;
    k++; 
  }
  printf("Ploynomial 1:");
  for(i=0;i<n1;i++)
      printf("%dx^%d ",p[i].coeff,p[i].exp);
  
  printf("\nPloynomial 2:");
  for(i=n1;i<n1+n2;i++)
      printf("%dx^%d ",p[i].coeff,p[i].exp);

  printf("\nSum polynomial:");
  for(i=n1+n2;i<k;i++)
      printf("%dx^%d ",p[i].coeff,p[i].exp);


  return 0;


}