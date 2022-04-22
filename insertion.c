#include<stdio.h>
void insrSort(int,int arr[]);
int main()
{
    int n,arr[25],result;
    printf("Enter the size of array:");
    scanf("%d",&n);

    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    insrSort(n,arr);

}
void insrSort(int n,int arr[])
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(temp<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
