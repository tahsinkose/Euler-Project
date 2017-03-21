// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// An optimized version that uses reverse instead of sort for
// finding the next permutation
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
   

int findCeil (char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l,i;
 
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}
int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
 
// A utility function two swap two characters a and b
void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
// A utility function to reverse a string str[l..h]
void reverse(char str[], int l, int h)
{
while (l < h)
{
	swap(&str[l], &str[h]);
	l++;
	h--;
}
}

// Print all permutations of str in sorted order
void sortedPermutations ( char str[] )
{
	// Get size of string
	int size = strlen(str);
	int counter = 0;
	// Sort the string in increasing order
	qsort( str, size, sizeof( str[0] ), compare );

	// Print permutations one by one
	bool isFinished = false;
	while ( ! isFinished )
	{
		// print this permutation
		counter++;
		if(counter==1000000)
			printf ("%s \n", str);

		// Find the rightmost character which is smaller than its next
		// character. Let us call it 'first char'
		int i;
		for ( i = size - 2; i >= 0; --i )
		if (str[i] < str[i+1])
			break;

		// If there is no such chracter, all are sorted in decreasing order,
		// means we just printed the last permutation and we are done.
		if ( i == -1 )
			isFinished = true;
		else
		{
			// Find the ceil of 'first char' in right of first character.
			// Ceil of a character is the smallest character greater than it
			int ceilIndex = findCeil( str, str[i], i + 1, size - 1 );

			// Swap first and second characters
			swap( &str[i], &str[ceilIndex] );

			// reverse the string on right of 'first char'
			reverse( str, i + 1, size - 1 );
		}
	}
}
// Driver program to test above function
int main()
{
    char str[] = "0123456789";
    sortedPermutations( str );
    return 0;
}
