#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum T_TYPES
{
	T_BOOL,
	T_INT,
	T_CHAR,
	T_FLOAT,
	UNKNOWN,
};

#define Type( x ) _Generic( ( x ), _Bool: T_BOOL, float: T_FLOAT, char: T_CHAR, int: T_INT, default: UNKNOWN )

static unsigned int TOTAL_TEST_COUNTER = 0;
static unsigned int TOTAL_FAILED_COUNTER = 0;
static unsigned int TOTAL_IGNORED_COUNTER = 0;
static unsigned int TOTAL_SUCCESSFUL_COUNTER = 0;
static unsigned int TOTAL_TEST_COUNTER_PER_FUNCTION = 0;
static unsigned int TOTAL_FAILED_COUNTER_PER_FUNCTION = 0;
static unsigned int TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION = 0;

/**
 * @brief Runs one single test.
 * @param func The test function to be executed.
**/
#define NANO_SINGLE_TEST( func, ... )                                                                                  \
	do                                                                                                             \
	{                                                                                                              \
		( func )( __VA_ARGS__ );                                                                               \
	} while ( 0 )

/**
 * @brief Ignores one test with provided reason.
 * @param REASON Reason that we ignored the test.
 * @param func   Ignored test function.
**/
#define NANO_IGNORE_TEST( REASON, func )                                                                               \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_IGNORED_COUNTER++;                                                                               \
		fprintf( stderr, "vvv %s\n\n", #func );                                                                \
		fprintf( stderr, "* \t\"%s\" %s:%d Ignored.\n", REASON, __FILE__, __LINE__ );                          \
		fprintf( stderr, "vvv\n" );                                                                            \
	} while ( 0 )

