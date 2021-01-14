/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:19:20 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 01:01:11 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int *flag, va_list vl)
{
	char	c;
	int		len;
	int		res;

	res = 0;
	len = flag[2];
	c = (char)va_arg(vl, int);
	if (flag[1] == 1 && (flag[2] > 1 || flag[2] == 0))
	{
		res += write(1, &c, 1);
		res += ft_print_width(' ', len - 1);
		return (res);
	}
	if (flag[1] == 0 && (flag[2] > 1 || flag[2] == 0))
	{
		res += ft_print_width(' ', len - 1);
		res += write(1, &c, 1);
		return (res);
	}
	else
		res += write(1, &c, 1);
	return (1);
}
