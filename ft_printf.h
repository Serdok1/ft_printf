/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:40:13 by sozbayra          #+#    #+#             */
/*   Updated: 2023/03/29 11:21:46 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printstr(char *str);
int		ft_hex_convert_upper(unsigned long decimal);
int		ft_print_decimal(int decimal);
int		ft_print_integer(int integer);
int		ft_print_unsigned(unsigned int n);
int		ft_print_percent(void);
int		ft_print_ptr(unsigned long decimal);
int		ft_print_hex(unsigned int decimal, int key);
int		ft_printf(const char *input, ...);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned int num);
int		ft_hex_convert_lower(unsigned long decimal);
int		ft_hex_write(char *write_char, int i);
#endif