/**
 * @brief Runs a group of provided test in order.
 * @param GROUPTESTNAME A human-readable name to identify the group of tests.
 * @param ... Test functions to be called.
**/
#define NANO_GROUP_TEST( GROUPTESTNAME, ... )                                                                          \
	do                                                                                                             \
	{                                                                                                              \
		void ( *funcs[] )( void ) = { __VA_ARGS__ };                                                           \
		const char *fnames = #__VA_ARGS__;                                                                     \
		size_t count = sizeof( funcs ) / sizeof( funcs[0] );                                                   \
		char fnamescp[strlen( fnames ) + 1];                                                                   \
		strncpy( fnamescp, fnames, sizeof( fnamescp ) );                                                       \
		char *fname = strtok( fnamescp, ", " );                                                                \
		for ( size_t i = 0; i < count; ++i )                                                                   \
		{                                                                                                      \
			( funcs[i] )();                                                                                \
			fname = strtok( NULL, ", " );                                                                  \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual integer is equal to given expected integer value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_EQ_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ),                              \
				"Actual and expected must be in int type" );                                           \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected: %d, got: %d.\n", TESTNAME, __FILE__,       \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual integer is greater than given expected integer value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_GE_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ),                              \
				"Actual and expected must be in int type" );                                           \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected %d to be greater than %d.\n", TESTNAME,     \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual integer is less than given expected integer value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_LE_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ),                              \
				"Actual and expected must be in int type" );                                           \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected < actual )                                                                               \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected %d to be less than %d.\n", TESTNAME,        \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual integer is not equal to given expected integer value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_NOTEQ_INT( TESTNAME, expected, actual )                                                            \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ),                              \
				"Actual and expected must be in int type" );                                           \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: %d not expected to be equal to %d .\n", TESTNAME,    \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual float is equal to given expected float value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_EQ_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ),                          \
				"Actual and expected must be in float type" );                                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected %f, got: %f.\n", TESTNAME, __FILE__,        \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual float is not equal to given expected float value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_NOTEQ_FLOAT( TESTNAME, expected, actual )                                                          \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ),                          \
				"Actual and expected must be in float type" );                                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected: %f, got: %f.\n", TESTNAME, __FILE__,       \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual float is greater than given expected float value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_GE_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ),                          \
				"Actual and expected must be in float type" );                                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected %f to be greater than %f.\n", TESTNAME,     \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual float is less than given expected float value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_LE_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ),                          \
				"Actual and expected must be in float type" );                                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected < actual )                                                                               \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected %f to be less than %f.\n", TESTNAME,        \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual char is equal to given expected char value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_EQ_CHAR( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_CHAR && Type( actual ) == T_CHAR ),                            \
				"Actual and expected must be in char type" );                                          \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected '%c', got: '%c'.\n", TESTNAME, __FILE__,    \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual char is not equal to given expected char value.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_NOTEQ_CHAR( TESTNAME, expected, actual )                                                           \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( expected ) == T_CHAR && Type( actual ) == T_CHAR ),                            \
				"Actual and expected must be in char type" );                                          \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected '%c', got: '%c'.\n", TESTNAME, __FILE__,    \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual pointer is equal to given expected pointer.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_EQ_PTR( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected: %p, got: %p.\n", TESTNAME, __FILE__,       \
				 __LINE__, expected, actual );                                                         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual pointer is not equal to given expected pointer.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_NOTEQ_PTR( TESTNAME, expected, actual )                                                            \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: %p not expected to be equal to %p .\n", TESTNAME,    \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual boolean is true.
 * @param TESTNAME A human-readable name to identify the test.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_TRUE( TESTNAME, actual )                                                                           \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( actual ) == T_BOOL ), "Actual must be in bool type" );                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( !actual )                                                                                         \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected actual value to be true, but got false.\n", \
				 TESTNAME, __FILE__, __LINE__ );                                                       \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual boolean is false.
 * @param TESTNAME A human-readable name to identify the test..
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_FALSE( TESTNAME, actual )                                                                          \
	do                                                                                                             \
	{                                                                                                              \
		_Static_assert( ( Type( actual ) == T_BOOL ), "Actual must be in bool type" );                         \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( actual )                                                                                          \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected actual value to be false, but got true.\n", \
				 TESTNAME, __FILE__, __LINE__ );                                                       \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual value size is equal to given expected value size.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_EQ_SIZE( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( sizeof( expected ) != sizeof( actual ) )                                                          \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n", TESTNAME,     \
				 __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                           \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual value size is not equal to given expected value size.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_NOTEQ_SIZE( TESTNAME, expected, actual )                                                           \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( sizeof( expected ) == sizeof( actual ) )                                                          \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n", TESTNAME,     \
				 __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                           \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual value size is greater than given expected value size.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_GE_SIZE( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( sizeof( expected ) > sizeof( actual ) )                                                           \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n", TESTNAME,     \
				 __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                           \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/**
 * @brief Checks if actual value size is less than given expected value size.
 * @param TESTNAME A human-readable name to identify the test.
 * @param expected The value the we that we expect to receive.
 * @param actual   The value which we received.
**/
#define NANO_ASSERT_LE_SIZE( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
		TOTAL_TEST_COUNTER++;                                                                                  \
		TOTAL_TEST_COUNTER_PER_FUNCTION++;                                                                     \
		if ( sizeof( expected ) < sizeof( actual ) )                                                           \
		{                                                                                                      \
			TOTAL_FAILED_COUNTER++;                                                                        \
			TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                                           \
			fprintf( stderr, "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n", TESTNAME,     \
				 __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                           \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			TOTAL_SUCCESSFUL_COUNTER++;                                                                    \
			TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                                       \
			fprintf( stderr, "+ \t\"%s\" %s:%d Ok.\n", TESTNAME, __FILE__, __LINE__ );                     \
		}                                                                                                      \
	} while ( 0 )

/** 
 * @brief Create test function with more information.
 * @param FUNCTIONNAME Name of test function.
 * @param CODEBLOCK Place a block of code that will run in the function.
**/
#define NANO_FUNCTION( FUNCTIONNAME, CODEBLOCK )                                                                       \
	void FUNCTIONNAME( void )                                                                                      \
	{                                                                                                              \
		TOTAL_TEST_COUNTER_PER_FUNCTION = 0;                                                                   \
		TOTAL_FAILED_COUNTER_PER_FUNCTION = 0;                                                                 \
		TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION = 0;                                                             \
		fprintf( stderr, ">>> %s\n\n", #FUNCTIONNAME );                                                        \
		CODEBLOCK;                                                                                             \
		fprintf( stderr, "\r\nTESTS: (%u) | SUCCESSFUL: (%u) | FAILED: (%u)\r\n",                              \
			 TOTAL_TEST_COUNTER_PER_FUNCTION, TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION,                       \
			 TOTAL_FAILED_COUNTER_PER_FUNCTION );                                                          \
		fprintf( stderr, "<<<\n" );                                                                            \
	}

/** 
 * @brief The main function constructor.
 * @param CODEBLOCK Place a block of code that will run in the main function.
**/
#define NANO_MAIN( CODEBLOCK )                                                                                         \
	int main( void )                                                                                               \
	{                                                                                                              \
		CODEBLOCK;                                                                                             \
		fprintf( stderr,                                                                                       \
			 "\r\nTOTAL TESTS: (%u) | TOTAL SUCCESSFUL TESTS: (%u) | TOTAL FAILED TESTS: (%u) | TOTAL "    \
			 "IGNORED TESTS: (%u)\r\n",                                                                    \
			 TOTAL_TEST_COUNTER, TOTAL_SUCCESSFUL_COUNTER, TOTAL_FAILED_COUNTER, TOTAL_IGNORED_COUNTER );  \
		return 0;                                                                                              \
	}
