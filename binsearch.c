#include<stdio.h>
int binSearch(int,int,int arr[]);
int main()
{
    int n,arr[25],key,result;
    printf("Enter the size of array:");
    scanf("%d",&n);

    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter the key to be searched:");
    scanf("%d",&key);
    result=binSearch(key,n,arr);
    if(result==-1)
        printf("The element is not present");
    else
        printf("The element is present in the position %d",result+1);
}
int binSearch(int key,int n,int arr[])
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(key==arr[mid])
            return mid;
        else if(key>mid)
                l=mid+1;
             else
                r=mid-1;
    }
    return -1;
}