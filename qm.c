#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
struct student
{
char name[20];
float height;
float weight;
};
int partition(struct student* st, int lb, int ub)
{
    int pivot=st[lb].height;
    int start=lb;
    int end=ub;
    struct student temp;
    while(start<end)
    {
        while(st[start].height<=pivot)
        {
            start++;
        }
        while(st[end].height>pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp=st[start];
            st[start]=st[end];
            st[end]=temp;
        }

    }
    temp=st[lb];
    st[lb]=st[ub];
    st[ub]=temp;

    return end;
}
void quicksort(struct student* st, int lb, int ub)
{
    if(lb < ub)
    {
        int q = partition(st, lb ,ub);
        quicksort(st, lb, q-1);
        quicksort(st, q, ub);
    }
}
void merge(struct student* st1, int lb, int m, int ub)
{
    int i=lb;
    int j= m+1;
    int k=lb;
    struct student temp[ub];
    while(i<=m && j<=ub)
    {
        if(st1[i].height<=st1[j].height)
        {
            temp[k]=st1[i];
            i++;
        }
        else
        {
            temp[k]=st1[j];
            j++;
        }
        k++;
    }
}
void mergesort(struct student* st1, int p, int r)
{
if(p < r)
{
int q = floor((p+r)/2);
mergesort(st1, p, q);
mergesort(st1, q+1, r);
merge(st1, p, q, r);
}
}
void main()
{
int n;
char c;
printf("Enter the number of students\n");
scanf("%d", &n);
// FILE *fp = fopen("Student details.txt", "w");
// FILE *fpq = fopen("Quick student details.txt", "w");
// FILE *fpm = fopen("Merge student details.txt", "w");
// fprintf(fp, "NAME\t\tHEIGHT\tWEIGHT\n");
// fprintf(fpq, "NAME\t\tHEIGHT\tWEIGHT\n");
// fprintf(fpm, "NAME\t\tHEIGHT\tWEIGHT\n");

struct student* st = malloc(n * sizeof(struct student));

for(int i=0; i<n; i++)
{
    printf("\nEnter the student details\n");
    printf("Name = ");
    scanf("%c", &c);
    fgets(st[i].name, 20, stdin);
    st[i].name[strlen(st[i].name) - 1] = '\0'; 
    printf("Height = ");
    scanf("%f", &st[i].height);
    printf("Weight = ");
    scanf("%f", &st[i].weight);
}
FILE *fp = fopen("Student details.txt", "w");
fprintf(fp, "NAME\t\tHEIGHT\tWEIGHT\n");

printf("\nWriting to file...\n");
for(int i = 0; i < n; i++)
    fprintf(fp, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);

fclose(fp);

fp = fopen("Student details.txt", "r");
FILE *fpq = fopen("Quick student details.txt", "w");
fprintf(fpq, "NAME\t\tHEIGHT\tWEIGHT\n");

printf("\nPerforming quick sort...\n");
clock_t t = clock();
quicksort(st, 0, n-1);
t = clock() - t;

for(int i = 0; i < n; i++)
    fprintf(fpq, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);

fprintf(fpq, "\nTime taken = %lf", (double) t / CLOCKS_PER_SEC);

fclose(fpq);
//fclose(fp);

//fp = fopen("Student details.txt", "w");

for(int i = 1; i < =n; i++)
    fscanf(fp, "%s\t\t%f\t%f\n", st[i].name, &st[i].height, &st[i].weight);

fclose(fp);

fp = fopen("Student details.txt", "r");
FILE *fpm = fopen("Merge student details.txt", "w");
fprintf(fpm, "NAME\t\tHEIGHT\tWEIGHT\n");
printf("\nPerforming merge sort...\n");
t = clock();
mergesort(st, 0, n-1);
t = clock() - t;

for(int i = 0; i < n; i++)
    fprintf(fpm, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);

fprintf(fpm, "\nTime taken = %lf", (double) t / CLOCKS_PER_SEC);

printf("\nWrite successful.\n\n");
fclose(fpm);
fclose(fp);

}