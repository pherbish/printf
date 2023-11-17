#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdio.h>
int print_digit(long n, int b);
int print_char(int c);
int print_str(char *str);
int format_specicifier(char specifier, va_list ap);
int _printf(const char *format, ...);
#endif
