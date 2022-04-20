#ifndef ZAL
#define ZAL
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char x);
int print_n(const va_list ls);
int _printf(const char *format, ...);
int print_char(const va_list a);
int print_string(const va_list b);
int print_modulo(const va_list list);
int num_digits(int n);
void print_num(int n);
int len(const char *s);

#endif
