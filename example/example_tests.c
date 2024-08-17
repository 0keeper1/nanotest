#include "../src/lib.h"
#include "example_functions.h"
#include <stdbool.h>

void test_sum()
{
	int x, y, result;
	x = 3;
	y = 4;

	result = sum( x, y );

	NANO_ASSERT_EQ_INT( "test sum function", 7, result );

	x = 100;
	y = 200;
	result = sum( x, y );

	NANO_ASSERT_EQ_INT( "test sum function", 300, result );
}

void test_is_odd()
{
	bool result;
	int num;

	num = 2;
	result = is_odd( num );

	NANO_ASSERT_EQ_BOOL( "test is odd: false", false, result );

	num = 3;
	result = is_odd( num );

	NANO_ASSERT_EQ_BOOL( "test is odd: true", true, result );
}

void test_is_n()
{
	NANO_ASSERT_EQ_BOOL( "is n", true, is_n( 'n' ) );
	NANO_ASSERT_EQ_BOOL( "isn't n", false, is_n( 'm' ) );
}

int main()
{
	// single test
	NANO_SINGLE_TEST( test_is_n );

	// group test
	NANO_GROUP_TEST( "math functions test", test_is_odd, test_sum );

	return 0;
}
