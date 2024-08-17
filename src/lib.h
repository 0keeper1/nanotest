#pragma once

#include <stdio.h>
#include <string.h>

#define NANO_SINGLE_TEST( func, ... )                                                                                  \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "RUNNING THE %s ...\n", #func );                                                      \
		( func )( __VA_ARGS__ );                                                                               \
		fprintf( stderr, "EXITING THE %s ...\n", #func );                                                      \
	} while ( 0 )

#define NANO_IGNORE_TEST( WHY, func )                                                                                  \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "TEST IGNORED BECAUSE %s %s ...\n", WHY, #func );                                     \
	} while ( 0 )

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

#define NANO_ASSERT_GE_FLOAT( TESTNAME, expected, actual )                                                             \
	do                                                                                                             \
	{                                                                                                              \
		if ( expected > actual )                                                                               \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Error: expected %f to be greater than %f.\n",     \
				 TESTNAME, __FILE__, __LINE__, expected, actual );                                     \
		}                                                                                                      \
		s else                                                                                                 \
		{                                                                                                      \
			fprintf( stderr, "\t\"%s\" file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );           \
		}                                                                                                      \
	} while ( 0 )

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
