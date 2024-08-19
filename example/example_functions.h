#pragma once

#include "stdbool.h"

static inline int sum_int( int x, int y ) { return x + y; }

static inline int *int_ptr( int *x ) { return x; }

static inline float sum_float( float x, float y ) { return x + y; }

static inline bool is_odd( int x ) { return ( x % 2 ) != 0; }

static inline bool is_n( char c ) { return c == 'n'; }

static inline char next_char( char c ) { return ++c; }
