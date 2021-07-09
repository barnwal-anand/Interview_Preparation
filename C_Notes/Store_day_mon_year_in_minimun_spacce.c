When we create a file in Windows, the following formula is applied to it:

(Year-1980) * 512 + Month * 32 + Day

A 2-byte resultant number is then stored on the disk.
For every file, date and time are stored as 2-byte entries.
In this 2-byte number, the left most 7 bits contain the year,
the middle 4 bits contain the month,
and the right most 5 bits contain the day.
*/

# include <stdio.h>
int main( )
{
	// Initialize variable with 2 byte number
	short int dt = 9766 ;
	// Declare variables for storing date, month and year
	short int date, month, year, temp ;
    // Extract year
	year = ( dt >> 9 )+1980 ;
	// Extract month
	temp = dt << 7 ;
	month = temp >> 12 ;
	// Extract date
	temp = dt << 11 ;
	date = temp >> 11 ;
	// Display day, month, and year
	printf ( "%d %d %d\n", date, month, year ) ;
}

Output
d m yyyy
6 1 1999
