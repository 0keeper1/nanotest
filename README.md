# NaNotest

NaNotest is minimalistic testing library for C, focused to be lightweight and simple.

# Examples

- Single test example

```c
int sum(int x, int y) { return x + y; }

void test_sum()
{
	int x, y;
	x = sum(3, 4);
	y = sum(5, 2);
	
	NANO_ASSERT_EQ_INT( "cmp x and y", x, y );
}

int main()
{
	NANO_SINGLE_TEST( test_sum );
	return 0;
}
```

You can find a full example of the NaNotest usage example [here](./example/).

# License

This library is published under [MIT License](./LICENSE).
