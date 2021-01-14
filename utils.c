/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:40:06 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 01:01:46 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pu_len(size_t num, int base, char c)
{
	int len;

	len = 0;
	if (c == 'p')
		len += 2;
	while (num > (size_t)base - 1)
	{
		num /= base;
		len++;
	}
	len++;
	return (len);
}

int	ft_print_width(char c, int width)
{
	int i;

	i = -1;
	while (++i < width)
		ft_putchar_fd(c, 1);
	return (i);
}

int	ft_print_chars(char c, int width)
{
	int res;

	res = 0;
	while (width)
	{
		res += write(1, &c, 1);
		width--;
	}
	return (res);
}

int	ft_number_len(int number)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (number < 0)
		i = -1 * number;
	else
		i = number;
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_print_nbr(int n)
{
	unsigned int	i;
	char			res;
	static int		count;

	i = 0;
	count = 0;
	if (n < 0)
		i = n * -1;
	else
		i = n;
	if (i > 9)
		ft_print_nbr(i / 10);
	res = i % 10 + 48;
	count += write(1, &res, 1);
	return (count);
}
