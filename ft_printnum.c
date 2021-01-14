/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:27:38 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/03 16:26:33 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_num_w(int num, int len, int *flag)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (num < 0)
		space--;
	if (space > 0)
		res += ft_print_chars(' ', space);
	if (num < 0)
		res += write(1, "-", 1);
	if (len != 0)
		res += ft_print_nbr(num);
	return (res);
}

int	ft_num_min(int num, int len, int *flag)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (num < 0)
	{
		space--;
		res += write(1, "-", 1);
	}
	if (len != 0)
		res += ft_print_nbr(num);
	if (space > 0)
		res += ft_print_chars(' ', space);
	return (res);
}

int	ft_num_zero(int num, int len, int *flag)
{
	int zero;
	int res;

	res = 0;
	zero = 0;
	if (flag[2] > len)
		zero = flag[2] - len - (num < 0 ? 1 : 0);
	if (num < 0)
		res += write(1, "-", 1);
	if (zero > 0)
		res += ft_print_chars('0', zero);
	res += ft_print_nbr(num);
	return (res);
}

int	ft_num_prec(int num, int len, int *flag)
{
	int space;
	int zero;
	int res;

	res = 0;
	space = 0;
	zero = 0;
	flag[3] > len ? zero = flag[3] - len : 0;
	if (flag[2] > (len + zero + (num < 0 ? 1 : 0)))
		space = flag[2] - len - zero - (num < 0 ? 1 : 0);
	if (flag[1] == 1)
	{
		num < 0 ? res += write(1, "-", 1) : 0;
		res += ft_print_chars('0', zero);
		res += ft_print_nbr(num);
		res += ft_print_chars(' ', space);
	}
	else
	{
		res += ft_print_chars(' ', space);
		num < 0 ? res += write(1, "-", 1) : 0;
		res += ft_print_chars('0', zero);
		res += ft_print_nbr(num);
	}
	return (res);
}

int	ft_printnum(int *flag, va_list vl)
{
	int	len;
	int	res;
	int	num;

	res = 0;
	num = va_arg(vl, int);
	len = ft_number_len(num);
	if (flag[3] == 0 && num == 0)
		len = 0;
	if (flag[3] == -1 && flag[0] == 1)
		res = ft_num_zero(num, len, flag);
	else if (!(flag[3] == -1) && !(flag[3] == 0 && num == 0))
		res = ft_num_prec(num, len, flag);
	else if (flag[1] == 1)
		res = ft_num_min(num, len, flag);
	else if (flag[2])
		res = ft_num_w(num, len, flag);
	else if (num < 0)
	{
		res += write(1, "-", 1);
		res += ft_print_nbr(num);
	}
	else
		(len != 0 ? res += ft_print_nbr(num) : 0);
	return (res);
}
