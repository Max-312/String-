#include "s21_string.h"

char *s21_strchr(const char *str, int symbol) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    while (*str && *str != symbol) {
      str++;
    }
    if (*str == symbol) {
      result = (char *)str;
    }
  }
  return result;
}