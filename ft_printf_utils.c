#include "ft_printf.h"
#include "libft/libft.h"

int ft_printstr(char * str)
{
    int i;

    i = 0;
    if(!str)
        str = "(null)";
    while(str[i])
    {
        write(1, &str[i++], 1);
    }
    return (i);
}

int ft_ptr_len(int decimal)
{
    int i;

    i = 0;
    while (decimal != 0)
    {
        decimal /= 16;
        i++;
    }
    return (i);
}

int ft_print_ptr(unsigned long long decimal)
{
    int i;
    if (!decimal)
    {
        write(1, "0x0", 3);
        return (3);
    }
    write(1, "0x", 2);
    i = ft_hex_convert(decimal, ft_ptr_len(decimal), 0);
    i += 2;
    return (i);
}

int ft_print_hex(unsigned long long decimal, int key)
{
    int length;

    length = ft_ptr_len(decimal);
    return (ft_hex_convert(decimal, length, key));
}

int ft_hex_convert(unsigned long long decimal, int length, int key)
{
    int i;
    int remainder;
    unsigned long long quotient;
    char write_char[length];
    int j;
    char key_char;

    if (key == 1)
        key_char = 'A';
    else
        key_char = 'a';

    quotient = decimal;
    i = 0;
    remainder = 0;
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
        {
            write_char[i++] = '0' + remainder;
        }
        else
        {
            write_char[i++] = remainder - 10 + key_char;
        }
        quotient = quotient / 16;
    }
    j = i;
    while(write_char[--i])
    {
        write(1, &write_char[i], 1);
    }
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
    free(converted);
    return(i);
}

int ft_print_integer(int integer)
{
    char *converted;
    int i;

    ft_putnbr_fd(integer,1);
    converted = ft_itoa(integer);
    i = 0;
    while(converted[++i]);
    free(converted);
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
    free(converted);
    return(i);
}

int ft_print_percent()
{
    write(1, "%", 1);
    return (1);
}
