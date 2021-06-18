#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000

int count;
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int low,int high)
{
    int i,j,pivot;
    pivot=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(i<=high && pivot>=a[i])
        {
            i++;
            count++;
        }
        while(pivot<a[j])
        {
            j--;
            count++;
        }
        if(i<j)
            swap(&a[i],&a[j]);
        else
        {
            swap(&a[low], &a[j]);
            return j;
        }
    }
}
void quicksort(int a[],int low,int high)
{
    int i;
    if(low<high)
    {
        i=partition(a,low,high);
        quicksort(a,low,i-1);
        quicksort(a,i+1,high);
    }
}
int main()
{
    int a[SIZE],b[SIZE],c[SIZE],i,j,n,c1,c2,c3;
    //printf("Correctness proof:\n");
    printf("Enter no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);
    quicksort(a,1,n);
    printf("After sorting:\n");
    for(i=1;i<=n;i++)
        printf("%d ", a[i]);
    printf("\nThe number of times conditional statement has run is %d \n",count);
    printf("\nAnalysis of quick sort:\n");
    printf("Size\t Increasing\t Decreasing\t Random\n");
    for(i=16;i<4100;i*=2)
    {
        for(j=1;j<=i;j++)
        {
            a[j]=j;
            b[j]=i-j+1;
            c[j]=(rand()%i)+1;
        }
        count=0;
        quicksort(a,1,i);
        c1=count;
        count=0;
        quicksort(b,1,i);
        c2=count;
        count=0;
        quicksort(c,1,i);
        c3=count;
        printf("%d\t %10d\t %10d\t %10d\n",i,c1,c2,c3);
    }
    return 0;
}