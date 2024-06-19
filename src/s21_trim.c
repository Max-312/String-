#include "s21_string.h"

static s21_size_t s21_find_start_of_trim(const char *src,
                                         const char *trim_chars) {
  s21_size_t index = 0;
  while (src[index] && s21_strchr(trim_chars, src[index])) {
    index++;
  }
  return index;
}

static s21_size_t s21_find_end_of_trim(const char *src,
                                       const char *trim_chars) {
  s21_size_t index = s21_strlen(src);
  while (index > 0 && s21_strchr(trim_chars, src[index - 1])) {
    index--;
  }
  return index;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed_str = S21_NULL;

  if (src) {
    if (!trim_chars || trim_chars[0] == '\0') {
      trim_chars = " \t\n";
    }

    s21_size_t start_index = s21_find_start_of_trim(src, trim_chars);
    s21_size_t end_index = s21_find_end_of_trim(src, trim_chars);

    s21_size_t trimmed_length =
        (end_index > start_index) ? (end_index - start_index) : 0;
    trimmed_str = (char *)malloc(trimmed_length + 1);

    if (trimmed_str) {
      for (s21_size_t i = 0; i < trimmed_length; i++) {
        trimmed_str[i] = src[start_index + i];
      }
      trimmed_str[trimmed_length] = '\0';
    }
  }

  return trimmed_str;
}
