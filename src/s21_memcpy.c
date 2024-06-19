#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    uint8_t *dest_pointer = (uint8_t *)dest;
    const uint8_t *src_pointer = (const uint8_t *)src;

    for (s21_size_t i = 0; i < n; i++) {
      dest_pointer[i] = src_pointer[i];
    }
  }
  return dest;
}