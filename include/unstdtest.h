#pragma once

#include <assert.h>
#include <stdio.h>
#include <string.h>

enum TTypes {
  T_BOOL,
  T_INT,
  T_SHORT,
  T_LONG,
  T_UINT,
  T_USHORT,
  T_ULONG,
  T_CHAR,
  T_UCHAR,
  T_FLOAT,
  UNKNOWN,
};

#define TYPE(x)                                                                \
  _Generic((x),                                                                \
      _Bool: T_BOOL,                                                           \
      float: T_FLOAT,                                                          \
      char: T_CHAR,                                                            \
      int: T_INT,                                                              \
      short: T_SHORT,                                                          \
      long: T_LONG,                                                            \
      unsigned int: T_UINT,                                                    \
      unsigned short: T_USHORT,                                                \
      unsigned long: T_ULONG,                                                  \
      unsigned char: T_UCHAR,                                                  \
      default: UNKNOWN)

static unsigned int TOTAL_TEST_COUNTER = 0, TOTAL_FAILED_COUNTER = 0,
                    TOTAL_IGNORED_COUNTER = 0, TOTAL_SUCCESSFUL_COUNTER = 0,
                    TOTAL_TEST_COUNTER_PER_FUNCTION = 0,
                    TOTAL_FAILED_COUNTER_PER_FUNCTION = 0,
                    TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION = 0;

/**
 * @brief Checks if the actual integer is equal to the expected integer value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if this test
 * fails.
 */
#define ASSERT_EQ_INT(TESTDESC, expected, actual, required)                    \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected != actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected: %d, got: %d.\n%s",    \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual integer is greater than the expected integer
 * value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if this test
 * fails.
 */
#define ASSERT_GR_INT(TESTDESC, expected, actual, required)                    \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected > actual) {                                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected %d to be greater than %d.\n%s",    \
          TESTDESC, __FILE__, __LINE__, expected, actual,                      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual integer is greater than or equal to the expected
 * integer value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if this test
 * fails.
 */
#define ASSERT_GTE_INT(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (!(expected <= actual)) {                                               \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected %d to be greater than or "     \
              "equal %d.\n%s",                                                 \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual integer is less than the expected integer value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if this test
 * fails.
 */
