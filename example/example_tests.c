#include "../src/lib.h"
#include "example_functions.h"
#include <stdbool.h>

NANO_FUNCTION( test_sum_int, {
	int x, y, result;

	x = 3;
	y = 4;

	result = sum_int( x, y );

	NANO_ASSERT_EQ_INT( "3 + 4 must be equal to 7", 7, result );

	x = 100;
	y = 200;
	result = sum_int( x, y );

	NANO_ASSERT_NOTEQ_INT( "100 + 200 must not be 301", 301, result );

	x = 8;
	y = 1;
	result = sum_int( x, y );

	NANO_ASSERT_LE_INT( "9 + 3 must be less than 10", 10, result );

	x = 9;
	y = 3;
	result = sum_int( x, y );

	NANO_ASSERT_GE_INT( "9 + 3 must be greater than 10", 10, result );
} )

NANO_FUNCTION( test_sum_float, {
	float x, y, result;

	x = 3.1f;
	y = 4.4f;

	result = sum_float( x, y );

	NANO_ASSERT_EQ_FLOAT( "3.1 + 4.4 must be equal 7.5 to", 7.5f, result );

	x = 7.3f;
	y = 4.2f;
	result = sum_float( x, y );

	NANO_ASSERT_NOTEQ_FLOAT( "7.3 + 4.2 must not be equal to 5.2", 5.2f, result );

	x = 8.1f;
	y = 1.4f;
	result = sum_float( x, y );

	NANO_ASSERT_LE_FLOAT( "8.1 + 1.4 must be less than 10.9", 10.9f, result );

	x = 9.7f;
	y = 3.2f;
	result = sum_float( x, y );

	NANO_ASSERT_GE_FLOAT( "9.7 + 3.2 must be greater than 10.5", 10.5f, result );
} )

NANO_FUNCTION( test_is_odd, {
	bool result;
	int num;

	num = 2;
	result = is_odd( num );

	NANO_ASSERT_FALSE( "2 is an even number, we expect result to be false", result );

	num = 3;
	result = is_odd( num );

	NANO_ASSERT_TRUE( "3 is an odd number, we expect result to be true", result );
} )

NANO_FUNCTION( test_is_n, {
	NANO_ASSERT_TRUE( "n is equal to n", is_n( 'n' ) );
	NANO_ASSERT_FALSE( "m is not equal to n", is_n( 'm' ) );
} )

NANO_FUNCTION( test_next_char, {
	char c = 'a';
	NANO_ASSERT_EQ_CHAR( "b is next char of a in ASCII table", ( char )'b', next_char( c ) );
	NANO_ASSERT_NOTEQ_CHAR( "c is not next char of a in ASCII table", ( char )'c', next_char( c ) );
} )

NANO_FUNCTION( test_ptr_cmp, {
	int num = 1;
	int *x = int_ptr( &num );
	NANO_ASSERT_EQ_PTR( "expected and actual value are same pointers", x, x );

	int *y;
	NANO_ASSERT_NOTEQ_PTR( "y is a wild pointer, not equal to x", x, y );
} )

NANO_FUNCTION( test_size, {
	int x = 10;
	NANO_ASSERT_EQ_SIZE( "size of same value must be equal", x, x );
} )

NANO_FUNCTION( test_ignored, {} )

NANO_MAIN( {
	// single test
	NANO_SINGLE_TEST( test_is_n );

	// group test
	NANO_GROUP_TEST( "Group functions test", test_is_odd, test_sum_int, test_sum_float, test_next_char,
			 test_ptr_cmp, test_size );

	// ignored test
	NANO_IGNORE_TEST( "Empty test must be ignored", test_ignored );
} )