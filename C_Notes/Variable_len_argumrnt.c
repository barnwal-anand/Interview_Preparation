# include <stdio.h>
# include <stdarg.h>
int findmax ( int, ... ) ;
int main( )
{
	int  max ;

	max = findmax ( 5, 23, 15, 1, 92, 50 ) ;
	printf ( "maximum = %d\n", max ) ;

	max = findmax ( 3, 100, 300, 29 ) ;
	printf ( "maximum = %d\n", max ) ;

	return 0 ;
}
int findmax ( int  tot_num, ... )
{
	int  max, count, num ;
	va_list  ptr ;

	va_start ( ptr, tot_num ) ;
	max = va_arg ( ptr, int ) ;
	for ( count = 1 ; count < tot_num ; count++ )
	{
		num = va_arg ( ptr, int ) ;
		if ( num > max )
			max = num ;
	}
	return ( max ) ;
}

/*
The fixed number of arguments are accessed in the normal way; whereas,
the optional arguments are accessed using the macros: va_start and va_arg.

va_start is used to initialize a pointer to the beginning of the list of optional arguments.
va_arg is used to advance the pointer to the next argument.

The first argument passed to findmax( ) is collected in the variable: tot_num.
findmax( ) begins with a declaration of a pointer, ptr, of the type va_list.

The statement, va_start ( ptr, tot_num ), sets up ptr such that it points to the first variable argument in the list.
In the first call to findmax( ), ptr would now point to 23.

The statement, max = va_arg ( ptr, int ), would assign the integer being pointed to by ptr to max.
Thus, 23 would be assigned to max, and ptr would now start pointing to the next argument, i.e., 15.
*/
