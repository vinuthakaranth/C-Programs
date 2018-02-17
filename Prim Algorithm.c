#include <stdio.h>
#include <process.h>

int prim(int n,int cost[10][10],int source,int t[10][10])
{
        int i,j,k,u,v,min,sum,d[10],s[10],nr[10];

        for (i=1; i <= n; i++)
        {
                d[i] = cost[source][i];
                s[i] = 0;
                nr[i] = source;
        }

        s[source] = 1;          /* Add source to S */
        k = 1;
        sum = 0;
        for(i=1; i < n; i++)
        {
                /* fund u and d[u] such that d[u] is minimum
                   and u in V-S
                 */
                min = 9999;
                u = 0;
                for (j=1; j <= n; j++)
                {
                        if ( s[j] == 0 )
                        {
                                if ( d[j] <= min )
                                {
                                        min = d[j];
                                        u = j;
                                }
                        }
                }

                /* store u and n[u] , the edge of spanning tree */
                t[k][1] = u, t[k][2] = nr[u];
                k += 1;

                /* find the cost of the minimum spanning tree */
                sum += cost[u] [nr[u]];
                /* add u to s */
                s[u] = 1;       

                /* find d[v] and n[v] for every v in V-S */
                for ( v = 1; v <= n; v++ )
                {
                        if ( s[v] == 0 )
                        {
                                if ( cost[u][v] < d[v] )
                                {
                                        d[v] = cost[u][v];
                                        nr[v] = u;
                                }
                        }
                }
        }

        return sum;

}

void main()
{
        int n,i,j,source,sum,cost[10][10],t[10][10];

        printf("Enter the no. of nodes\n");
        scanf("%d",&n);

        printf("Enter the cost adjacency matrix\n");
        for(i=1; i <= n ; i++)
        {
                for (j=1; j <= n; j++)
                {
                        scanf("%d",&cost[i][j]);
                }
        }

        printf("Enter the source\n");
        scanf("%d",&source);

        sum = prim(n,cost,source,t);

        if ( sum >= 9999 )
        {
                printf("Spanning tree does not exist\n");
                exit(0);
        }
        printf("The spanning tree is shown below\n");
        for ( i = 1; i <= n-1; i++)
                printf("%d %d\n",t[i][1],t[i][2]);
}
