#include<stdio.h>
int selSort(int a[],int);
int main()
{
    int n,arr[25],result;
    printf("Enter the size of array:");
    scanf("%d",&n);

    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selSort(arr,n);
    return 0;
}
int selSort(int arr[],int n)
{
    int i,j,temp=0,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

    }
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}