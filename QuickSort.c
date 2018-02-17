#include <stdio.h>
#include <time.h>

int max(int a,int b)
{
        return ( a > b ) ? a : b;
}

int partition(int a[],int low,int high)
{
        int i,j,temp,key;

        
        key = a[low]; 
        i = low+1;
        j = high;

        while(1)
        {
                while ( i < high && key >= a[i]) i++;

                while ( key < a[j] ) j--;

                if ( i < j )
                {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }
                else
                {
                        temp = a[low];
                        a[low] = a[j];
                        a[j] = temp;
                        return j;
                }
        }
}

void quicksort(int a[], int low, int high)
{
        int j;

        if ( low < high )
        {
                j = partition(a,low,high);
                quicksort(a,low,j-1);
                quicksort(a,j+1,high);
        }
}


void main()
{
        int i,n,a[20];

		printf("Enter the value for n\n");
        scanf("%d",&n);

        printf("Enter the numbers to be sorted\n");
        for (i=0; i < n; i++) scanf("%d",&a[i]);

        quicksort(a,0,n-1);

        printf("The sorted array is\n");
        for(i=0; i < n; i++) printf("%d\n",a[i]);

        getch();
}
