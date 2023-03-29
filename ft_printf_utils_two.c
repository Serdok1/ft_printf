/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:47:39 by sozbayra          #+#    #+#             */
/*   Updated: 2023/03/29 11:27:47 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int	ft_hex_write(char *write_char, int i)
{
	int	j;

	j = i;
	while (write_char[--i])
		write(1, &write_char[i], 1);
	return (j);
}

int	ft_hex_convert_lower(unsigned long decimal)
{
	int					i;
	int					remainder;
	unsigned long long	quotient;
	char				write_char[100];

	quotient = decimal;
	i = 0;
	remainder = 0;
	if (quotient == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			write_char[i++] = '0' + remainder;
		else
			write_char[i++] = remainder - 10 + 'a';
		quotient = quotient / 16;
	}
	return (ft_hex_write(write_char, i));
}
