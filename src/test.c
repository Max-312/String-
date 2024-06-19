#include <check.h>

#include "s21_sprintf.h"
#include "s21_sscanf.h"
#include "s21_string.h"

Suite *suite_core(void);

#define TEST_MEMCPY_CASE(num, input, size)              \
  START_TEST(s21_memcpy_##num) {                        \
    char str1[50] = {0};                                \
    char str2[] = input;                                \
    s21_size_t num_bytes = size;                        \
    ck_assert_ptr_eq(s21_memcpy(str1, str2, num_bytes), \
                     memcpy(str1, str2, num_bytes));    \
  }                                                     \
  END_TEST

TEST_MEMCPY_CASE(1, "hello world", 5)
TEST_MEMCPY_CASE(2, "hello world", 11)
TEST_MEMCPY_CASE(3, "example", 7)
TEST_MEMCPY_CASE(4, "", 0)
TEST_MEMCPY_CASE(5, "data", 4)
TEST_MEMCPY_CASE(6, "test string", 6)
TEST_MEMCPY_CASE(7, "\nnew\nline", 8)
TEST_MEMCPY_CASE(8, "\tspecial", 9)
TEST_MEMCPY_CASE(9, "  leading spaces", 15)
TEST_MEMCPY_CASE(10, "trailing spaces  ", 16)
TEST_MEMCPY_CASE(11, "mixed 123 !@#", 12)
TEST_MEMCPY_CASE(12, "short", 5)
TEST_MEMCPY_CASE(13, "longer string with spaces", 20)
TEST_MEMCPY_CASE(14, "boundary test", 13)
TEST_MEMCPY_CASE(15, "final test case", 10)
TEST_MEMCPY_CASE(16, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26)
TEST_MEMCPY_CASE(17, "0123456789", 10)
TEST_MEMCPY_CASE(18, "!@#$%^&*()", 10)

#define TEST_MEMSET_CASE(num, src, symbol, size) \
  START_TEST(s21_memset_##num) {                 \
    char str[] = src;                            \
    int sym = symbol;                            \
    s21_size_t num_bytes = size;                 \
    s21_memset(str, sym, num_bytes);             \
    for (s21_size_t i = 0; i < num_bytes; i++) { \
      ck_assert_int_eq(str[i], sym);             \
    }                                            \
  }                                              \
  END_TEST

TEST_MEMSET_CASE(1, "hello world", 'x', 5)
TEST_MEMSET_CASE(2, "testing memset", 'z', 7)
TEST_MEMSET_CASE(3, "example", 'a', 3)
TEST_MEMSET_CASE(4, "school21", 'b', 6)
TEST_MEMSET_CASE(5, "function", 'c', 4)
TEST_MEMSET_CASE(6, "case study", 'd', 9)
TEST_MEMSET_CASE(7, "boundary", 'e', 8)
TEST_MEMSET_CASE(8, "test string", 'f', 11)
TEST_MEMSET_CASE(9, "abcdefghijklmnopqrstuvwxyz", 'y', 26)
TEST_MEMSET_CASE(10, "large data set", 'g', 4)
TEST_MEMSET_CASE(11, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 'm', 26)
TEST_MEMSET_CASE(12, "numeric 12345", 'n', 5)
TEST_MEMSET_CASE(13, "fill with zero", '\0', 10)

#define TEST_STRLEN_CASE(num, input)                \
  START_TEST(s21_strlen_##num) {                    \
    char str[] = input;                             \
    ck_assert_int_eq(s21_strlen(str), strlen(str)); \
  }                                                 \
  END_TEST

TEST_STRLEN_CASE(1, "")
TEST_STRLEN_CASE(2, " ")
TEST_STRLEN_CASE(3, "artanisi ")
TEST_STRLEN_CASE(4, "artanisi")
TEST_STRLEN_CASE(5, " \n")
TEST_STRLEN_CASE(6, "artanisi \n")
TEST_STRLEN_CASE(7, "\n ")
TEST_STRLEN_CASE(8, "\n\0")
TEST_STRLEN_CASE(9, "artanisi \n \0")
TEST_STRLEN_CASE(10, "artanisi \n\n")
TEST_STRLEN_CASE(11, "\n/////")
TEST_STRLEN_CASE(12, "artanisi \n\t artanisi")
TEST_STRLEN_CASE(13, "\t ")
TEST_STRLEN_CASE(14, "artanisi \n \0")
TEST_STRLEN_CASE(15, "\t\n")
TEST_STRLEN_CASE(16, " \n\t artanisi")
TEST_STRLEN_CASE(17, "artanisi \n ")
TEST_STRLEN_CASE(18, " \t")
TEST_STRLEN_CASE(19, " \n")
TEST_STRLEN_CASE(20, "\n\n\n\n\n")
TEST_STRLEN_CASE(21, " !@#$%^&*()-=+ ")
TEST_STRLEN_CASE(22, "artanisi")
TEST_STRLEN_CASE(23, "abcdefghijklmnopqrstuvwxyz")
TEST_STRLEN_CASE(24, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
TEST_STRLEN_CASE(25, "0123456789")
TEST_STRLEN_CASE(26, "!@#$%^&*()_+")
TEST_STRLEN_CASE(27, "          ")
TEST_STRLEN_CASE(28, "\t\t\t\t\t")
TEST_STRLEN_CASE(29,
                 "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY"
                 "Z!@#$%^&*()_+")
TEST_STRLEN_CASE(30, "\v\v\v\v\v")

#define TEST_STRNCPY_CASE(num, src, n, expected) \
  START_TEST(s21_strncpy_##num) {                \
    char str1[] = src;                           \
    char str2[100] = {0};                        \
    s21_strncpy(str2, str1, n);                  \
    ck_assert_str_eq(str2, expected);            \
  }                                              \
  END_TEST

TEST_STRNCPY_CASE(1, "hello world", 5, "hello")
TEST_STRNCPY_CASE(2, "hello world", 0, "")
TEST_STRNCPY_CASE(3, "hello", 5, "hello")
TEST_STRNCPY_CASE(4, "hello", 0, "")
TEST_STRNCPY_CASE(5, "hello there", 3, "hel")
TEST_STRNCPY_CASE(6, "hello there", 11, "hello there")
TEST_STRNCPY_CASE(7, "hello there", 12, "hello there")
TEST_STRNCPY_CASE(8, "example", 7, "example")
TEST_STRNCPY_CASE(9, "example", 1, "e")
TEST_STRNCPY_CASE(10, "test string", 11, "test string")
TEST_STRNCPY_CASE(11, "test string", 12, "test string")
TEST_STRNCPY_CASE(12, "test string", 4, "test")
TEST_STRNCPY_CASE(13, "another test", 7, "another")
TEST_STRNCPY_CASE(14, "copy this", 5, "copy ")
TEST_STRNCPY_CASE(15, "copy this", 9, "copy this")
TEST_STRNCPY_CASE(16, "short", 10, "short")
TEST_STRNCPY_CASE(17, "edge case", 9, "edge case")
TEST_STRNCPY_CASE(18, "boundary", 8, "boundary")
TEST_STRNCPY_CASE(19, "boundary", 4, "boun")
TEST_STRNCPY_CASE(20, "test", 4, "test")
TEST_STRNCPY_CASE(21, "test", 5, "test\0")
TEST_STRNCPY_CASE(22, "testing", 3, "tes")
TEST_STRNCPY_CASE(23, "", 5, "\0")
TEST_STRNCPY_CASE(24, "example", 7, "example")

#define TEST_TO_LOWER_CASE(num, input, expected) \
  START_TEST(s21_to_lower_##num) {               \
    const char str1[] = input;                   \
    char *tmp = s21_to_lower(str1);              \
    ck_assert_str_eq(tmp, expected);             \
    free(tmp);                                   \
  }                                              \
  END_TEST

TEST_TO_LOWER_CASE(1, "HELLO WORLD", "hello world")
TEST_TO_LOWER_CASE(2, "Hello World", "hello world")
TEST_TO_LOWER_CASE(3, "GOOD MORNING", "good morning")
TEST_TO_LOWER_CASE(4, "CProg:%123RAM!123ming", "cprog:%123ram!123ming")
TEST_TO_LOWER_CASE(5, "@TeStInG123!@", "@testing123!@")
TEST_TO_LOWER_CASE(6, "MIXEDcaseSTRING", "mixedcasestring")
TEST_TO_LOWER_CASE(7, "Num3r1cAndSp3c14l", "num3r1candsp3c14l")
TEST_TO_LOWER_CASE(8, "OnlyLowerCase", "onlylowercase")
TEST_TO_LOWER_CASE(9, "UPPERCASELETTERS", "uppercaseletters")
TEST_TO_LOWER_CASE(10, "12345ABCDEabcde", "12345abcdeabcde")
TEST_TO_LOWER_CASE(11, "EDGE_CASES: !@#$%^&*", "edge_cases: !@#$%^&*")
TEST_TO_LOWER_CASE(12, "MiXeD CasE WiTh 123", "mixed case with 123")
TEST_TO_LOWER_CASE(13, "Special_Characters_%$", "special_characters_%$")
TEST_TO_LOWER_CASE(14, "longStringWITHmixedCASE", "longstringwithmixedcase")
TEST_TO_LOWER_CASE(15, "1234567890", "1234567890")
TEST_TO_LOWER_CASE(16, "UPPER_AND_lower", "upper_and_lower")
TEST_TO_LOWER_CASE(17, "Test!@#123", "test!@#123")
TEST_TO_LOWER_CASE(18, "SimpleTestString", "simpleteststring")
TEST_TO_LOWER_CASE(19, "TEST_STRING_WITH_SPACES ", "test_string_with_spaces ")
TEST_TO_LOWER_CASE(20, "NoNumbersOrSymbols", "nonumbersorsymbols")

#define TEST_TO_UPPER_CASE(num, input, expected) \
  START_TEST(s21_to_upper_##num) {               \
    const char str1[] = input;                   \
    char *tmp = s21_to_upper(str1);              \
    ck_assert_str_eq(tmp, expected);             \
    free(tmp);                                   \
  }                                              \
  END_TEST

TEST_TO_UPPER_CASE(1, "hello", "HELLO")
TEST_TO_UPPER_CASE(2, "world!", "WORLD!")
TEST_TO_UPPER_CASE(3, "good morning", "GOOD MORNING")
TEST_TO_UPPER_CASE(4, "test123", "TEST123")
TEST_TO_UPPER_CASE(5, "example with spaces", "EXAMPLE WITH SPACES")
TEST_TO_UPPER_CASE(6, "hello world", "HELLO WORLD")
TEST_TO_UPPER_CASE(7, "12345", "12345")
TEST_TO_UPPER_CASE(8, "!@#$%^&*()", "!@#$%^&*()")
TEST_TO_UPPER_CASE(9, "Test Case 9", "TEST CASE 9")
TEST_TO_UPPER_CASE(10, "  mixedCase ", "  MIXEDCASE ")
TEST_TO_UPPER_CASE(11, "MIXED case", "MIXED CASE")
TEST_TO_UPPER_CASE(12, "\tnew\nline", "\tNEW\nLINE")
TEST_TO_UPPER_CASE(13, "123abcABC", "123ABCABC")
TEST_TO_UPPER_CASE(14, "abcdefghijklmnopqrstuvwxyz",
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
TEST_TO_UPPER_CASE(15, "additional test", "ADDITIONAL TEST")
TEST_TO_UPPER_CASE(16, "UpperCase", "UPPERCASE")
TEST_TO_UPPER_CASE(17, "lOwErCaSe", "LOWERCASE")
TEST_TO_UPPER_CASE(18, "Mix3dStr1ng", "MIX3DSTR1NG")
TEST_TO_UPPER_CASE(19, "SPACED OUT STRING", "SPACED OUT STRING")
TEST_TO_UPPER_CASE(20, "punctuation, included!", "PUNCTUATION, INCLUDED!")

#define TEST_MEMCMP_CASE(num, s1, s2, n)                                \
  START_TEST(s21_memcmp_##num) {                                        \
    char str1[] = s1;                                                   \
    char str2[] = s2;                                                   \
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n)); \
  }                                                                     \
  END_TEST

