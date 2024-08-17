#pragma once

#include <stdio.h>
#include <string.h>

// Runs one single test.
#define NANO_SINGLE_TEST( func, ... )                                                                                  \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "RUNNING THE %s ...\n", #func );                                                      \
		( func )( __VA_ARGS__ );                                                                               \
		fprintf( stderr, "EXITING THE %s ...\n", #func );                                                      \
	} while ( 0 )

// Ignores one test with provided reason.
#define NANO_IGNORE_TEST( REASON, func )                                                                               \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "%s TEST IGNORED REASON: %s\n", #func, REASON );                                  \
	} while ( 0 )

// Runs a group of provided test in order.
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

// Checks if actual integer is equal to given expected integer value.
#define NANO_ASSERT_EQ_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
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

// Checks if actual integer is greater than given expected integer value.
#define NANO_ASSERT_GE_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
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

// Checks if actual integer is less than given expected integer value.
#define NANO_ASSERT_LE_INT( TESTNAME, expected, actual )                                                               \
	do                                                                                                             \
	{                                                                                                              \
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

// Checks if actual integer is not equal to given expected integer value.
#define NANO_ASSERT_NOTEQ_INT( TESTNAME, expected, actual )                                                            \
	do                                                                                                             \
	{                                                                                                              \
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


// Checks if actual float is equal to given expected float value.
#define NANO_ASSERT_EQ_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f Got %f.\n", TESTNAME,          \
				 __FILE__, __LINE__, expected, actual );                                               \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )

// Checks if actual float is greater than given expected float value.
#define NANO_ASSERT_GE_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f to be greater than %f.\n",     \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                 \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )

// Checks if actual float is less than given expected float value.
#define NANO_ASSERT_LE_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		if ( expected < actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected: %f to be less than %f.\n",       \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )

// Checks if actual char is equal to given expected char value.
#define NANO_ASSERT_EQ_CHAR( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
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

// Checks if actual pointer is equal to given expected pointer.
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

// Checks if actual pointer is not equal to given expected pointer.
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

// Checks if actual boolean is equal to given expected boolean value.
#define NANO_ASSERT_EQ_BOOL( TESTNAME, expected, actual )                                                              \
	do                                                                                                             \
	{                                                                                                              \
		if ( expected != actual )                                                                              \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected: %s, got %s.\n", TESTNAME,        \
				 __FILE__, __LINE__, expected ? "true" : "false", actual ? "true" : "false" );         \
		}                                                                                                      \
		else                                                                                                   \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )

// Checks if actual value size is equal to given expected value size.
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
