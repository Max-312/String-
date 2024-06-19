#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = 0;

    while (str[len]) {
      len++;
    }

    result = (char *)malloc(len + 1);
    if (result != S21_NULL) {
      for (s21_size_t i = 0; i < len; i++) {
        uint8_t ch = (uint8_t)str[i];
        if (ch >= 'a' && ch <= 'z') {
          result[i] = ch - ASCII_DIFF;
        } else {
          result[i] = ch;
        }
      }
      result[len] = '\0';
    }
  }

  return result;
}
