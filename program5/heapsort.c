#include<stdio.h>
#include<stdlib.h>
#define max 1000
int cmp=0;

void heapify(int a[max],int n){
	int i,j,k,v,flag;
	for(i=n/2;i>=1;i--){
		k=i;
		v=a[k];
		flag=0;
		while(!flag && 2*k<=n){
			j=2*k;
			if(j<n){
				++cmp;
				if(a[j]<a[j+1]){
					j=j+1;
				}
			}
			++cmp;
			if(v>=a[j])
			flag=1;
			else{
				a[k]=a[j];
				k=j;
			}
		}
		a[k]=v;
	}
}

void heapsort(int a[max],int n){
	int i,temp;
		for(i=n;i>1;i--){
			temp=a[1];
			a[1]=a[i];
			a[i]=temp;
			heapify(a,i-1);
		}
}

int main(){
	int i,n,a[max],b[max],c[max],j,c1,c2,c3;
	printf("enter n : ");
	scanf("%d",&n);
	printf("read array : ");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	heapify(a,n);
	heapsort(a,n);
	printf("sorted elements : ");
	for(i=1;i<=n;i++)
	printf("%d  ",a[i]);
	printf("\n");
	printf("no. of cmp : %d\n",cmp);
	
	printf("\t\tlength \t\t ascending \t descending \t random\n");
	for(int i=16;i<550;i=i*2){
		for(int j=0;j<i;j++)
		{
			a[j] =j;
			b[j]= i-j;
			c[j]= rand()%i;
		}
		cmp=0;
		heapify(a,i);
		heapsort(a,i);
		c1 = cmp;
		cmp =0;
		heapify(b,i);
		heapsort(b,i);
		c2 = cmp;
		cmp =0;
		heapify(c,i);
		heapsort(c,i);
		c3 = cmp;
	
		printf("Basic operation: %d \t\t %d \t\t %d \t\t %d\n",i,c1,c2,c3);
		
	}
	
	return 0;
}
