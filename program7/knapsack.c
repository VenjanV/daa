#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
	// printing the matrix
	printf("\nThe knapsack matrix is: \n");
	for(i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			printf("%d\t",K[i][j]);
		}
		printf("\n");
	}
	
	i=n;
	w=W;
	printf("\nobjects\tweights\tprofits\n");
	while(w!=0 && i!=0){
		if(K[i][w]!=K[i-1][w]){
			printf("%d\t%d\t%d\n",i,wt[i-1],val[i-1]);
			w=w-wt[i-1];
		}
		i--;
	}
   
   return K[n][W];
}
int main()
{
    int i, n, val[20], wt[20], W;
    
    printf("Enter number of items:");
    scanf("%d", &n);
    
    printf("Enter weight of items: ");
    for(i = 0;i < n; ++i){
     scanf("%d",&wt[i]);
    }
    
    printf("Enter profits items: ");
    for(i = 0;i < n; ++i){
     scanf("%d", &val[i]);
    }
    
 
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf("maximum profit : %d\n", knapSack(W, wt, val, n));
    return 0;
}
