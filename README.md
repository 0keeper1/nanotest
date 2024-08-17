# NaNotest

NaNotest is minimalistic testing library for C, focused to be lightweight and simple.

# Examples

- Single test example

```c
void test_compare()
{
	int x, y;
	x = do_something();
	y = do_something();
	NANO_ASSERT_EQ_INT( "cmp x and y", x, y );
}

int main()
{
	NANO_SINGLE_TEST( test_compare );
	return 0;
}
```

You can find a full example of the NaNotest usage example [here](./example/).

# License

This library is published under [MIT License](./LICENSE).
