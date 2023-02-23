#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>
int ft_printstr(char * str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_hex_convert(unsigned long long decimal)
{
    int i;
    int remainder;
    unsigned long long quotient;
    char write_char[20];
    int j;

    quotient = decimal;
    i = 0;
    remainder = 0;
    write(1, "0x", 2);
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
        {
            write_char[i++] = '0' + remainder;
        }
        else
        {
            write_char[i++] = remainder - 10 + 'a';
        }
        quotient = quotient / 16;
    }
    j = i;
    while(write_char[--i])
    {
        write(1, &write_char[i], 1);
    }
    j += 3;
    return (j);
}

int ft_print_decimal(int decimal)
{
    char *converted;
    int i;

    converted = ft_itoa(decimal);
    i = 0;
    while(converted[i])
        write(1, &converted[i++], 1);
    i += 1;
    return(i);
}

int ft_print_integer(int integer)
{
    char *converted;
    int i;

    ft_putnbr_fd(integer,1);
    converted = ft_itoa(integer);
    i = 0;
    while(converted[i++]);
    return(i);
}

int ft_print_unsigned(unsigned int n)
{
    char *converted;
    int i;

    converted = ft_itoa(n);
    i = 0;
    while(converted[i])
        write(1, &converted[i++], 1);
    i += 1;
    return(i);
}
