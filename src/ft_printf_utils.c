#include "ft_printf.h"
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
    while(write_char[--i])
    {
        write(1, &write_char[i], 1);
    }
    return (i);
}
/* 
int main()
{
    char *deneme;
    deneme = "deneme";
    ft_hex_convert(1420);
} */