#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printstr(char * str);
int ft_hex_convert(unsigned long long decimal);
int ft_print_decimal(int decimal);
int ft_print_integer(int integer);
int ft_print_unsigned(unsigned int n);
int ft_print_percent();
#endif