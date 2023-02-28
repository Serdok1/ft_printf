#include "ft_printf_bonus.h"
#include "libft/libft.h"

int ft_print_blank(int d)
{
    int return_value;
    return_value = 0;
    if(d >= 0)
    {
        write(1, " ", 1);
        return_value += ft_print_integer(d);
        return_value += 1;
        return (return_value);
    }
    return_value = ft_print_integer(d);
    return (return_value);
}


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

int ft_print_ptr(unsigned long decimal)
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

int ft_print_hex(unsigned int decimal, int key)
{
    int length;

    length = ft_ptr_len(decimal);
    return (ft_hex_convert(decimal, length, key));
}

int ft_hex_convert(unsigned long decimal, int length, int key)
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
    if(quotient == 0)
    {
        write(1, "0", 1);
        return(1);
    }
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
    int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}

int ft_print_percent()
{
    write(1, "%", 1);
    return (1);
}

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}