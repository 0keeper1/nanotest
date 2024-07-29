# NaNotest

NaNotest provides simple macros for unit testing. 

# Usage

- Single Test:

    ```c
    void comparexandy() { 
        int x, y;
        x = 3; y = 2;
        NANO_ASSERT_EQ_INT("cmp x and y", x, y);
    }

    int main () {
        NANO_SINGLE_TEST(comparexandy);
        return 0;
    }
    ```
- Group Test:
    
    ```c
    void test1() { /* something */ }
    void test2() { /* something */ }
    void test3() { /* something */ }
    int main () {
        NANO_GROUP_TEST("examples", test1, test2, test3);
        return 0;
    }
    ```