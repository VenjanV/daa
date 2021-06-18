#include <stdio.h>
#include <stdlib.h>

int count=0;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0;
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		count++;
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
		//count++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
		//count++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = (l+r)/ 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int n,c1,c2,c3;
	int a[550],b[550],c[550];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&arr[i]); 
    }
	count=0;
	mergeSort(arr, 0, n - 1);
	printf("\nSorted array is \n");
	printArray(arr, n);
	printf("\nThe basic operation is executed %d times\n",count);
	
	
	//random array time complexity checking
	printf("\t\tlength \t\t ascending \t descending \t random\n");
    for(int i=16;i<550;i=i*2)
	{
		for(int j=0;j<i;j++)
		{
			a[j] =j;
			b[j]= i-j;
			c[j]= rand()%i;
		}
		count=0;
		mergeSort(a,0,i-1);
		c1 = count;
		count=0;
		mergeSort(b,0,i-1);
		c2 = count;
		count =0;
		mergeSort(c,0,i-1);
		c3 = count;
		count =0;
	
		printf("Basic operation: %d \t\t %d \t\t %d \t\t %d\n",i,c1,c2,c3);
	}
	return 0;
}