TEST_MEMCMP_CASE(1, "abcdef", "abcdef", 6)
TEST_MEMCMP_CASE(2, "abcdef", "abcdez", 6)
TEST_MEMCMP_CASE(3, "abcdef", "abcdez", 3)
TEST_MEMCMP_CASE(4, "", "", 0)
TEST_MEMCMP_CASE(5, "abc", "abcdef", 3)
TEST_MEMCMP_CASE(6, "abcdef", "ABCDEF", 6)
TEST_MEMCMP_CASE(7, "123456", "123456", 6)
TEST_MEMCMP_CASE(8, "123456", "654321", 3)
TEST_MEMCMP_CASE(9, "abcdef", "ghijkl", 0)
TEST_MEMCMP_CASE(10, "\0abcdef", "\0abcdef", 7)
TEST_MEMCMP_CASE(11, "hello", "world", 5)
TEST_MEMCMP_CASE(12, "test\0test", "test\0test", 9)
TEST_MEMCMP_CASE(13, "longer string test", "longer string test", 18)
TEST_MEMCMP_CASE(14, "case sensitive", "Case Sensitive", 14)
TEST_MEMCMP_CASE(15, "short", "shorter", 5)
TEST_MEMCMP_CASE(16, "identical", "identical", 9)
TEST_MEMCMP_CASE(17, "different\0strings", "different\0strings", 17)
TEST_MEMCMP_CASE(18, "numeric1234", "numeric1234", 11)
TEST_MEMCMP_CASE(19, "spaces in between", "spaces in between", 17)
TEST_MEMCMP_CASE(20, "special@#%&characters", "special@#%&characters", 21)

#define TEST_STRCHR_CASE(num, input, ch, expected) \
  START_TEST(s21_strchr_##num) {                   \
    const char *str = input;                       \
    char *res = s21_strchr(str, ch);               \
    if (expected == S21_NULL) {                    \
      ck_assert_ptr_eq(res, S21_NULL);             \
    } else {                                       \
      ck_assert_str_eq(res, expected);             \
    }                                              \
  }                                                \
  END_TEST

TEST_STRCHR_CASE(1, "hello", 'e', "ello")
TEST_STRCHR_CASE(2, "world", 'r', "rld")
TEST_STRCHR_CASE(3, "hello world", ' ', " world")
TEST_STRCHR_CASE(4, "hello", 'z', S21_NULL)
TEST_STRCHR_CASE(5, "hello", '\0', "")
TEST_STRCHR_CASE(6, "example", 'e', "example")
TEST_STRCHR_CASE(7, "test string", 's', "st string")
TEST_STRCHR_CASE(8, "abcdabcd", 'a', "abcdabcd")
TEST_STRCHR_CASE(9, "abcdabcd", 'b', "bcdabcd")
TEST_STRCHR_CASE(10, "abcdabcd", 'd', "dabcd")
TEST_STRCHR_CASE(11, "abcdabcd", 'e', S21_NULL)
TEST_STRCHR_CASE(12, "test\0hidden", '\0', "")
TEST_STRCHR_CASE(13, "\t\nspecial\n\t", '\n', "\nspecial\n\t")
TEST_STRCHR_CASE(14, "end of string\0hidden", '\0', "")

#define TEST_STRNCMP_CASE(num, s1, s2, n)                                 \
  START_TEST(s21_strncmp_##num) {                                         \
    char str1[] = s1;                                                     \
    char str2[] = s2;                                                     \
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n)); \
  }                                                                       \
  END_TEST

TEST_STRNCMP_CASE(1, "abcdef", "abcdef", 6)
TEST_STRNCMP_CASE(2, "abcdef", "abcdez", 6)
TEST_STRNCMP_CASE(3, "abcdef", "abcdez", 3)
TEST_STRNCMP_CASE(4, "", "", 0)
TEST_STRNCMP_CASE(5, "abc", "abcdef", 3)
TEST_STRNCMP_CASE(6, "abcdef", "ABCDEF", 6)
TEST_STRNCMP_CASE(7, "123456", "123456", 6)
TEST_STRNCMP_CASE(8, "123456", "654321", 3)
TEST_STRNCMP_CASE(9, "abcdef", "ghijkl", 0)
TEST_STRNCMP_CASE(10, "\0abcdef", "\0abcdef", 7)
TEST_STRNCMP_CASE(11, "test string", "test string", 11)
TEST_STRNCMP_CASE(12, "compare", "comparison", 7)
TEST_STRNCMP_CASE(13, "prefix", "prefixes", 6)
TEST_STRNCMP_CASE(14, "sensitive", "Sensitive", 9)
TEST_STRNCMP_CASE(15, "short", "shorter", 6)
TEST_STRNCMP_CASE(16, "identical", "identical", 9)
TEST_STRNCMP_CASE(17, "different\0test", "different\0test", 14)
TEST_STRNCMP_CASE(18, "numbers123", "numbers123", 10)
TEST_STRNCMP_CASE(19, "whitespace   ", "whitespace", 10)
TEST_STRNCMP_CASE(20, "special@#%&*", "special@#%&*", 12)

#define TEST_TRIM_CASE(num, input, trim_chars, expected) \
  START_TEST(s21_trim_##num) {                           \
    const char *src = input;                             \
    const char *trim = trim_chars;                       \
    char *res = s21_trim(src, trim);                     \
    if (expected == S21_NULL) {                          \
      ck_assert_ptr_eq(res, S21_NULL);                   \
    } else {                                             \
      ck_assert_str_eq(res, expected);                   \
      free(res);                                         \
    }                                                    \
  }                                                      \
  END_TEST

TEST_TRIM_CASE(1, "  hello  ", S21_NULL, "hello")
TEST_TRIM_CASE(2, "\t\ttrimmed\t\t", S21_NULL, "trimmed")
TEST_TRIM_CASE(3, "\nnew line\n", S21_NULL, "new line")
TEST_TRIM_CASE(4, "   mixed\t\n  ", S21_NULL, "mixed")
TEST_TRIM_CASE(5, "no trimming", S21_NULL, "no trimming")
TEST_TRIM_CASE(6, "", S21_NULL, "")
TEST_TRIM_CASE(7, "special@@@characters@@@", "@", "special@@@characters")
TEST_TRIM_CASE(8, "@@@start and end@@@", "@", "start and end")
TEST_TRIM_CASE(9, "abcdxyz", "abc", "dxyz")
TEST_TRIM_CASE(10, "test string", "t ", "est string")
TEST_TRIM_CASE(11, "   only spaces  ", " ", "only spaces")
TEST_TRIM_CASE(12, "!!!@@@special chars@@@!!!", "!@", "special chars")
TEST_TRIM_CASE(13, "##trimmed string##", "#", "trimmed string")
TEST_TRIM_CASE(14, "12345numbers54321", "12345", "numbers")

