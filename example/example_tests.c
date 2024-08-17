#include "../src/lib.h"
#include "example_functions.h"
#include <stdbool.h>

void test_sum_int()
{
	int x, y, result;
	x = 3;
	y = 4;

	result = sum_int( x, y );

	NANO_ASSERT_EQ_INT( "test sum_int function", 7, result );

	x = 100;
	y = 200;
	result = sum_int( x, y );

	NANO_ASSERT_NOTEQ_INT( "test sum_int function", 301, result );

	x = 8;
	y = 1;
	result = sum_int( x, y );

	NANO_ASSERT_LE_INT( "test sum_int function", 10, result );

	x = 9;
	y = 3;
	result = sum_int( x, y );

	NANO_ASSERT_GE_INT( "test sum_int function", 10, result );
}

void test_sum_float()
{
	float x, y, result;
	x = 3.1;
	y = 4.4;

	result = sum_float( x, y );

	NANO_ASSERT_EQ_FLOAT( "test sum_float function", ( float )7.5, result );

	x = 8.1;
	y = 1.4;
	result = sum_float( x, y );

	NANO_ASSERT_LE_FLOAT( "test sum_float function", ( float )10.9, result );

	x = 9.7;
	y = 3.2;
	result = sum_float( x, y );

	NANO_ASSERT_GE_FLOAT( "test sum_float function", ( float )10.5, result );
}

void test_is_odd()
{
	bool result;
	int num;

	num = 2;
	result = is_odd( num );

	NANO_ASSERT_EQ_BOOL( "test is odd: false", ( _Bool ) false, result );

	num = 3;
	result = is_odd( num );

	NANO_ASSERT_EQ_BOOL( "test is odd: true", ( _Bool ) true, result );
}

void test_is_n()
{
	NANO_ASSERT_EQ_BOOL( "is n", ( _Bool ) true, is_n( 'n' ) );
	NANO_ASSERT_EQ_BOOL( "isn't n", ( _Bool ) false, is_n( 'm' ) );
}

void test_next_char()
{
	char c = 'a';
	NANO_ASSERT_EQ_CHAR( "test next char", ( char )'b', next_char( c ) );
}

void test_ptr_cmp()
{
	int num = 1;
	int *x = int_ptr( &num );
	NANO_ASSERT_EQ_PTR( "test pointer compare", x, x );

	int *y = NULL;
	NANO_ASSERT_NOTEQ_PTR( "test pointer compare", x, y );
}

void test_size()
{
	int x = 10;
	NANO_ASSERT_EQ_SIZE( "test size equal", x, x );
}

void test_ignored() {}

int main()
{
	// single test
	NANO_SINGLE_TEST( test_is_n );

	// group test
	NANO_GROUP_TEST( "Math functions test", test_is_odd, test_sum_int, test_sum_float, test_next_char, test_ptr_cmp,
			 test_size );

	// ignored test
	NANO_IGNORE_TEST( "Empty test must be ignored", test_ignored );

	return 0;
}
