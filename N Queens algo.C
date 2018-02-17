 #include <stdio.h>
#include <math.h>

/* Print the solution as on chess board */
void print_solution(int n,int x[])
{
 int i,j,c[10][10];
 /* No queen has placed initially */
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   c[i][j]='-';
  }
 }

 /* Place the queens on the chess board */
 for(i=1;i<=n;i++)
 {
  c[i][x[i]]='Q';
 }

 /* Print where the queens have been placed on chess board */
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("% c\t ",c[i][j]);
  }
  printf("\n");
 }
}

/* Function to check whether the queen can be placed successfully or not */
int place(int x[],int k)
{
 int i;
 for(i=1;i<=k-1;i++)
 {
 /* Attack column or diagonal it is unsuccessful */
  if(x[i]==x[k] || i-x[i]==k-x[k] || i+x[i]==k+x[k])
  {
   return 0;
  }
 }
 /* kth queen can be successfully placed */
 return 1;
}

void nqueens(int n)
{
 int k,x[10],i,count;
 k=1;          /* Select the first quuen */
 x[k]=0;
 count=0;      /* Number of solutions */

 while(k!=0)        /* Any solution exists ? */
 {
  x[k]++;      /* Place the kth queen in next column */
		/* Satisfy both explicit and implicit constraint */
  while((x[k]<=n) && (!place(x,k)))
  {
   x[k]++;      /* Place queen in next column */
  }
		/* if queen successully placed */
  if(x[k]<=n)
  {
			/* If all queens are placed */
   if(k==n)
   {
  //  for(i=1;i<=n;i++)
  //   printf("%d",x[i]);
      count++;
      printf("Sol no. =%d\n",count);

      print_solution(n,x);
      printf("\n");
      getch();
   }
   else
   {
    k++;		/* select the next queen */
    x[k]=0;
   }
  }
  else
  {
   k--;			/*Backtrack and select previous queen */
  }
 }

  /* No more solution exists */
// return;
}

void main()
{
 int n;  clrscr();

 printf("Enter the no. of queens\n");
 scanf("%d",&n);
 nqueens(n);
 getch();
}