#define TEST_INSERT_CASE(num, str1, str2, pos, expected) \
  START_TEST(s21_insert_##num) {                         \
    char *s1 = str1;                                     \
    char *s2 = str2;                                     \
    char *res = s21_insert(s1, s2, pos);                 \
    if (expected == S21_NULL) {                          \
      ck_assert_ptr_eq(res, S21_NULL);                   \
    } else {                                             \
      ck_assert_str_eq(res, expected);                   \
      free(res);                                         \
    }                                                    \
  }                                                      \
  END_TEST

TEST_INSERT_CASE(1, "hello", "world", 5, "helloworld")
TEST_INSERT_CASE(2, "hello", "world", 0, "worldhello")
TEST_INSERT_CASE(3, "hello", "world", 6, S21_NULL)
TEST_INSERT_CASE(4, "hello", "world", 1, "hworldello")
TEST_INSERT_CASE(5, "hello", "world", 2, "heworldllo")
TEST_INSERT_CASE(6, "hello", "world", 3, "helworldlo")
TEST_INSERT_CASE(7, "hello", "", 5, "hello")
TEST_INSERT_CASE(8, "hello", S21_NULL, 5, S21_NULL)
TEST_INSERT_CASE(9, "large", "input", 0, "inputlarge")
TEST_INSERT_CASE(10, "test", "value", 3, "tesvaluet")
TEST_INSERT_CASE(11, "data", "structure", 4, "datastructure")
TEST_INSERT_CASE(12, "edge", "case", 0, "caseedge")
TEST_INSERT_CASE(13, "edge", "case", 4, "edgecase")
TEST_INSERT_CASE(14, "insert", "test", 6, "inserttest")
TEST_INSERT_CASE(15, "check", "assert", 3, "cheassertck")
TEST_INSERT_CASE(16, "begin", "start", 1, "bstartegin")
TEST_INSERT_CASE(17, "end", "finish", 2, "enfinishd")
TEST_INSERT_CASE(18, "boundary", "limit", 8, "boundarylimit")

START_TEST(s21_strerror_test) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(12), strerror(12));
  ck_assert_str_eq(s21_strerror(123), strerror(123));
  ck_assert_str_eq(s21_strerror(346563), strerror(346563));
  ck_assert_str_eq(s21_strerror(-326342), strerror(-326342));
}
END_TEST

START_TEST(strcspn_test) {
  char t_1[] = "12314241";
  char t_2[] = "fffff";
  char t_3[] = "//\0\n";
  char t_4[] = "goga";
  char t_5[] = "22222111111111";
  char t_6[] = "22222111111111";

  ck_assert_uint_eq(s21_strcspn(t_1, t_2), strcspn(t_1, t_2));
  ck_assert_uint_eq(s21_strcspn(t_2, t_3), strcspn(t_2, t_3));
  ck_assert_uint_eq(s21_strcspn(t_4, t_3), strcspn(t_4, t_3));
  ck_assert_uint_eq(s21_strcspn(t_5, t_4), strcspn(t_5, t_4));
  ck_assert_uint_eq(s21_strcspn(t_5, t_6), strcspn(t_5, t_6));
}
END_TEST

START_TEST(strpbrk_test) {
  char t_1[] = "01234ffffff";
  char t_2[] = "7773";
  char *str = "Hello, world";
  char *empty = "";

  ck_assert_str_eq(s21_strpbrk(t_1, t_2), "34ffffff");
  ck_assert_str_eq(s21_strpbrk(t_1, t_2), strpbrk(t_1, t_2));

  ck_assert_ptr_eq(s21_strpbrk(str, empty), S21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(strstr_test) {
  char t_1[] = "<<<5>>>";
  char t_2[] = "5";
  char t_3[] = "QwertyQwertyQwerty";
  char t_4[] = "Qwerty";
  char t_5[] = "abcd";
  char t_6[] = "";
  char t_7[] = "aaaaa123aaa1234aaa";
  char t_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(t_1, t_2), strstr(t_1, t_2));
  ck_assert_ptr_eq(s21_strstr(t_3, t_4), strstr(t_3, t_4));
  ck_assert_ptr_eq(s21_strstr(t_5, t_6), strstr(t_5, t_6));
  ck_assert_ptr_eq(s21_strstr(t_4, t_5), strstr(t_4, t_5));
  ck_assert_ptr_eq(s21_strstr(t_7, t_8), strstr(t_7, t_8));
}
END_TEST

START_TEST(strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char str_strtok2[] = "one/two/three(four)five";
  char str_strtok3[] = " ";
  char str_strtok4[] = " ";
  char str_strtok5[] = "GqwerGqwer";
  char str_strtok6[] = "GqwerGqwer";

  char delim1[] = "/()";
  char delim2[] = "/()";
  char delim3[] = " ";
  char delim4[] = "G";

  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);

  char *aish = s21_strtok(str_strtok3, delim3);
  char *orig_aish = strtok(str_strtok4, delim3);
  char *aish1 = s21_strtok(str_strtok5, delim4);
  char *orig_aish1 = strtok(str_strtok6, delim4);

  ck_assert_ptr_eq(aish, orig_aish);
  ck_assert_str_eq(aish1, orig_aish1);

  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim1);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

START_TEST(memchr_test) {
  char t_1[] = "1234567";
  char t_2[] = "\twqrwert";
  char t_3[] = "Hello!\n";
  char t_4[] = "DigitaWLLich";
  int t_5 = '3';
  int t_6 = '7';
  int t_7 = '\n';
  int t_8 = 'w';
  int t_9 = '0';

  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_5, 8),
                    (unsigned long)memchr(t_1, t_5, 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_2, t_6, 6),
                    (unsigned long)memchr(t_2, t_6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_3, t_7, 1),
                    (unsigned long)memchr(t_3, t_7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_4, t_8, 4),
                    (unsigned long)memchr(t_4, t_8, 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_9, 2),
                    (unsigned long)memchr(t_1, t_9, 2));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_2, t_5, 3),
                    (unsigned long)memchr(t_2, t_5, 3));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_3, t_6, 7),
                    (unsigned long)memchr(t_3, t_6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_4, t_7, 6),
                    (unsigned long)memchr(t_4, t_7, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_8, 8),
                    (unsigned long)memchr(t_1, t_8, 8));
}
END_TEST

START_TEST(strncat_test) {
  char t_1[4] = "<<<\0";
  char t_2[2] = "5\0";
  char t_3[2] = "5\0";
  char t_4[] = "\0";

  ck_assert_str_eq(s21_strncat(t_1, t_2, 1), "<<<5\0");
  ck_assert_str_eq(s21_strncat(t_3, t_4, 0), strncat(t_2, t_4, 0));
}
END_TEST

START_TEST(strrchr_test) {
  char t_1[] = "0163456769";
  char t_2[] = ";;;;;;H%%//#HH";
  char t_3[] = " /";

  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, '6'),
                    (unsigned long)strrchr(t_1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, ' '),
                    (unsigned long)strrchr(t_1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, '6'),
                    (unsigned long)strrchr(t_1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, 'H'),
                    (unsigned long)strrchr(t_2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, '$'),
                    (unsigned long)strrchr(t_2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, ';'),
                    (unsigned long)strrchr(t_2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_3, ' '),
                    (unsigned long)strrchr(t_3, ' '));
  ck_assert_str_eq(s21_strrchr(t_2, '\0'), strrchr(t_2, '\0'));
}
END_TEST

