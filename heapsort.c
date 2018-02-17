#include <stdio.h>

void heapify(int a[], int n)
{
int c,p,k,item;

      	for ( k = 1; k < n; k++)
      	{
      		item = a[k];        	
            		c = k;              		
            		p = (c-1) / 2;          	

            		while ( c > 0 && item > a[p] )
            		{		        	

            			a[c] = a[p];  	
                  		c = p;        	

                  		p = (c-1) / 2;    	
            		}

            		a[c] = item;        
      	}
}


void adjust(int a[], int n)
{
        	int c,p,item;

       	 p = 0;		
        	 item = a[p];
       	 c = 2*p+1;	
        	while ( c <= n-1 )			
        	{
                	if ( c+1 <= n-1 )			
			if ( a[c] < a[c+1] ) c++;	
                	if ( item < a[c] )			
                	{
                        		a[p] = a[c];		
                        		p = c;			
                        		c = 2*p+1;		
                	}
                	else
                        		break;			
        	}
        	a[p] = item;				
}

void heapsort(int a[], int n)
{    
int i, temp;
      	heapify(a,n);
       	for ( i = n-1; i > 0; i--)
       	{
                     temp = a[0], a[0] = a[i], a[i] = temp;
                     adjust(a,i);
       	}
}

/* function to sort shown in example 6.9*/

void main()
{
    int a[20],n,i;

    printf("Enter no. of elements to sort\n");
    scanf("%d",&n);
        printf("Enter the elments to sort\n");
        for ( i = 0; i < n; i++)	scanf("%d",&a[i]);
	
		heapsort(a,n);
        	
		printf("The sorted array is\n");
       	for ( i = 0; i < n; i++)
        {
           	printf("%d\n",a[i]);
        }
}
