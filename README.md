# unstdtest

unstdtest is minimalistic unit testing framework for C, focused to be lightweight and simple.

# Examples

- Single test example

```c
FUNCTION( test_sum, false, {
	int x;
	int y;

	x = sum(3, 4);
	y = sum(5, 2);
	
	ASSERT_EQ_INT( "cmp x and y", x, y, false );
})

MAIN( {
	SINGLE_TEST( test_sum );
} )
```

# License

This library is published under [MIT License](./LICENSE).