START_TEST(sprintf_d_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  int d = 228;

  int res_1 = s21_sprintf(str, "%10.5d", d);
  int res_1_orig = sprintf(str_orig, "%10.5d", d);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", d);
  int res_2_orig = sprintf(str_orig, "% 10.5d", d);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", d);
  int res_3_orig = sprintf(str_orig, "%3.5d", d);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", d);
  int res_4_orig = sprintf(str_orig, "%d", d);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", d);
  int res_5_orig = sprintf(str_orig, "%0d", d);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", d);
  int res_6_orig = sprintf(str_orig, "%-d", d);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", d);
  int res_7_orig = sprintf(str_orig, "%+d", d);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", d);
  int res_8_orig = sprintf(str_orig, "% d", d);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", d);
  int res_9_orig = sprintf(str_orig, "%5d", d);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%-5d", d);
  int res_10_orig = sprintf(str_orig, "%-5d", d);
  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%+5d", d);
  int res_11_orig = sprintf(str_orig, "%+5d", d);
  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "% 5d", d);
  int res_12_orig = sprintf(str_orig, "% 5d", d);
  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%.5d", d);
  int res_13_orig = sprintf(str_orig, "%.5d", d);
  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_c_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  char A = 'A';

  int res_1 = s21_sprintf(str, "%c", A);
  int res_1_orig = sprintf(str_orig, "%c", A);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%-c", A);
  int res_2_orig = sprintf(str_orig, "%-c", A);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%10c", A);
  int res_3_orig = sprintf(str_orig, "%10c", A);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%-2c", A);
  int res_4_orig = sprintf(str_orig, "%-2c", A);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_s_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  char *A = "Ochko";

  int res_1 = s21_sprintf(str, "%s", A);
  int res_1_orig = sprintf(str_orig, "%s", A);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%-s", A);
  int res_2_orig = sprintf(str_orig, "%-s", A);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%10s", A);
  int res_3_orig = sprintf(str_orig, "%10s", A);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%.5s", A);
  int res_4_orig = sprintf(str_orig, "%.5s", A);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-10s", A);
  int res_5_orig = sprintf(str_orig, "%-10s", A);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_ld_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  long int d = 1504389565748;

  int res_1 = s21_sprintf(str, "%10.5ld", d);
  int res_1_orig = sprintf(str_orig, "%10.5ld", d);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5ld", d);
  int res_2_orig = sprintf(str_orig, "% 10.5ld", d);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5ld", d);
  int res_3_orig = sprintf(str_orig, "%3.5ld", d);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%ld", d);
  int res_4_orig = sprintf(str_orig, "%ld", d);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-ld", d);
  int res_5_orig = sprintf(str_orig, "%-ld", d);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%+ld", d);
  int res_6_orig = sprintf(str_orig, "%+ld", d);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "% ld", d);
  int res_7_orig = sprintf(str_orig, "% ld", d);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%5ld", d);
  int res_8_orig = sprintf(str_orig, "%5ld", d);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5ld", d);
  int res_9_orig = sprintf(str_orig, "%-5ld", d);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%+5ld", d);
  int res_10_orig = sprintf(str_orig, "%+5ld", d);
  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "% 5ld", d);
  int res_11_orig = sprintf(str_orig, "% 5ld", d);
  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%.5ld", d);
  int res_12_orig = sprintf(str_orig, "%.5ld", d);
  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_u_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  unsigned int u = 228;

  int res_1 = s21_sprintf(str, "%10.5u", u);
  int res_1_orig = sprintf(str_orig, "%10.5u", u);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%-10.5u", u);
  int res_2_orig = sprintf(str_orig, "%-10.5u", u);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", u);
  int res_3_orig = sprintf(str_orig, "%3.5u", u);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%u", u);
  int res_4_orig = sprintf(str_orig, "%u", u);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%u", u);
  int res_5_orig = sprintf(str_orig, "%u", u);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%5u", u);
  int res_6_orig = sprintf(str_orig, "%5u", u);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%-5u", u);
  int res_7_orig = sprintf(str_orig, "%-5u", u);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%10.5u", u);
  int res_8_orig = sprintf(str_orig, "%10.5u", u);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%.5u", u);
  int res_9_orig = sprintf(str_orig, "%.5u", u);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_ULTIMA_test) {
  char str[200] = {'\0'};
  char str_orig[200] = {'\0'};
  char s[] = "chfbjkds\0";
  char s2[] = "qwerty\0";
  short int d = 19555;
  long int d2 = 1504389565748;
  int d3 = -190;
  unsigned short int us = 10443;
  unsigned long int ul = 5665465454;
  char c = 'A';
  float f = 1.0004;
  float f2 = -228;
  float f3 = 1.0;
  const char format[10000] =
      "1234 x %+-5.3hd x %+-20.15ld x % 10.6d x %-5s x %-10.3s x %-5.7hu x "
      "%-10.2lu x %-5c x %c x % -5.2f x %10.5f x %.f x %10f";
  int res_1 =
      s21_sprintf(str, format, d, d2, d3, s, s2, us, ul, c, c, f, f2, f3, f3);
  int res_1_orig =
      sprintf(str_orig, format, d, d2, d3, s, s2, us, ul, c, c, f, f2, f3, f3);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_proc) {
  char buf1[100];
  char buf2[100];
  sprintf(buf1, "%%");
  s21_sprintf(buf2, "%%");
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_simple) {
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf8[100];
  char buf9[100];
  char buf10[100];
  char buf11[100];

  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  char buf8_[100];
  char buf9_[100];
  char buf10_[100];
  char buf11_[100];

  sprintf(buf2, "%g", 0.000000001);
  s21_sprintf(buf2_, "%g", 0.000000001);
  sprintf(buf3, "%G", 0.000000001);
  s21_sprintf(buf3_, "%G", 0.000000001);
  sprintf(buf4, "%e", 123456789.123456789);
  s21_sprintf(buf4_, "%e", 123456789.123456789);
  sprintf(buf5, "%E", 123456789.123456789);
  s21_sprintf(buf5_, "%E", 123456789.123456789);
  sprintf(buf6, "%x", 0xabcdef);
  s21_sprintf(buf6_, "%x", 0xabcdef);
  sprintf(buf7, "%X", 0xABCDEF);
  s21_sprintf(buf7_, "%X", 0xABCDEF);
  sprintf(buf8, "%x", 0xABCDEF);
  s21_sprintf(buf8_, "%x", 0xABCDEF);
  sprintf(buf9, "%X", 0xabcdef);
  s21_sprintf(buf9_, "%X", 0xabcdef);
  sprintf(buf10, "%o", 20);
  s21_sprintf(buf10_, "%o", 20);

  double number = 123456789.123456789;
  void *ptr = &number;
  sprintf(buf11, "%p", ptr);
  s21_sprintf(buf11_, "%p", ptr);

  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
  ck_assert_str_eq(buf8, buf8_);
  ck_assert_str_eq(buf9, buf9_);
  ck_assert_str_eq(buf10, buf10_);
  ck_assert_str_eq(buf11, buf11_);
}
END_TEST

START_TEST(test_complex_e) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  sprintf(buf1, "%*.e", 10, 123456789.123456789);
  s21_sprintf(buf1_, "%*.e", 10, 123456789.123456789);
  sprintf(buf2, "%.*e", 5, 123456789.123456789);
  s21_sprintf(buf2_, "%.*e", 5, 123456789.123456789);
  sprintf(buf3, "%*.*e", 10, 5, 123456789.123456789);
  s21_sprintf(buf3_, "%*.*e", 10, 5, 123456789.123456789);
  sprintf(buf4, "%020e", 123456789.123456789);
  s21_sprintf(buf4_, "%020e", 123456789.123456789);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
}
END_TEST

START_TEST(test_complex_E) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  sprintf(buf1, "%*.E", 10, 123456789.123456789);
  s21_sprintf(buf1_, "%*.E", 10, 123456789.123456789);
  sprintf(buf2, "%.*E", 5, 123456789.123456789);
  s21_sprintf(buf2_, "%.*E", 5, 123456789.123456789);
  sprintf(buf3, "%*.*E", 10, 5, 123456789.123456789);
  s21_sprintf(buf3_, "%*.*E", 10, 5, 123456789.123456789);
  sprintf(buf4, "%020E", 123456789.123456789);
  s21_sprintf(buf4_, "%020E", 123456789.123456789);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
}
END_TEST

START_TEST(test_complex_x) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  sprintf(buf1, "%*.x", 10, 0xabcdef);
  s21_sprintf(buf1_, "%*.x", 10, 0xabcdef);
  sprintf(buf2, "%.*x", 5, 0xabcdef);
  s21_sprintf(buf2_, "%.*x", 5, 0xabcdef);
  sprintf(buf3, "%*.*x", 10, 5, 0xabcdef);
  s21_sprintf(buf3_, "%*.*x", 10, 5, 0xabcdef);
  sprintf(buf4, "%020x", 0xabcdef);
  s21_sprintf(buf4_, "%020x", 0xabcdef);
  sprintf(buf5, "%#x", 0xabcdef);
  s21_sprintf(buf5_, "%#x", 0xabcdef);
  sprintf(buf6, "%#x", 0XABCDEF);
  s21_sprintf(buf6_, "%#x", 0XABCDEF);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
}
END_TEST

START_TEST(test_complex_X) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  sprintf(buf1, "%*.X", 10, 0XABCDEF);
  s21_sprintf(buf1_, "%*.X", 10, 0XABCDEF);
  sprintf(buf2, "%.*X", 5, 0XABCDEF);
  s21_sprintf(buf2_, "%.*X", 5, 0XABCDEF);
  sprintf(buf3, "%*.*X", 10, 5, 0XABCDEF);
  s21_sprintf(buf3_, "%*.*X", 10, 5, 0XABCDEF);
  sprintf(buf4, "%020X", 0XABCDEF);
  s21_sprintf(buf4_, "%020X", 0XABCDEF);
  sprintf(buf5, "%#X", 0XABCDEF);
  s21_sprintf(buf5_, "%#X", 0XABCDEF);
  sprintf(buf6, "%#X", 0xabcdef);
  s21_sprintf(buf6_, "%#X", 0xabcdef);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
}
END_TEST

START_TEST(test_complex_o) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  sprintf(buf1, "%*.o", 10, 20);
  s21_sprintf(buf1_, "%*.o", 10, 20);
  sprintf(buf2, "%.*o", 5, 20);
  s21_sprintf(buf2_, "%.*o", 5, 20);
  sprintf(buf3, "%*.*o", 10, 5, 20);
  s21_sprintf(buf3_, "%*.*o", 10, 5, 20);
  sprintf(buf4, "%020o", 20);
  s21_sprintf(buf4_, "%020o", 20);
  sprintf(buf5, "%#o", 20);
  s21_sprintf(buf5_, "%#o", 20);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
}
END_TEST

