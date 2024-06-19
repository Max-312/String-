#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0, flag = 0;

  if (n > 0 && str1 && str2) {
    for (s21_size_t i = 0; i < n && !flag; i++) {
      if ((result = str1[i] - str2[i]) != 0) flag = 1;
    }
  }
  return result;
}