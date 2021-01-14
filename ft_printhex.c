/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:23:43 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 14:41:49 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_w(size_t num, int len, int *flag, int registr)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (space > 0)
		res += ft_print_chars(' ', space);
	if (len != 0)
		res += ft_print_upx(num, registr, 16);
	return (res);
}

int	ft_hex_zero(size_t num, int len, int *flag, int registr)
{
	int zero;
	int res;

	res = 0;
	zero = 0;
	if (flag[2] > len)
		zero = flag[2] - len;
	if (zero > 0)
		res += ft_print_chars('0', zero);
	if (len != 0)
		res += ft_print_upx(num, registr, 16);
	return (res);
}

int	ft_hex_min(size_t num, int len, int *flag, int registr)
{
	int res;
	int space;

	res = 0;
	space = flag[2] - len;
	if (flag[2] <= len)
		res += ft_print_upx(num, registr, 16);
	else
	{
		if (len != 0)
			res += ft_print_upx(num, registr, 16);
		if (space > 0)
			res += ft_print_chars(' ', space);
	}
	return (res);
}

int	ft_hex_prec(size_t num, int len, int *flag, int registr)
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
		(len != 0 ? res += ft_print_upx(num, registr, 16) : 0);
		res += ft_print_chars(' ', space);
	}
	else
	{
		res += ft_print_chars(' ', space);
		res += ft_print_chars('0', zero);
		(len != 0 ? res += ft_print_upx(num, registr, 16) : 0);
	}
	return (res);
}

int	ft_printhex(int *flag, va_list vl, char c)
{
	unsigned int	num;
	int				len;
	int				res;
	int				registr;

	res = 0;
	registr = 0;
	num = va_arg(vl, unsigned int);
	if (c == 'X')
		registr = 1;
	len = ft_pu_len(num, 16, c);
	if (flag[3] == 0 && num == 0)
		len = 0;
	if (flag[3] == -1 && flag[0] == 1)
		res = ft_hex_zero(num, len, flag, registr);
	else if (flag[3] != -1)
		res = ft_hex_prec(num, len, flag, registr);
	else if (flag[1] == 1)
		res = ft_hex_min(num, len, flag, registr);
	else if (flag[2])
		res = ft_hex_w(num, len, flag, registr);
	else
		(len != 0 ? res += ft_print_upx(num, registr, 16) : 0);
	return (res);
}