START_TEST(test_anomal_large_int) {
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%ld", 1234567890000001);
  s21_sprintf(buf1_, "%ld", 1234567890000001);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

START_TEST(test_precision) {
  double number = 127.9991;
  char buf1[100];
  char buf2[100];

  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf1_[100];
  char buf2_[100];

  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  sprintf(buf1, "%.*f", 3, number);
  s21_sprintf(buf1_, "%.*f", 3, number);
  sprintf(buf2, "%.*g", 3, number);
  s21_sprintf(buf2_, "%.*g", 3, number);
  sprintf(buf4, "%.*f", 0, number);
  s21_sprintf(buf4_, "%.*f", 0, number);

  number = 127.1991;
  sprintf(buf5, "%.*f", 0, number);
  s21_sprintf(buf5_, "%.*f", 0, number);
  sprintf(buf6, "%.*e", 3, number);
  s21_sprintf(buf6_, "%.*e", 3, number);
  sprintf(buf7, "%.*e", 0, number);
  s21_sprintf(buf7_, "%.*e", 0, number);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);

  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
}
END_TEST

START_TEST(test_large_int) {
  long int number = 1234567890000000001LL;
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%ld", number);
  s21_sprintf(buf1_, "%ld", number);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

START_TEST(test_hash_e) {
  double number = 0.8;
  char buf1[100];
  char buf1_[100];
  char buf2[100];
  char buf2_[100];
  sprintf(buf1, "%#e", number);
  s21_sprintf(buf1_, "%#e", number);
  sprintf(buf2, "%#e", 0.0);
  s21_sprintf(buf2_, "%#e", 0.0);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_zero_padding) {
  double number = 0.8;
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf8[100];
  char buf9[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  char buf8_[100];
  char buf9_[100];
  sprintf(buf1, "%08e", number);
  s21_sprintf(buf1_, "%08e", number);
  sprintf(buf2, "%08f", number);
  s21_sprintf(buf2_, "%08f", number);
  sprintf(buf3, "%08f", 9.1);
  s21_sprintf(buf3_, "%08f", 9.1);
  sprintf(buf4, "%08g", number);
  s21_sprintf(buf4_, "%08g", number);
  sprintf(buf5, "%023g", number);
  s21_sprintf(buf5_, "%023g", number);
  sprintf(buf6, "%08G", number);
  s21_sprintf(buf6_, "%08G", number);
  sprintf(buf7, "%023G", number);
  s21_sprintf(buf7_, "%023G", number);
  sprintf(buf8, "%08d", 10);
  s21_sprintf(buf8_, "%08d", 10);
  sprintf(buf9, "%023d", 10);
  s21_sprintf(buf9_, "%023d", 10);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
  ck_assert_str_eq(buf8, buf8_);
  ck_assert_str_eq(buf9, buf9_);
}
END_TEST

START_TEST(test_mixed_ld) {
  long int number = 1234567890000000001LL;
  char buf1[100];
  char buf2[100];
  char buf1_[100];
  char buf2_[100];
  sprintf(buf1, "%*.*ld", 5, 8, number);
  s21_sprintf(buf1_, "%*.*ld", 5, 8, number);
  sprintf(buf2, "%*.*ld", 5, 10, number);
  s21_sprintf(buf2_, "%*.*ld", 5, 10, number);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_mixed_f) {
  double num = 12000.9;
  char buf1[100];
  char buf2[100];
  char buf1_[100];
  char buf2_[100];
  sprintf(buf1, "%0#*.*f", 10, 1, num);
  s21_sprintf(buf1_, "%0#*.*f", 10, 1, num);
  sprintf(buf2, "%0#*.*f", 10, 14, num);
  s21_sprintf(buf2_, "%0#*.*f", 10, 14, num);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_mixed_e) {
  double num = 12000.9;
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%0#*.*e", 10, 14, num);
  s21_sprintf(buf1_, "%0#*.*e", 10, 14, num);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

START_TEST(test_wide_string_specifier) {
  char buffer[100];
  wchar_t wstr[] = L"Hello, World!";

  int result = s21_sprintf(buffer, "%ls", wstr);

  ck_assert_int_gt(result, 0);
  ck_assert_str_eq(buffer, "Hello, World!");
}
END_TEST

START_TEST(sscanf_1) {
  ////некорректный ввод
  const char *input = "015 015 ";
  const char *format = "015%d55%d";
  int original_num1 = 0;
  int original_num2 = 0;
  int s21_num1 = 0;
  int s21_num2 = 0;
  int c1 = sscanf(input, format, &original_num1, &original_num2);
  int c2 = s21_sscanf(input, format, &s21_num1, &s21_num2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_2) {
  ////некорректный ввод
  const char *input = "015 015 ";
  const char *format = "%dk";
  int original_num1 = 0;
  int s21_num1 = 0;
  int c1 = sscanf(input, format, &original_num1);
  int c2 = s21_sscanf(input, format, &s21_num1);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_3) {
  //// нестандартный ввод числа
  const char *input = "-00000015 ";
  const char *format = "%d";
  int original_num1 = 0;
  int s21_num1 = 0;
  int c1 = sscanf(input, format, &original_num1);
  int c2 = s21_sscanf(input, format, &s21_num1);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(original_num1, s21_num1);
}
END_TEST

START_TEST(sscanf_4) {
  ////некорректный ввод ширины ==0
  const char *input = "9823372036854775807";
  const char *format = "%0lli";
  long long original_num = 0, s21_num = 0;

  int c1 = sscanf(input, format, &original_num);
  int c2 = s21_sscanf(input, format, &s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_5) {
  ////некорректный ввод ширины negative
  const char *input = "9823372036854775807";
  const char *format = "%-2lli";
  long long original_num = 0;
  long long s21_num = 0;

  int c1 = sscanf(input, format, &original_num);
  int c2 = sscanf(input, format, &s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_6) {
  ////некорректный ввод ширины negative
  const char *input = "9823372036854775807";
  const char *format = "%-2lli";
  long long original_num = 0;
  long long s21_num = 0;
  int c1 = sscanf(input, format, &original_num);
  int c2 = sscanf(input, format, &s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_7) {
  ////ширина превышает строку
  const char *input = "97";
  const char *format = "%90lli";
  long long original_num = 0;
  long long s21_num = 0;

  int c1 = sscanf(input, format, &original_num);
  int c2 = s21_sscanf(input, format, &s21_num);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(original_num, s21_num);
}
END_TEST

START_TEST(sscanf_8) {
  //%n with first symbol \0
  const char *input = "\010ef";
  const char *format = "%d";
  int original_num = 0;
  int s21_num = 0;
  int c2 = sscanf(input, format, &s21_num);
  int c1 = s21_sscanf(input, format, &original_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_9) {
  //%n
  const char *input = "10ef";
  const char *format = "%d%nef";
  int original_num1 = 0, original_num2 = 0;
  int s21_num1 = 0, s21_num2 = 0;
  int c1 = s21_sscanf(input, format, &s21_num1, &s21_num2);
  int c2 = sscanf(input, format, &original_num1, &original_num2);
  ck_assert_int_eq(original_num1, s21_num1);
  ck_assert_int_eq(original_num2, s21_num2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_11) {
  // standard %n
  const char *str = "0134 -78 abcd";
  const char *format = "%d%d%n";
  int orig_num1 = 0;
  int orig_num2 = 0;
  int s21_num1 = 0;
  int s21_num2 = 0;
  int orig_chars_read = 0;
  int s21_chars_read = 0;
  int c1 = sscanf(str, format, &orig_num1, &orig_num2, &orig_chars_read);
  int c2 = s21_sscanf(str, format, &s21_num1, &s21_num2, &s21_chars_read);
  ck_assert_int_eq(orig_num1, s21_num1);
  ck_assert_int_eq(orig_num2, s21_num2);
  ck_assert_int_eq(orig_chars_read, s21_chars_read);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_12) {
  // special point format==str
  const char *input = "1234 nsd5678";
  const char *format = "%d %d";
  int original_num1 = 0;
  int original_num2 = 0;
  int s21_num1 = 0;
  int s21_num2 = 0;
  int c1 = sscanf(input, format, &s21_num1, &s21_num2);
  int c2 = s21_sscanf(input, format, &original_num1, &original_num2);
  ck_assert_int_eq(original_num1, s21_num1);
  ck_assert_int_eq(original_num2, s21_num2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_13) {
  // doubled %n
  char *str = "100 10";
  char *format = "%d%n%d%n";
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int num4 = 0;
  int s21_num1 = 0;
  int s21_num2 = 0;
  int s21_num3 = 0;
  int s21_num4 = 0;
  int c1 = sscanf(str, format, &num1, &num2, &num3, &num4);
  int c2 = s21_sscanf(str, format, &s21_num1, &s21_num2, &s21_num3, &s21_num4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, s21_num1);
  ck_assert_int_eq(num2, s21_num2);
  ck_assert_int_eq(num3, s21_num3);
  ck_assert_int_eq(num4, s21_num4);
}
END_TEST

START_TEST(sscanf_14) {
  // repeat
  char *str = "-03243 -23";
  int orig_num1 = -1;
  int s21_num1 = -1;
  int c1 = sscanf(str, "%*i %i", &orig_num1);
  int c2 = s21_sscanf(str, "%*i %i", &s21_num1);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(orig_num1, s21_num1);
}
END_TEST

START_TEST(sscanf_15) {
  const char *str = "hello world";
  char *format = "%s %s";
  char orig_str1[50] = {'\0'};
  char orig_str2[50] = {'\0'};
  char s21_str1[50] = {'\0'};
  char s21_str2[50] = {'\0'};
  int c1 = sscanf(str, format, orig_str1, orig_str2);
  int c2 = s21_sscanf(str, format, s21_str1, s21_str2);
  ck_assert_int_eq(c1, c2);
  ck_assert_str_eq(orig_str1, s21_str1);
  ck_assert_str_eq(orig_str2, s21_str2);
}
END_TEST

START_TEST(sscanf_16) {
  const char *str = "hello world";
  char *format = "%s %s";
  char orig_str1[50] = {'\0'};
  char orig_str2[50] = {'\0'};
  char s21_str1[50] = {'\0'};
  char s21_str2[50] = {'\0'};
  int c1 = sscanf(str, format, orig_str1, orig_str2);
  int c2 = s21_sscanf(str, format, s21_str1, s21_str2);
  ck_assert_int_eq(c1, c2);
  ck_assert_str_eq(orig_str1, s21_str1);
  ck_assert_str_eq(orig_str2, s21_str2);
}
END_TEST

START_TEST(sscanf_17) {
  const char *str = "hello world";
  char *format = "%s%s";
  char orig_str1[50] = {'\0'};
  char orig_str2[50] = {'\0'};
  char s21_str1[50] = {'\0'};
  char s21_str2[50] = {'\0'};
  int c1 = sscanf(str, format, orig_str1, orig_str2);
  int c2 = s21_sscanf(str, format, s21_str1, s21_str2);
  ck_assert_int_eq(c1, c2);
  ck_assert_str_eq(orig_str1, s21_str1);
  ck_assert_str_eq(orig_str2, s21_str2);
}
END_TEST

START_TEST(sscanf_18) {
  const char *str = "FD FFFFFFFF hello";
  unsigned long num, s21_num;
  char *format = "%*lx %lx";
  int c1 = sscanf(str, format, &num);
  int c2 = s21_sscanf(str, format, &s21_num);
  ck_assert_int_eq(num, s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_19) {
  const char *str = "FD FFFFFFFF hello";
  unsigned long num, s21_num;
  char *format = "%lx %*lx";
  int c1 = sscanf(str, format, &num);
  int c2 = s21_sscanf(str, format, &s21_num);
  ck_assert_int_eq(num, s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_20) {
  // strange behavior with (width + *); better toremove
  const char *str = "FD FFFFFFFF hello";
  unsigned long num, s21_num;
  char *format = "%*1lx %lx";
  int c1 = sscanf(str, format, &num);
  int c2 = sscanf(str, format, &s21_num);
  ck_assert_int_eq(num, s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_21) {
  const char *str = "+12.34 --56.78";
  char *format = "%*f %f";
  float orig_num = 0, s21_num = 0;

  int c1 = sscanf(str, format, &orig_num);
  int c2 = sscanf(str, format, &s21_num);
  ck_assert_float_eq(orig_num, s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_22) {
  // dont remember existing of this test (feature is in sign+length); they are
  // test 122
  const char *str = "+12.34 -56.78";
  char *format = "%2f %2f ";
  float orig_num1, s21_num1, orig_num2, s21_num2;
  ;
  int c1 = sscanf(str, format, &orig_num1, &orig_num2);
  int c2 = s21_sscanf(str, format, &s21_num1, &s21_num2);
  ck_assert_int_eq(orig_num1, s21_num1);
  ck_assert_int_eq(orig_num2, s21_num2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_23) {
  // normal test for ho, hx and etc + minusexcept hi
  const char *str = "-7FFF";
  int c1, c2;
  unsigned short orig_num, s21_num;
  c1 = sscanf(str, "%hx", &orig_num);
  c2 = s21_sscanf(str, "%hx", &s21_num);
  ck_assert_int_eq(orig_num, s21_num);
  ck_assert_int_eq(c1, c2);
  const char *str2 = "-789";
  short int orig2_num, s212_num;
  c1 = sscanf(str2, "%hd", &orig2_num);
  c2 = s21_sscanf(str2, "%hd", &s212_num);
  ck_assert_int_eq(orig2_num, s212_num);
  ck_assert_int_eq(c1, c2);
  const char *str3 = "-567";
  c1 = sscanf(str3, "%ho", &orig_num);
  c2 = s21_sscanf(str3, "%ho", &s21_num);
  ck_assert_int_eq(orig_num, s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_24) {
  // wrong str for %hd ho hx //
  const char *str = "not_a_number";
  unsigned short num, s21_num;
  short int num2, s21_num2;
  int c1, c2;

  c1 = sscanf(str, "%hd", &num2);
  c2 = s21_sscanf(str, "%hd", &s21_num2);
  ck_assert_int_eq(c1, c2);
  c1 = sscanf(str, "%ho", &num);
  c2 = s21_sscanf(str, "%ho", &s21_num);
  ck_assert_int_eq(c1, c2);
  c1 = sscanf(str, "%hx", &num);
  c2 = s21_sscanf(str, "%hx", &s21_num);
  ck_assert_int_eq(c1, c2);
  c1 = sscanf(str, "%hi", &num2);
  c2 = s21_sscanf(str, "%hi", &s21_num2);
  ck_assert_int_eq(c1, c2);
  const char *str1 = "GHIJ";
  c1 = sscanf(str1, "%hx", &num);
  c2 = s21_sscanf(str1, "%hx", &s21_num);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_25) {
  const char *str = "0xFF * 56 1234567890";
  int num, s21_num;
  unsigned int hex_num, s21_hex_num;
  char ch, s21_ch;
  int chars_read, s21_chars_read;
  unsigned long long_num, s21_long_num;

  int c1 = sscanf(str, "%x %c %d %n %lx", &hex_num, &ch, &num, &chars_read,
                  &long_num);
  int c2 = s21_sscanf(str, "%x %c %d %n %lx", &s21_hex_num, &s21_ch, &s21_num,
                      &s21_chars_read, &s21_long_num);
  ck_assert_uint_eq(hex_num, s21_hex_num);
  ck_assert_int_eq(num, s21_num);
  ck_assert_int_eq(chars_read, s21_chars_read);
  ck_assert_uint_eq(long_num, s21_long_num);
  ck_assert_int_eq(s21_ch, ch);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_26) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int c3 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int cc3 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c3, cc3);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_27) {
  char fstr[] = "%*2c%c%c";
  char str[] = "\\\n\t\t";
  char a1 = 0, a2 = 0, b1 = 0, b2 = 0;

  int c1 = sscanf(str, fstr, &a1, &b1);
  int c2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_28) {
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
  int s21_num1 = 0, s21_num2 = 0, s21_num3 = 0, s21_num4 = 0;
  const char str[] = "12345.99";
  const char fstr[] = "%1i %1i %1i %i";

  int c1 = sscanf(str, fstr, &num1, &num2, &num3, &num4);
  int c2 = s21_sscanf(str, fstr, &s21_num1, &s21_num2, &s21_num3, &s21_num4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, s21_num1);
  ck_assert_int_eq(num2, s21_num2);
  ck_assert_int_eq(num3, s21_num3);
  ck_assert_int_eq(num4, s21_num4);
}
END_TEST

START_TEST(sscanf_29) {
  void *a1 = S21_NULL, *a2 = S21_NULL;
  const char str[] = "0xFFFF";
  const char fstr[] = "%p";

  int c1 = s21_sscanf(str, fstr, &a1);
  int c2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(c1, c2);
  ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_30) {
  const char str[] = "0xFFFF";
  const char fstr[] = "%*p%n";
  int chars_read, s21_chars_read;

  int c1 = sscanf(str, fstr, &chars_read);
  int c2 = sscanf(str, fstr, &s21_chars_read);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(s21_chars_read, chars_read);
}
END_TEST

START_TEST(sscanf_32) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] =
      "NAN           INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";
  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_33) {
  char str1[1000];
  char str2[1000];

  char *format = "This is a simple wide char %lc";
  unsigned long w = L'2';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_34) {
  int value;
  int res = s21_sscanf("42", "%d", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 42);
}
END_TEST

START_TEST(sscanf_35) {
  float value;
  int res = s21_sscanf("3.14", "%f", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_float_eq_tol(value, 3.14, 0.0001);
}
END_TEST

START_TEST(sscanf_36) {
  char value[100];
  int res = s21_sscanf("hello", "%s", value);
  ck_assert_int_eq(res, 1);
  ck_assert_str_eq(value, "hello");
}
END_TEST

START_TEST(sscanf_37) {
  char value;
  int res = s21_sscanf("a", "%c", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 'a');
}
END_TEST

START_TEST(sscanf_38) {
  int value;
  int res = s21_sscanf("0x1A", "%x", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 0x1A);
}
END_TEST

START_TEST(sscanf_39) {
  int i;
  float f;
  char s[100];
  int res = s21_sscanf("123 4.56 test", "%d %f %s", &i, &f, s);
  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(i, 123);
  ck_assert_float_eq_tol(f, 4.56, 0.0001);
  ck_assert_str_eq(s, "test");
}
END_TEST

START_TEST(sscanf_40) {
  int value;
  int res = s21_sscanf("    42", "%d", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 42);
}
END_TEST

START_TEST(sscanf_41) {
  int value;
  int res = s21_sscanf("abc", "%d", &value);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(sscanf_42) {
  int value;
  int res = s21_sscanf("012", "%o", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 10);
}
END_TEST

START_TEST(sscanf_43) {
  int value;
  int res = s21_sscanf("100%", "%d%%", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 100);
}
END_TEST

START_TEST(sscanf_44) {
  void *ptr;
  int res = s21_sscanf("0x123456", "%p", &ptr);
  ck_assert_int_eq(res, 1);
  ck_assert_ptr_eq(ptr, (void *)0x123456);
}
END_TEST

START_TEST(sscanf_45) {
  long value;
  int res = s21_sscanf("1234567890", "%ld", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(value, 1234567890);
}
END_TEST

START_TEST(sscanf_46) {
  double value;
  int res = s21_sscanf("123.456", "%lf", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_double_eq_tol(value, 123.456, 0.0001);
}
END_TEST

START_TEST(sscanf_47) {
  long double value;
  int res = s21_sscanf("123.456789", "%Lf", &value);
  ck_assert_int_eq(res, 1);
  ck_assert_ldouble_eq_tol(value, 123.456789, 0.0001);
}
END_TEST

Suite *suite_core() {
  Suite *s = suite_create("Core");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memcpy_1);
  tcase_add_test(tc_core, s21_memcpy_2);
  tcase_add_test(tc_core, s21_memcpy_3);
  tcase_add_test(tc_core, s21_memcpy_4);
  tcase_add_test(tc_core, s21_memcpy_5);
  tcase_add_test(tc_core, s21_memcpy_6);
  tcase_add_test(tc_core, s21_memcpy_7);
  tcase_add_test(tc_core, s21_memcpy_8);
  tcase_add_test(tc_core, s21_memcpy_9);
  tcase_add_test(tc_core, s21_memcpy_10);
  tcase_add_test(tc_core, s21_memcpy_11);
  tcase_add_test(tc_core, s21_memcpy_12);
  tcase_add_test(tc_core, s21_memcpy_13);
  tcase_add_test(tc_core, s21_memcpy_14);
  tcase_add_test(tc_core, s21_memcpy_15);
  tcase_add_test(tc_core, s21_memcpy_16);
  tcase_add_test(tc_core, s21_memcpy_17);
  tcase_add_test(tc_core, s21_memcpy_18);

  tcase_add_test(tc_core, s21_memset_1);
  tcase_add_test(tc_core, s21_memset_2);
  tcase_add_test(tc_core, s21_memset_3);
  tcase_add_test(tc_core, s21_memset_4);
  tcase_add_test(tc_core, s21_memset_5);
  tcase_add_test(tc_core, s21_memset_6);
  tcase_add_test(tc_core, s21_memset_7);
  tcase_add_test(tc_core, s21_memset_8);
  tcase_add_test(tc_core, s21_memset_9);
  tcase_add_test(tc_core, s21_memset_10);
  tcase_add_test(tc_core, s21_memset_11);
  tcase_add_test(tc_core, s21_memset_12);
  tcase_add_test(tc_core, s21_memset_13);

  tcase_add_test(tc_core, s21_strlen_1);
  tcase_add_test(tc_core, s21_strlen_2);
  tcase_add_test(tc_core, s21_strlen_3);
  tcase_add_test(tc_core, s21_strlen_4);
  tcase_add_test(tc_core, s21_strlen_5);
  tcase_add_test(tc_core, s21_strlen_6);
  tcase_add_test(tc_core, s21_strlen_7);
  tcase_add_test(tc_core, s21_strlen_8);
  tcase_add_test(tc_core, s21_strlen_9);
  tcase_add_test(tc_core, s21_strlen_10);
  tcase_add_test(tc_core, s21_strlen_11);
  tcase_add_test(tc_core, s21_strlen_12);
  tcase_add_test(tc_core, s21_strlen_13);
  tcase_add_test(tc_core, s21_strlen_14);
  tcase_add_test(tc_core, s21_strlen_15);
  tcase_add_test(tc_core, s21_strlen_16);
  tcase_add_test(tc_core, s21_strlen_17);
  tcase_add_test(tc_core, s21_strlen_18);
  tcase_add_test(tc_core, s21_strlen_19);
  tcase_add_test(tc_core, s21_strlen_20);
  tcase_add_test(tc_core, s21_strlen_21);
  tcase_add_test(tc_core, s21_strlen_22);
  tcase_add_test(tc_core, s21_strlen_23);
  tcase_add_test(tc_core, s21_strlen_24);
  tcase_add_test(tc_core, s21_strlen_25);
  tcase_add_test(tc_core, s21_strlen_26);
  tcase_add_test(tc_core, s21_strlen_27);
  tcase_add_test(tc_core, s21_strlen_28);
  tcase_add_test(tc_core, s21_strlen_29);
  tcase_add_test(tc_core, s21_strlen_30);

  tcase_add_test(tc_core, s21_strncpy_1);
  tcase_add_test(tc_core, s21_strncpy_2);
  tcase_add_test(tc_core, s21_strncpy_3);
  tcase_add_test(tc_core, s21_strncpy_4);
  tcase_add_test(tc_core, s21_strncpy_5);
  tcase_add_test(tc_core, s21_strncpy_6);
  tcase_add_test(tc_core, s21_strncpy_7);
  tcase_add_test(tc_core, s21_strncpy_8);
  tcase_add_test(tc_core, s21_strncpy_9);
  tcase_add_test(tc_core, s21_strncpy_10);
  tcase_add_test(tc_core, s21_strncpy_11);
  tcase_add_test(tc_core, s21_strncpy_12);
  tcase_add_test(tc_core, s21_strncpy_13);
  tcase_add_test(tc_core, s21_strncpy_14);
  tcase_add_test(tc_core, s21_strncpy_15);
  tcase_add_test(tc_core, s21_strncpy_16);
  tcase_add_test(tc_core, s21_strncpy_17);
  tcase_add_test(tc_core, s21_strncpy_18);
  tcase_add_test(tc_core, s21_strncpy_19);
  tcase_add_test(tc_core, s21_strncpy_20);
  tcase_add_test(tc_core, s21_strncpy_21);
  tcase_add_test(tc_core, s21_strncpy_22);
  tcase_add_test(tc_core, s21_strncpy_23);
  tcase_add_test(tc_core, s21_strncpy_24);

  tcase_add_test(tc_core, s21_to_lower_1);
  tcase_add_test(tc_core, s21_to_lower_2);
  tcase_add_test(tc_core, s21_to_lower_3);
  tcase_add_test(tc_core, s21_to_lower_4);
  tcase_add_test(tc_core, s21_to_lower_5);
  tcase_add_test(tc_core, s21_to_lower_6);
  tcase_add_test(tc_core, s21_to_lower_7);
  tcase_add_test(tc_core, s21_to_lower_8);
  tcase_add_test(tc_core, s21_to_lower_9);
  tcase_add_test(tc_core, s21_to_lower_10);
  tcase_add_test(tc_core, s21_to_lower_11);
  tcase_add_test(tc_core, s21_to_lower_12);
  tcase_add_test(tc_core, s21_to_lower_13);
  tcase_add_test(tc_core, s21_to_lower_14);
  tcase_add_test(tc_core, s21_to_lower_15);
  tcase_add_test(tc_core, s21_to_lower_16);
  tcase_add_test(tc_core, s21_to_lower_17);
  tcase_add_test(tc_core, s21_to_lower_18);
  tcase_add_test(tc_core, s21_to_lower_19);
  tcase_add_test(tc_core, s21_to_lower_20);

  tcase_add_test(tc_core, s21_to_upper_1);
  tcase_add_test(tc_core, s21_to_upper_2);
  tcase_add_test(tc_core, s21_to_upper_3);
  tcase_add_test(tc_core, s21_to_upper_4);
  tcase_add_test(tc_core, s21_to_upper_5);
  tcase_add_test(tc_core, s21_to_upper_6);
  tcase_add_test(tc_core, s21_to_upper_7);
  tcase_add_test(tc_core, s21_to_upper_8);
  tcase_add_test(tc_core, s21_to_upper_9);
  tcase_add_test(tc_core, s21_to_upper_10);
  tcase_add_test(tc_core, s21_to_upper_11);
  tcase_add_test(tc_core, s21_to_upper_12);
  tcase_add_test(tc_core, s21_to_upper_13);
  tcase_add_test(tc_core, s21_to_upper_14);
  tcase_add_test(tc_core, s21_to_upper_15);
  tcase_add_test(tc_core, s21_to_upper_16);
  tcase_add_test(tc_core, s21_to_upper_17);
  tcase_add_test(tc_core, s21_to_upper_18);
  tcase_add_test(tc_core, s21_to_upper_19);
  tcase_add_test(tc_core, s21_to_upper_20);

  tcase_add_test(tc_core, s21_memcmp_1);
  tcase_add_test(tc_core, s21_memcmp_2);
  tcase_add_test(tc_core, s21_memcmp_3);
  tcase_add_test(tc_core, s21_memcmp_4);
  tcase_add_test(tc_core, s21_memcmp_5);
  tcase_add_test(tc_core, s21_memcmp_6);
  tcase_add_test(tc_core, s21_memcmp_7);
  tcase_add_test(tc_core, s21_memcmp_8);
  tcase_add_test(tc_core, s21_memcmp_9);
  tcase_add_test(tc_core, s21_memcmp_10);
  tcase_add_test(tc_core, s21_memcmp_11);
  tcase_add_test(tc_core, s21_memcmp_12);
  tcase_add_test(tc_core, s21_memcmp_13);
  tcase_add_test(tc_core, s21_memcmp_14);
  tcase_add_test(tc_core, s21_memcmp_15);
  tcase_add_test(tc_core, s21_memcmp_16);
  tcase_add_test(tc_core, s21_memcmp_16);
  tcase_add_test(tc_core, s21_memcmp_17);
  tcase_add_test(tc_core, s21_memcmp_18);
  tcase_add_test(tc_core, s21_memcmp_19);
  tcase_add_test(tc_core, s21_memcmp_20);

  tcase_add_test(tc_core, s21_strchr_1);
  tcase_add_test(tc_core, s21_strchr_2);
  tcase_add_test(tc_core, s21_strchr_3);
  tcase_add_test(tc_core, s21_strchr_4);
  tcase_add_test(tc_core, s21_strchr_5);
  tcase_add_test(tc_core, s21_strchr_6);
  tcase_add_test(tc_core, s21_strchr_7);
  tcase_add_test(tc_core, s21_strchr_8);
  tcase_add_test(tc_core, s21_strchr_9);
  tcase_add_test(tc_core, s21_strchr_10);
  tcase_add_test(tc_core, s21_strchr_11);
  tcase_add_test(tc_core, s21_strchr_12);
  tcase_add_test(tc_core, s21_strchr_13);
  tcase_add_test(tc_core, s21_strchr_14);

  tcase_add_test(tc_core, s21_strncmp_1);
  tcase_add_test(tc_core, s21_strncmp_2);
  tcase_add_test(tc_core, s21_strncmp_3);
  tcase_add_test(tc_core, s21_strncmp_4);
  tcase_add_test(tc_core, s21_strncmp_5);
  tcase_add_test(tc_core, s21_strncmp_6);
  tcase_add_test(tc_core, s21_strncmp_7);
  tcase_add_test(tc_core, s21_strncmp_8);
  tcase_add_test(tc_core, s21_strncmp_9);
  tcase_add_test(tc_core, s21_strncmp_10);
  tcase_add_test(tc_core, s21_strncmp_11);
  tcase_add_test(tc_core, s21_strncmp_12);
  tcase_add_test(tc_core, s21_strncmp_13);
  tcase_add_test(tc_core, s21_strncmp_14);
  tcase_add_test(tc_core, s21_strncmp_15);
  tcase_add_test(tc_core, s21_strncmp_16);
  tcase_add_test(tc_core, s21_strncmp_17);
  tcase_add_test(tc_core, s21_strncmp_18);
  tcase_add_test(tc_core, s21_strncmp_19);
  tcase_add_test(tc_core, s21_strncmp_20);

  tcase_add_test(tc_core, s21_trim_1);
  tcase_add_test(tc_core, s21_trim_2);
  tcase_add_test(tc_core, s21_trim_3);
  tcase_add_test(tc_core, s21_trim_4);
  tcase_add_test(tc_core, s21_trim_5);
  tcase_add_test(tc_core, s21_trim_6);
  tcase_add_test(tc_core, s21_trim_7);
  tcase_add_test(tc_core, s21_trim_8);
  tcase_add_test(tc_core, s21_trim_9);
  tcase_add_test(tc_core, s21_trim_10);
  tcase_add_test(tc_core, s21_trim_11);
  tcase_add_test(tc_core, s21_trim_12);
  tcase_add_test(tc_core, s21_trim_13);
  tcase_add_test(tc_core, s21_trim_14);

  tcase_add_test(tc_core, s21_insert_1);
  tcase_add_test(tc_core, s21_insert_2);
  tcase_add_test(tc_core, s21_insert_3);
  tcase_add_test(tc_core, s21_insert_4);
  tcase_add_test(tc_core, s21_insert_5);
  tcase_add_test(tc_core, s21_insert_6);
  tcase_add_test(tc_core, s21_insert_7);
  tcase_add_test(tc_core, s21_insert_8);
  tcase_add_test(tc_core, s21_insert_9);
  tcase_add_test(tc_core, s21_insert_10);
  tcase_add_test(tc_core, s21_insert_11);
  tcase_add_test(tc_core, s21_insert_12);
  tcase_add_test(tc_core, s21_insert_13);
  tcase_add_test(tc_core, s21_insert_14);
  tcase_add_test(tc_core, s21_insert_15);
  tcase_add_test(tc_core, s21_insert_16);
  tcase_add_test(tc_core, s21_insert_17);
  tcase_add_test(tc_core, s21_insert_18);

  tcase_add_test(tc_core, sprintf_d_test);
  tcase_add_test(tc_core, sprintf_c_test);
  tcase_add_test(tc_core, sprintf_s_test);
  tcase_add_test(tc_core, sprintf_ld_test);
  tcase_add_test(tc_core, sprintf_u_test);
  tcase_add_test(tc_core, sprintf_ULTIMA_test);
  tcase_add_test(tc_core, test_proc);
  tcase_add_test(tc_core, test_simple);
  tcase_add_test(tc_core, test_complex_e);
  tcase_add_test(tc_core, test_complex_E);
  tcase_add_test(tc_core, test_complex_x);
  tcase_add_test(tc_core, test_complex_X);
  tcase_add_test(tc_core, test_complex_o);
  tcase_add_test(tc_core, test_anomal_large_int);
  tcase_add_test(tc_core, test_precision);
  tcase_add_test(tc_core, test_large_int);
  tcase_add_test(tc_core, test_hash_e);
  tcase_add_test(tc_core, test_zero_padding);
  tcase_add_test(tc_core, test_mixed_ld);
  tcase_add_test(tc_core, test_mixed_f);
  tcase_add_test(tc_core, test_mixed_e);
  tcase_add_test(tc_core, test_wide_string_specifier);

  tcase_add_test(tc_core, sscanf_1);
  tcase_add_test(tc_core, sscanf_2);
  tcase_add_test(tc_core, sscanf_3);
  tcase_add_test(tc_core, sscanf_4);
  tcase_add_test(tc_core, sscanf_5);
  tcase_add_test(tc_core, sscanf_6);
  tcase_add_test(tc_core, sscanf_7);
  tcase_add_test(tc_core, sscanf_8);
  tcase_add_test(tc_core, sscanf_9);
  tcase_add_test(tc_core, sscanf_11);
  tcase_add_test(tc_core, sscanf_12);
  tcase_add_test(tc_core, sscanf_13);
  tcase_add_test(tc_core, sscanf_14);
  tcase_add_test(tc_core, sscanf_15);
  tcase_add_test(tc_core, sscanf_16);
  tcase_add_test(tc_core, sscanf_17);
  tcase_add_test(tc_core, sscanf_18);
  tcase_add_test(tc_core, sscanf_19);
  tcase_add_test(tc_core, sscanf_20);
  tcase_add_test(tc_core, sscanf_21);
  tcase_add_test(tc_core, sscanf_22);
  tcase_add_test(tc_core, sscanf_23);
  tcase_add_test(tc_core, sscanf_24);
  tcase_add_test(tc_core, sscanf_25);
  tcase_add_test(tc_core, sscanf_26);
  tcase_add_test(tc_core, sscanf_27);
  tcase_add_test(tc_core, sscanf_28);
  tcase_add_test(tc_core, sscanf_29);
  tcase_add_test(tc_core, sscanf_30);
  tcase_add_test(tc_core, sscanf_32);
  tcase_add_test(tc_core, sscanf_33);

  tcase_add_test(tc_core, sscanf_34);
  tcase_add_test(tc_core, sscanf_35);
  tcase_add_test(tc_core, sscanf_36);
  tcase_add_test(tc_core, sscanf_37);
  tcase_add_test(tc_core, sscanf_38);
  tcase_add_test(tc_core, sscanf_39);
  tcase_add_test(tc_core, sscanf_40);
  tcase_add_test(tc_core, sscanf_41);
  tcase_add_test(tc_core, sscanf_42);
  tcase_add_test(tc_core, sscanf_43);
  tcase_add_test(tc_core, sscanf_44);
  tcase_add_test(tc_core, sscanf_45);
  tcase_add_test(tc_core, sscanf_46);
  tcase_add_test(tc_core, sscanf_47);

  tcase_add_test(tc_core, strcspn_test);
  tcase_add_test(tc_core, strpbrk_test);
  tcase_add_test(tc_core, strstr_test);
  tcase_add_test(tc_core, strtok_test);
  tcase_add_test(tc_core, memchr_test);
  tcase_add_test(tc_core, strncat_test);

  tcase_add_test(tc_core, strrchr_test);
  tcase_add_test(tc_core, s21_strerror_test);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  Suite *s = suite_core();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}