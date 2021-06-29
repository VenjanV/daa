#include<stdio.h>
#include<stdlib.h>
int w[10],x[10],d,sum=0,b=0;

void sum_subset(int s,int k,int r){
	int i;
	x[k]=1;
	if(s+w[k]==d){
		printf("\nsubset %d : { ",++b);
		for(i=1;i<=k;i++){
			if(x[i]==1)
				printf("%d ",w[i]);
		}
		printf("}");
	}
	else if(s+w[k]+w[k+1]<=d)
		sum_subset(s+w[k],k+1,r-w[k]);
	if((s+r-w[k]>=d)&&(s+w[k+1]<=d)){
		x[k]=0;
		sum_subset(s,k+1,r-w[k]);
	}
}

int main(){
	int i,n;
	printf("Read number of elements : ");
	scanf("%d",&n);
	printf("\nread elelments in increasing order : ");
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum=sum+w[i];
	}
	printf("\nsubset max value : ");
	scanf("%d",&d);
	if(sum<d ||w[1]>d){
		printf("\nNo solution!!\n");
		exit(0);
	}
	sum_subset(0,1,sum);
	if(b==0)
	printf("\nNo Solution!!");
	printf("\n");
	return 0;
}
