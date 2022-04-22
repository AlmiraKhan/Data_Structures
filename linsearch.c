#include<stdio.h>
int linsearch(int,int,int arr[]);
int main()
{
    int i,n,arr[25],key,result;
    printf("Enter the array size:");
    scanf("%d",&n);

    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter the key to be searched:");
    scanf("%d",&key);

    result=linsearch(n,key,arr);
    if(result==-1)
        printf("Element not present");
    else
        printf("Element found at position %d",result+1);

    return 0;
}
int linsearch(int n,int key,int arr[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