#define ASSERT_LE_INT(TESTDESC, expected, actual, required)                    \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected < actual || expected == actual) {                             \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected %d to be less than %d.\n%s",   \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual integer is less than or equal to the expected
 * integer value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_LTE_INT(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (!(expected >= actual)) {                                               \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected %d to be less than or equal "  \
              "%d.\n%s",                                                       \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual integer is not equal to the expected integer
 * value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_NEQ_INT(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_INT && TYPE(actual) == T_INT),         \
                   "Both expected and actual must be of type int");            \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected == actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: %d not expected to be equal to %d.\n%s",    \
          TESTDESC, __FILE__, __LINE__, expected, actual,                      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual float is equal to the expected float value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_EQ_FLOAT(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_FLOAT && TYPE(actual) == T_FLOAT),     \
                   "Both expected and actual must be of type float");          \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected != actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected %f, got: %f.\n%s",     \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual float is not equal to the expected float value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_NEQ_FLOAT(TESTDESC, expected, actual, required)                 \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_FLOAT && TYPE(actual) == T_FLOAT),     \
                   "Both expected and actual must be of type float");          \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected == actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected: %f, got: %f.\n%s",    \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if the actual float is greater than the expected float value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_GR_FLOAT(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_FLOAT && TYPE(actual) == T_FLOAT),     \
                   "Both expected and actual must be of type float");          \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected > actual) {                                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected %f to be greater than %f.\n%s",    \
          TESTDESC, __FILE__, __LINE__, expected, actual,                      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual float is less than given expected float value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_LE_FLOAT(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_FLOAT && TYPE(actual) == T_FLOAT),     \
                   "Both expected and actual must be of type float");          \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected < actual) {                                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected %f to be less than %f.\n%s",   \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is equal to given expected char value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_EQ_CHAR(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected != actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected '%c', got: '%c'.\n%s", \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is not equal to given expected char value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_NEQ_CHAR(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected == actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected '%c', got: '%c'.\n%s", \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is grater than given expected char value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_GR_CHAR(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected > actual) {                                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected '%c' to be greater than "      \
              "'%c'.\n%s",                                                     \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is grater than or equal given expected char
 *value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_GTE_CHAR(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (!(expected <= actual)) {                                               \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected '%c' to be greater than or "   \
              "equal '%c'.\n%s",                                               \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is less than given expected char value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_LE_CHAR(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected < actual || expected == actual)) {                            \
        TOTAL_FAILED_COUNTER++;                                                \
        TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                   \
        fprintf(                                                               \
            stdout,                                                            \
            "- \t\"%s\" %s:%d Error: expected '%c' to be less than '%c'.\n%s", \
            TESTDESC, __FILE__, __LINE__, expected, actual,                    \
            required ? "This test is required and must pass to continue.\n"    \
                     : "");                                                    \
        assert(required == false);                                             \
      }                                                                        \
    else {                                                                     \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual char is less than or equal given expected char value.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_LTE_CHAR(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    _Static_assert((TYPE(expected) == T_CHAR && TYPE(actual) == T_CHAR),       \
                   "Actual and expected must be in char type");                \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (!(expected >= actual)) {                                               \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected '%c' to be less than or "      \
              "equal '%c'.\n%s",                                               \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual pointer is equal to given expected pointer.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_EQ_PTR(TESTDESC, expected, actual, required)                    \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected != actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout, "- \t\"%s\" %s:%d Error: expected: %p, got: %p.\n%s",    \
              TESTDESC, __FILE__, __LINE__, expected, actual,                  \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual pointer is not equal to given expected pointer.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_NEQ_PTR(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (expected == actual) {                                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: %p not expected to be equal to %p.\n%s",    \
          TESTDESC, __FILE__, __LINE__, expected, actual,                      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual boolean is true.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_TRUE(TESTDESC, actual, required)                                \
  do {                                                                         \
    _Static_assert((TYPE(actual) == T_BOOL), "Actual must be in bool type");   \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (!actual) {                                                             \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected actual value to be true, but " \
              "got false.\n%s",                                                \
              TESTDESC, __FILE__, __LINE__,                                    \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual boolean is false.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_FALSE(TESTDESC, actual, required)                               \
  do {                                                                         \
    _Static_assert((TYPE(actual) == T_BOOL), "Actual must be in bool type");   \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (actual) {                                                              \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(stdout,                                                          \
              "- \t\"%s\" %s:%d Error: expected actual value to be false, "    \
              "but got true.\n%s",                                             \
              TESTDESC, __FILE__, __LINE__,                                    \
              required ? "This test is required and must pass to continue.\n"  \
                       : "");                                                  \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual value size is equal to given expected value size.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_EQ_SIZE(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (sizeof(expected) != sizeof(actual)) {                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n%s",    \
          TESTDESC, __FILE__, __LINE__, sizeof(expected), sizeof(actual),      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual value size is not equal to given expected value size.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_NEQ_SIZE(TESTDESC, expected, actual, required)                  \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (sizeof(expected) == sizeof(actual)) {                                  \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n%s",    \
          TESTDESC, __FILE__, __LINE__, sizeof(expected), sizeof(actual),      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual value size is greater than given expected value size.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_GR_SIZE(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (sizeof(expected) > sizeof(actual)) {                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n%s",    \
          TESTDESC, __FILE__, __LINE__, sizeof(expected), sizeof(actual),      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Checks if actual value size is less than given expected value size.
 * @param TESTDESC A human-readable description explaining the test.
 * @param expected The value expected to be received.
 * @param actual   The value that was received.
 * @param required Indicates whether the test process should panic if the test
 * fails.
 */
#define ASSERT_LE_SIZE(TESTDESC, expected, actual, required)                   \
  do {                                                                         \
    TOTAL_TEST_COUNTER++;                                                      \
    TOTAL_TEST_COUNTER_PER_FUNCTION++;                                         \
    if (sizeof(expected) < sizeof(actual)) {                                   \
      TOTAL_FAILED_COUNTER++;                                                  \
      TOTAL_FAILED_COUNTER_PER_FUNCTION++;                                     \
      fprintf(                                                                 \
          stdout,                                                              \
          "- \t\"%s\" %s:%d Error: expected size: %ld, got size: %ld.\n%s",    \
          TESTDESC, __FILE__, __LINE__, sizeof(expected), sizeof(actual),      \
          required ? "This test is required and must pass to continue.\n"      \
                   : "");                                                      \
      assert(required == false);                                               \
    } else {                                                                   \
      TOTAL_SUCCESSFUL_COUNTER++;                                              \
      TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION++;                                 \
      fprintf(stdout, "+ \t\"%s\" %s:%d Ok.\n", TESTDESC, __FILE__, __LINE__); \
    }                                                                          \
  } while (0)

/**
 * @brief Runs one single test.
 * @param func The test function to be executed.
 */
#define SINGLE_TEST(func)                                                      \
  do {                                                                         \
    (func)();                                                                  \
  } while (0)

/**
 * @brief Ignores one test with provided reason.
 * @param REASON Reason that we ignored the test.
 * @param func   Ignored test function.
 */
#define IGNORE_TEST(REASON, func)                                              \
  do {                                                                         \
    TOTAL_IGNORED_COUNTER++;                                                   \
    fprintf(stdout, "vvv %s\n\n", #func);                                      \
    fprintf(stdout, "* \t\"%s\" %s:%d Ignored.\n", REASON, __FILE__,           \
            __LINE__);                                                         \
    fprintf(stdout, "vvv\n");                                                  \
  } while (0)

/**
 * @brief Runs a group of provided test in order.
 * @param GROUPTESTNAME A human-readable name to identify the group of tests.
 * @param ... Test functions to be called.
 */
#define GROUP_TEST(GROUPTESTNAME, ...)                                         \
  do {                                                                         \
    void (*funcs[])(void) = {__VA_ARGS__};                                     \
    const char *fnames = #__VA_ARGS__;                                         \
    size_t count = sizeof(funcs) / sizeof(funcs[0]);                           \
    char fnamescp[strlen(fnames) + 1];                                         \
    strncpy(fnamescp, fnames, sizeof(fnamescp));                               \
    char *fname = strtok(fnamescp, ", ");                                      \
    for (size_t i = 0; i < count; ++i) {                                       \
      (funcs[i])();                                                            \
      fname = strtok(NULL, ", ");                                              \
    }                                                                          \
  } while (0)

/**
 * @brief Create test function with more information.
 * @param FUNCNAME Name of test function.
 * @param required Indicates whether test process should panic if this function
 * didn't passed.
 * @param ... Place a block of code that will run in the function.
 */
#define FUNCTION(FUNCNAME, ...)                                                \
  void FUNCNAME(void);                                                         \
  void FUNCNAME(void) {                                                        \
    TOTAL_TEST_COUNTER_PER_FUNCTION = 0;                                       \
    TOTAL_FAILED_COUNTER_PER_FUNCTION = 0;                                     \
    TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION = 0;                                 \
    fprintf(stdout, ">>> %s\n\n", #FUNCNAME);                                  \
    __VA_ARGS__;                                                               \
    fprintf(stdout, "\r\nTESTS: (%u) | SUCCESSFUL: (%u) | FAILED: (%u)\r\n",   \
            TOTAL_TEST_COUNTER_PER_FUNCTION,                                   \
            TOTAL_SUCCESSFUL_COUNTER_PER_FUNCTION,                             \
            TOTAL_FAILED_COUNTER_PER_FUNCTION);                                \
    fprintf(stdout, "<<<\n");                                                  \
  }

/**
 * @brief The main function builder.
 * @param ... Place a block of code that will run in the main function.
 */
#define MAIN(...)                                                              \
  int main(void) {                                                             \
    __VA_ARGS__;                                                               \
    fprintf(stdout,                                                            \
            "\r\nTOTAL TESTS: (%u) | TOTAL SUCCESSFUL TESTS: (%u) | TOTAL "    \
            "FAILED TESTS: (%u) | TOTAL "                                      \
            "IGNORED TESTS: (%u)\r\n",                                         \
            TOTAL_TEST_COUNTER, TOTAL_SUCCESSFUL_COUNTER,                      \
            TOTAL_FAILED_COUNTER, TOTAL_IGNORED_COUNTER);                      \
    return 0;                                                                  \
  }
