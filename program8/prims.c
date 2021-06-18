#include<stdio.h>
void main() {
	int a,b,u,v,n,i,j,ne=1;
	int visited[10]= {0}, min,mincost=0,cost[10][10];
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
	visited[1]=1;
	printf("\n");
	while(ne<n) {
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
		     if(visited[i]!=0) {
				min=cost[i][j];
				a=i;
				u=i;
				b=j;
				v=j;
			}
		if(visited[u]==0 || visited[v]==0) {
			printf("Edge %d:(%d %d) cost:%d\n",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("Minimun cost=%d\n",mincost);
}

/*
0 4 5 999 999
999 0 6 7 999
999 999 0 999 5
3 999 8 999 999
999 999 999 4 999
*/