/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:30:40 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 14:47:52 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_w(size_t num, int len, int *flag)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (space > 0)
		res += ft_print_chars(' ', space);
	if (len != 0)
		res += ft_print_upx(num, 0, 10);
	return (res);
}

int	ft_unsigned_min(size_t num, int len, int *flag)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (len != 0)
		res += ft_print_upx(num, 0, 10);
	if (space > 0)
		res += ft_print_chars(' ', space);
	return (res);
}

int	ft_unsigned_zero(size_t num, int len, int *flag)
{
	int zero;
	int res;

	res = 0;
	zero = 0;
	if (flag[2] > len)
		zero = flag[2] - len;
	if (zero > 0)
		res += ft_print_chars('0', zero);
	res += ft_print_upx(num, 0, 10);
	return (res);
}

int	ft_unsigned_prec(size_t num, int len, int *flag)
{
	int space;
	int zero;
	int res;

	res = 0;
	space = 0;
	zero = 0;
	if (flag[3] > len)
		zero = flag[3] - len;
	if (flag[2] > (len + zero))
		space = flag[2] - len - zero;
	if (flag[1] == 1)
	{
		res += ft_print_chars('0', zero);
		res += ft_print_upx(num, 0, 10);
		res += ft_print_chars(' ', space);
	}
	else
	{
		res += ft_print_chars(' ', space);
		res += ft_print_chars('0', zero);
		res += ft_print_upx(num, 0, 10);
	}
	return (res);
}

int	ft_printunsigned(int *flag, va_list vl)
{
	size_t	num;
	int		len;
	int		res;

	res = 0;
	num = va_arg(vl, unsigned int);
	len = ft_pu_len(num, 10, 'u');
	if (flag[3] == 0 && num == 0)
		len = 0;
	if (flag[3] == -1 && flag[0] == 1)
		res = ft_unsigned_zero(num, len, flag);
	else if (!(flag[3] == -1) && !(flag[3] == 0 && num == 0))
		res = ft_unsigned_prec(num, len, flag);
	else if (flag[1] == 1)
		res = ft_unsigned_min(num, len, flag);
	else if (flag[2])
		res = ft_unsigned_w(num, len, flag);
	else
		(len != 0 ? res += ft_print_upx(num, 0, 10) : 0);
	return (res);
}
