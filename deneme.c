#include <stdio.h>
#include "ft_printf_bonus.h"
int main()
{
    int a;
    int b;
    a = ft_printf("ft: % s % s % s % s % s \n", " - ", "", "4", "", "2 ");
    b = printf("pr: % s % s % s % s % s \n", " - ", "", "4", "", "2 ");
    printf("a: %d\nb: %d", a, b);
}