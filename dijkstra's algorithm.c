#include <stdio.h>
#include <process.h>
#include <conio.h>

void dijkstra(int n,int cost[10][10],int source, int dest, int d[],int p[],int s[])
{
        int i,j,u,v,min;

        for (i=0; i < n; i++)
        {
                d[i] = cost[source][i];
                s[i] = 0;
                p[i] = source;
        }

	s[source] = 1;
	for(i=1; i < n; i++)
	{
	       min = 9999;
		u = -1;
		for (j=0; j < n; j++)
		{
			if ( s[j] == 0 )
			{
				if ( d[j] < min )
				{
					min = d[j];
					u = j;
				}
			}
		}

				if (u == -1) return;

			s[u] = 1;

				if ( u == dest) return;

	       for ( v = 0; v < n; v++ )
		{
			if ( s[v] == 0 )
			{
				if ( d[u] + cost[u][v] < d[v] )
				{
					d[v] = d[u] + cost[u][v];
					p[v] = u;
				}
			}
		}
	}
}

void print_path(int source, int destination, int d[], int p[])
{
	int i;

	i = destination;
	while (i != source)
	{
		printf("%d <- ",i);
		i = p[i];
	}
	printf("%d = %d\n",i,d[destination]);
	printf("\n\n");

}


void main()
{
	int n,i,j,cost[10][10],a[10][10],d[10],p[10],s[10];

	printf("Enter the no. of nodes\n");
	scanf("%d",&n);

	printf("Enter the cost adjacency matrix\n");

	   for(i=0; i < n ; i++)
	{
		for (j=0; j < n; j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}


		for (i = 0; i < n; i++)
		{
			for ( j = 0; j < n; j++)
			{
				dijkstra(n,cost,i,j,d,p,s);

				if (d[j] == 9999)
					printf("%d is not reachable from %d \n",j, i);
				else
				{
					printf("The shortest path is shown below\n");
					print_path(i, j, d, p);
				}
			}
			getch();
		}
}
