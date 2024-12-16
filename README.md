# unstdtest

unstdtest is minimalistic unit testing framework for C, focused to be lightweight and simple.

# Examples

- Single test example

```c
NANO_FUNCTION( test_sum, false, {
	int x;
	int y;

	x = sum(3, 4);
	y = sum(5, 2);
	
	NANO_ASSERT_EQ_INT( "cmp x and y", x, y, false );
})

NANO_MAIN( {
	NANO_SINGLE_TEST( test_sum );
} )
```

# License

This library is published under [MIT License](./LICENSE).
