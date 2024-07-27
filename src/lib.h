#pragma once

#include <stdio.h>

#define NANO_REG_TEST( function, ... )                                                                                 \
	{                                                                                                              \
		fprintf( stderr, "RUNNING THE %s ...\n", #function );                                                  \
		( function )( __VA_ARGS__ );                                                                           \
		fprintf( stderr, "EXITING THE %s ...\n", #function );                                                  \
	}

#define NANO_ASSERT_EQ_INT( TESTNAME, obj1, obj2 )                                                                     \
	if ( obj1 != obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d Got %d.\n", TESTNAME, __FILE__, __LINE__,  \
			 obj1, obj2 );                                                                                 \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_GE_INT( TESTNAME, obj1, obj2 )                                                                     \
	if ( obj1 > obj2 )                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d to be greater than %d.\n", TESTNAME,       \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_LE_INT( TESTNAME, obj1, obj2 )                                                                     \
	if ( obj1 < obj2 )                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %d to be less than %d.\n", TESTNAME,          \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_NOTEQ_INT( TESTNAME, obj1, obj2 )                                                                  \
	if ( obj1 == obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: %d Not expected to be equal to %d .\n", TESTNAME,      \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_FLOAT( TESTNAME, obj1, obj2 )                                                                   \
	if ( obj1 != obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f Got %f.\n", TESTNAME, __FILE__, __LINE__,  \
			 obj1, obj2 );                                                                                 \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_GE_FLOAT( TESTNAME, obj1, obj2 )                                                                   \
	if ( obj1 > obj2 )                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f to be greater than %f.\n", TESTNAME,       \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_LE_FLOAT( TESTNAME, obj1, obj2 )                                                                   \
	if ( obj1 < obj2 )                                                                                             \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %f to be less than %f.\n", TESTNAME,          \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_CHAR( TESTNAME, obj1, obj2 )                                                                    \
	if ( obj1 != obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected '%c' Got '%c'.\n", TESTNAME, __FILE__,        \
			 __LINE__, obj1, obj2 );                                                                       \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_PTR( TESTNAME, obj1, obj2 )                                                                     \
	if ( obj1 != obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %p Got %p.\n", TESTNAME, __FILE__, __LINE__,  \
			 obj1, obj2 );                                                                                 \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_NOTEQ_PTR( TESTNAME, obj1, obj2 )                                                                  \
	if ( obj1 == obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: %p Not expected to be equal to %p .\n", TESTNAME,      \
			 __FILE__, __LINE__, obj1, obj2 );                                                             \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_BOOL( TESTNAME, obj1, obj2 )                                                                    \
	if ( obj1 != obj2 )                                                                                            \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected %s Got %s.\n", TESTNAME, __FILE__, __LINE__,  \
			 obj1 ? "true" : "false", obj2 ? "true" : "false" );                                           \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}

#define NANO_ASSERT_EQ_STRUCT_SIZE( TESTNAME, obj1, obj2 )                                                             \
	if ( sizeof( obj1 ) != sizeof( obj2 ) )                                                                        \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Error: Expected size %ld Got size %ld.\n", TESTNAME,          \
			 __FILE__, __LINE__, sizeof( obj1 ), sizeof( obj2 ) );                                         \
	}                                                                                                              \
	else                                                                                                           \
	{                                                                                                              \
		fprintf( stderr, "\t%s file: %s line: %d Ok.\n", TESTNAME, __FILE__, __LINE__ );                       \
	}
