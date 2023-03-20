#include "./ft_printf_bonus.h"

t_format	ft_newformat(void)
{
	t_format	newformat;

	newformat.minus = 0;
	newformat.plus = 0;
	newformat.width = 0;
	newformat.precision = 0;
	newformat.specifier = 0;
	newformat.zero = 0;
	newformat.dot = 0;
	newformat.space = 0;
	newformat.sharp = 0;
	newformat.neg_prec = 0;
	return (newformat);
}

int ft_start_format(char *str)
{
	ft_newformat();
}