# NaNotest

NaNotest is minimalistic testing library for C, focused to be lightweight and simple.

# Examples

- Single test example

```c
NANO_FUNCTION( test_sum, {
	int x;
	int y;

	x = sum(3, 4);
	y = sum(5, 2);
	
	NANO_ASSERT_EQ_INT( "cmp x and y", x, y );
})

NANO_MAIN( {
	NANO_SINGLE_TEST( test_sum );
} )
```

You can find a full example of the NaNotest usage example [here](./example/).

# License

This library is published under [MIT License](./LICENSE).
