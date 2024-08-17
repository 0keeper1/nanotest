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

/**
 * @brief Runs one single test.
 * @param func The test function to be executed.
**/
#define NANO_SINGLE_TEST( func, ... )                                                                                  \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "RUNNING THE %s ...\n", #func );                                                      \
		( func )( __VA_ARGS__ );                                                                               \
		fprintf( stderr, "EXITING THE %s ...\n", #func );                                                      \
	} while ( 0 )

/**
 * @brief Ignores one test with provided reason.
 * @param REASON Reason that we ignored the test.
 * @param func   Ignored test function.
**/
#define NANO_IGNORE_TEST( REASON, func )                                                                               \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "%s TEST IGNORED REASON: %s\n", #func, REASON );                                      \
	} while ( 0 )

/**
 * @brief Runs a group of provided test in order.
 * @param GROUPTESTNAME A human-readable name to identify the group of tests.
 * @param ... Test functions to be called.
**/
#define NANO_GROUP_TEST( GROUPTESTNAME, ... )                                                                          \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "Executing test group \"%s\"...\n", GROUPTESTNAME );                                  \
		void ( *funcs[] )( void ) = { __VA_ARGS__ };                                                           \
		const char *fnames = #__VA_ARGS__;                                                                     \
		size_t count = sizeof( funcs ) / sizeof( funcs[0] );                                                   \
		char fnamescp[strlen( fnames ) + 1];                                                                   \
		strncpy( fnamescp, fnames, sizeof( fnamescp ) );                                                       \
		char *fname = strtok( fnamescp, ", " );                                                                \
		for ( size_t i = 0; i < count; ++i )                                                                   \
		{                                                                                                      \
			fprintf( stderr, "RUNNING THE %s ...\n", fname );                                              \
			( funcs[i] )();                                                                                \
			fprintf( stderr, "EXITING THE %s ...\n", fname );                                              \
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
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ) );                            \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected: %d, got: %d.\n", TESTNAME,       \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ) );                            \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %d to be greater than %d.\n",     \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ) );                            \
		if ( expected < actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %d to be less than %d.\n",        \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_INT && Type( actual ) == T_INT ) );                            \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: %d not expected to be equal to %d .\n",    \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ) );                        \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f, got: %f.\n", TESTNAME,        \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ) );                        \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected: %f, got: %f.\n", TESTNAME,       \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ) );                        \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f to be greater than %f.\n",     \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_FLOAT && Type( actual ) == T_FLOAT ) );                        \
		if ( expected < actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f to be less than %f.\n",        \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_CHAR && Type( actual ) == T_CHAR ) );                          \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected '%c', got: '%c'.\n", TESTNAME,    \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( expected ) == T_CHAR && Type( actual ) == T_CHAR ) );                          \
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected '%c', got: '%c'.\n", TESTNAME,    \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected: %p, got: %p.\n", TESTNAME,       \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( expected == actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: %p not expected to be equal to %p .\n",    \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( actual ) == T_BOOL ) );                                                      \
		if ( !actual )                                                                                         \
		{                                                                                                      \
			fprintf(                                                                                       \
			    stderr,                                                                                    \
			    "\t\"%s\" file: %s line: %d Error: expected actual value to be true, but got false.\n",    \
			    TESTNAME, __FILE__, __LINE__ );                                                            \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		_Static_assert( ( Type( actual ) == T_BOOL ) );                                                 \
		if ( actual )                                                                                          \
		{                                                                                                      \
			fprintf(                                                                                       \
			    stderr,                                                                                    \
			    "\t\"%s\" file: %s line: %d Error: expected actual value to be false, but got true.\n",    \
			    TESTNAME, __FILE__, __LINE__ );                                                            \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( sizeof( expected ) != sizeof( actual ) )                                                          \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected size: %ld, got size: %ld.\n",     \
				 TESTNAME, __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                 \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( sizeof( expected ) == sizeof( actual ) )                                                          \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected size: %ld, got size: %ld.\n",     \
				 TESTNAME, __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                 \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( sizeof( expected ) > sizeof( actual ) )                                                           \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected size: %ld, got size: %ld.\n",     \
				 TESTNAME, __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                 \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
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
		if ( sizeof( expected ) < sizeof( actual ) )                                                           \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected size: %ld, got size: %ld.\n",     \
				 TESTNAME, __FILE__, __LINE__, sizeof( expected ), sizeof( actual ) );                 \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )
