/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:34:51 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 01:01:27 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upx(size_t number, int reg, size_t base)
{
	size_t		num;
	static int	res;

	res = 0;
	if (number == 0)
	{
		res += write(1, "0", 1);
		return (res);
	}
	if (number > (base - 1))
		ft_print_upx((number / base), reg, base);
	num = number % base;
	if ((num >= 10) && (num <= 15) && (reg == 0))
		res += ft_print_chars((char)num + 87, 1);
	else if ((num >= 10) && (num <= 15) && (reg == 1))
		res += ft_print_chars((char)num + 55, 1);
	else if (num <= 9)
		res += ft_print_chars((char)num + 48, 1);
	return (res);
}
