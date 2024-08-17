#include "stdbool.h"

int sum_int( int x, int y ) { return x + y; }

int *int_ptr(int x)
{
	return &x;
}

float sum_float( float x, float y ) { return x + y; }

bool is_odd( int x ) { return ( x % 2 ) != 0; }

bool is_n( char c ) { return c == 'n'; }

char next_char( char c ) { return ++c; }
