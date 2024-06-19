#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0, flag = 0;

  unsigned char *array1 = (unsigned char *)str1;
  unsigned char *array2 = (unsigned char *)str2;

  if (n && array1 && array2) {
    for (s21_size_t i = 0; i < n && !flag; i++) {
      if ((result = array1[i] - array2[i]) != 0) flag = 1;
    }
  }

  return result;
}