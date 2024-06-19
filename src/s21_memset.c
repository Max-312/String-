#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL) {
    uint8_t *str_pointer = (uint8_t *)str;

    for (s21_size_t i = 0; i < n; i++) {
      str_pointer[i] = (uint8_t)c;
    }
  }
  return str;
}
