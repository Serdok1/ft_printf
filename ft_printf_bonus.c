#include "ft_printf_bonus.h"
#include "./libft/libft.h"
#include <stdio.h>

int ft_printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_check(va_list args, char str, int i, const char *full)
{
    int return_value;

    return_value = 0;
    if(str == 'c')
        return_value += ft_printchar(va_arg(args, int));
    else if(str == 's')
        return_value += ft_printstr(va_arg(args, char*));
    else if(str == 'p')
        return_value += ft_print_ptr(va_arg(args, unsigned long));
    else if(str == 'd')
        return_value += ft_print_decimal(va_arg(args, int));
    else if(str == 'i')
       return_value += ft_print_integer(va_arg(args, int));
    else if(str == 'u')
        return_value += ft_print_unsigned(va_arg(args, unsigned int));
    else if(str == 'x')
        return_value += ft_print_hex(va_arg(args,unsigned int),0);
    else if(str == 'X')
        return_value += ft_print_hex(va_arg(args,unsigned int),1);
    else if(str == '%')
        return_value += ft_print_percent();
    else if(str == ' ')
    {
        if(full[i + 2] == 'd' || full[i + 2] == 'i')
        {
            return_value += ft_print_blank(va_arg(args, int));
        }
    }
    return (return_value);
}

int ft_printf(const char *input, ...)
{
    int i;
    va_list ptr;
    va_start(ptr, input);
    int return_value;

    i = 0;
    return_value = 0;
    while(input[i])
    {
        if(input[i] == '%')
        {
            return_value += ft_check(ptr, input[i + 1], i, input);
            i++;
        }
        else if(input[i] == 'd' || input[i] == 'i')
        {
            if(input[i - 1] == ' ')
            {
                if(input[i - 2] == '%')
                {
                    i++;
                }
            }
        }
        else
        {
            write(1, &input[i], 1);
            return_value++;
        }
        i++;
    }
    va_end(ptr);
    return (return_value);
}

#include <stdio.h>
int main()
{
    int a;

    a = 123123123;
    char *ptr;
    ptr = "deneme";
    int pr = printf(" % d ", 1);
    int ft = ft_printf(" % d ", 1);
    printf("pr: %d, ft: %d\n", pr, ft);
}