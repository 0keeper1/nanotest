#pragma once

#include <stdio.h>
#include <string.h>

#define NANO_SINGLE_TEST( func, ... )                                                                                  \
	{                                                                                                              \
		fprintf( stderr, "RUNNING THE %s ...\n", #func );                                                      \
		( func )( __VA_ARGS__ );                                                                               \
		fprintf( stderr, "EXITING THE %s ...\n", #func );                                                      \
	}

#define NANO_GROUP_TEST( GROUPTESTNAME, ... )                                                                          \
	do                                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "Executing test group \"%s\"...\n", TESTGROUPNAME );                                  \
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

#define NANO_ASSERT_EQ_INT( TESTNAME, expect, actual )                                                                 \
	if ( expect != actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d Got %d.\n", TESTNAME, __FILE__, __LINE__,  \
			 expect, actual );                                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_GE_INT( TESTNAME, expect, actual )                                                                 \
	if ( expect > actual )                                                                                         \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d to be greater than %d.\n", TESTNAME,       \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_LE_INT( TESTNAME, expect, actual )                                                                 \
	if ( expect < actual )                                                                                         \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d to be less than %d.\n", TESTNAME,          \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_NOTEQ_INT( TESTNAME, expect, actual )                                                              \
	if ( expect == actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: %d Not expected to be equal to %d .\n", TESTNAME,      \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_FLOAT( TESTNAME, expect, actual )                                                               \
	if ( expect != actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f Got %f.\n", TESTNAME, __FILE__, __LINE__,  \
			 expect, actual );                                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_GE_FLOAT( TESTNAME, expect, actual )                                                               \
	if ( expect > actual )                                                                                         \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f to be greater than %f.\n", TESTNAME,       \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	s else                                                                                                         \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_LE_FLOAT( TESTNAME, expect, actual )                                                               \
	if ( expect < actual )                                                                                         \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f to be less than %f.\n", TESTNAME,          \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_CHAR( TESTNAME, expect, actual )                                                                \
	if ( expect != actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected '%c' Got '%c'.\n", TESTNAME, __FILE__,        \
			 __LINE__, expect, actual );                                                                   \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_PTR( TESTNAME, expect, actual )                                                                 \
	if ( expect != actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %p Got %p.\n", TESTNAME, __FILE__, __LINE__,  \
			 expect, actual );                                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_NOTEQ_PTR( TESTNAME, expect, actual )                                                              \
	if ( expect == actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: %p Not expected to be equal to %p .\n", TESTNAME,      \
			 __FILE__, __LINE__, expect, actual );                                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_BOOL( TESTNAME, expect, actual )                                                                \
	if ( expect != actual )                                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %s Got %s.\n", TESTNAME, __FILE__, __LINE__,  \
			 expect ? "true" : "false", actual ? "true" : "false" );                                       \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_STRUCT_SIZE( TESTNAME, expect, actual )                                                         \
	if ( sizeof( expect ) != sizeof( actual ) )                                                                    \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected size %ld Got size %ld.\n", TESTNAME,          \
			 __FILE__, __LINE__, sizeof( expect ), sizeof( actual ) );                                     \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}
