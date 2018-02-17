#include <stdio.h>

int binomial(int n, int k)
{
        int i,j,c[10][10];

        for ( i = 0; i <= n; i++)
        {
                for ( j = 0; j <= k; j++)
                {
                        if ( j == 0 || i == j)
							c[i][j] = 1;
						else
							c[i][j] = c[i-1][j-1] + c[i-1][j];
                }
        }

		return c[n][k];
}

void main()
{
	int n,k;

	printf("Enter the value of n and k such that n > k\n");
	scanf("%d %d",&n, &k);

	printf("C(%d,%d) = %d\n",n, k, binomial(n,k));
}
