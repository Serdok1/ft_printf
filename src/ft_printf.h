#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printstr(char * str);
int ft_hex_convert(unsigned long long decimal);
void	ft_putchar_fd(char c, int fd);
#endif