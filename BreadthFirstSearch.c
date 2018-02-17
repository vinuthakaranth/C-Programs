#include <stdio.h>
#include <process.h>

void bfs(int a[20][20], int n,int source,int t[20][2], int s[])
{
        int f,r,q[20];	// for queue operations
		int u,v;		// represent two vertices
		int k = 0;		// To store the result pair (u, v)
		int i;			// index variable
  
		for (i = 1; i <= n; i++)
        {
                s[i] = 0;	// No node is visited in the beginning
        }

        f = r = k = 0;	// Queue is empty
        q[r] = source;	// Insert source vertex into queue

        s[source] = 1;  // Add source to S (indicates source is visited)

        while ( f <= r )		// As long as queue is not empty
        {
                u = q[f++];		// Delete the next vertex to be explored from q

		for ( v = 1; v <= n; v++)	
                {
						// Find the nodes v which are adjacent to u

                        if ( a[u][v] == 1 && s[v] == 0 )
                        {
                                s[v] = 1;		// add v to s indicates that v is visited now

                                q[++r] = v;		// Insert new vertex into Q for exploration

                                t[k][0] = u;    // Output the pair (u, v)edge reachable from u to v stored 
                                t[k][1] = v;
                                k++;
                        }
                }
        }
}


void main()
{
        int n,i,j,source,a[20][20],t[20][2],flag;
		int	s[20];		// To insert the vertices which are visited

        printf("Enter the no. of nodes\n");
        scanf("%d",&n);

        printf("Enter the  adjacency matrix\n");
        for ( i = 0; i < n; i++)
        {
                for ( j = 0; j < n; j++)
                {
                        scanf("%d",&a[i][j]);
                }
        }

        printf("Enter the source\n");
        scanf("%d",&source);

        bfs(a, n,source,t, s);

		flag = 0;	// All nodes are reachable

        for( i = 0; i < n; i++)
        {
                if ( s[i] == 0 )
				{
					printf("vertex %d is not reachable\n",i);
					flag = 1;		// A vertex is not reachable
				}
				else
					printf("vertex %d is reachable\n",i);
        }

		if ( flag == 1)
			printf("Some nodes are not visited\n");
		else
		{
			printf("The BFS traversal is\n");
			for ( i = 0; i < n-1; i++)
			{
                printf("%d %d\n",t[i][0],t[i][1]);
			}
		}
}
