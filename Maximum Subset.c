#include <stdio.h>


void subset(int n, int d, int w[])
{
	int s,k,i,x[10];

	for (i=1; i <= n; i++) x[i] = 0;

	s = 0;
	k = 1;
	x[k] = 1;
	
	while (1)
	{
		if( k <= n && x[k] == 1)
		{
			if ( s+w[k] == d)
			{
				printf("Solution is \n");
				for (i = 1; i <= n; i++)
				{
					if (x[i] == 1)
						printf("%d ",w[i]);
				}
				printf("\n");
				x[k] = 0;
			} 
			else if (s + w[k] < d )
			{
				s += w[k];
			}
			else
			{
				x[k] = 0;
			}
		}
		else
		{
			k--;
			while ( k >0 && x[k] == 0)
			{
				k--;
			}

			if (k == 0) break;

			x[k] = 0;
			s = s-w[k];
		}
		k = k + 1;
		x[k] = 1;
	}
}

void main()
{
	int n,i,d,w[10];

	printf("Enter the value of n");
	scanf("%d",&n);

	printf("Enter the set in increasing order\n");
	for (i= 1; i <= n; i++)
		scanf("%d",&w[i]);

	printf("Enter the maximum subset value of D\n");
	scanf("%d",&d);

	subset(n,d,w);
	getch();
}