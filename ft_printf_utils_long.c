/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:45:58 by sozbayra          #+#    #+#             */
/*   Updated: 2023/03/29 11:23:23 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_decimal(int decimal)
{
	char	*converted;
	int		i;

	converted = ft_itoa(decimal);
	i = 0;
	while (converted[i])
		write(1, &converted[i++], 1);
	free(converted);
	return (i);
}

int	ft_print_integer(int integer)
{
	char	*converted;
	int		i;

	ft_putnbr_fd(integer, 1);
	converted = ft_itoa(integer);
	i = 0;
	while (converted[++i])
		;
	free(converted);
	return (i);
}

int	ft_print_unsigned(unsigned int n)
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

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_num_len(unsigned int num)
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
