#include <stdio.h>
#include <string.h>
#include <process.h>

/* Function to obtain the shift table for the characters in text string */
void shift_table(char p[], int t[])
{
	int i,m;

	/* Length of pattern string */
	m = strlen(p);
	
	/* Initialize the table with pattern length */
	for (i = 0; i < 128; i++) t[i] = m;	

	//Find the distance of first m-1 characters of string from the last character
	for (i = 0; i <= m-2; i++)
	{
		t[p[i]]= m - 1 - i;
	}
}

int horspool_pattern_match(char p[], char s[])
{
	int m, n, i, k, t[128];

	shift_table(p, t);	/* Obtain the shifs required when mismatch occur */
	
	m = strlen(p);		/* Compute the length of pattern string */
	n = strlen(s);		/* Compute the length of text string */
	i = m - 1;			/* Position of pattern string's right end */
	
	while ( i < n )		/* Repeat till the end of text string */
	{
		k = 0;
		while ( k < m && p[m-1-k] == s[i-k] )
		{
			k = k + 1;	/* Matching of pattern and text string in progress */
		}

		/* Pattern found ? */
		if ( k == m ) return i - m + 1;

		/* No match, so shift the pattern towards right */
		i = i + t[s[i]];
	}

	return -1;
}

void main()
{
	char p[20], s[40];
	int  pos;

	printf("Enter the text string\n");
	scanf("%s",s);

	printf("Enter the pattern string\n");
	scanf("%s",p);

	pos = horspool_pattern_match(p, s);

	if ( pos == -1)
	{
		printf("Pattern string not found\n");
		exit(0);
	}

	printf("Pattern string found at %d position\n",pos + 1);
	getch();
}