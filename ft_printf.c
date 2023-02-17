#include "ft_printf.h"

int ft_printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_check(va_list args, char str)
{
    int return_value;

    return_value = 0;
    if(str == 'c')
    {
        return_value += ft_printchar(va_arg(args, int));
    }
    else if(str == 's')
    {
        return_value += ft_printstr(va_arg(args, char*));
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
            return_value += ft_check(ptr, input[i + 1]);
            i++;
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
    printf("%d", ft_printf("123%c %s", '4', "1234"));
    /* ft_printf("ilk string: %s, ilk karakter: %c", "selam", 'a'); */
}
