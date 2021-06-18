#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;		     
	int a[10][10];		
	int i,j,k,node;
	int in[10]={0};		
	int v[10]={0};		
	
	printf("Enter n: ");
	scanf("%d",&n);// read the number of nodes

	printf("Enter Adj matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d", &a[i][j]);

			if(a[i][j] == 1)//check if vertex has indegree               
				in[j]++;			
		}
	}

	printf("\nTopological order: ");
	for(k=1;k<=n;k++) 
	{
        for(i=1;i<=n;i++)	
		{
			if(in[i] == 0 && v[i] == 0)
			{
				node = i;
				printf("%5d",node);/*print the node in the topological order*/			
				v[node] = 1;
				break;
			}
		}
		
           for(i=1;i<=n;i++)
			if(a[node][i] == 1)
				in[i]--;	
	}
	printf("\n\n");
}
