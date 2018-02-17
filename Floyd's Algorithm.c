#include <stdio.h>

void floyd(int n, int cost[10][10],int d[10][10])
{
        int i,j,k;

        for ( i = 1; i <= n; i++)
        {
                for ( j = 1; j <= n; j++)
                {
                        d[i][j] = cost[i][j];
                }
        }

        for ( k = 1; k <= n; k++ )
        {
                for ( i = 1; i <= n; i++ )
                {
                        for ( j = 1; j <= n; j++ )
                        {       
                                if ( d[i][k] + d[k][j] < d[i][j] )
                                {
                                        d[i][j] = d[i][k] + d[k][j];
                                }
                        }
                }
       }
}

void main()
{
        int i,j,n,cost[10][10],p[10][10],d[10][10];

        printf("Enter the no. of nodes\n");
        scanf("%d",&n);
        printf("Enter the cost adjacency matrix\n");
        for ( i = 1; i <= n; i++)
        {
                for ( j = 1; j <= n; j++)
                {
                        scanf("%d",&cost[i][j]);
                }
        }

        floyd(n,cost,d);

        printf("The distance matrix is shown below\n");
        for ( i = 1; i <= n; i++)
        {
                for ( j = 1; j <= n; j++)
                {
                        printf("%5d",d[i][j]);
                }
                printf("\n");
        }
}
