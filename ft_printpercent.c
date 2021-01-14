/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:20:19 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 01:02:37 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpercent(int *flag)
{
	int len;
	int	res;

	res = 0;
	len = flag[2];
	if (flag[1] == 1 && (flag[2] > 1 || flag[2] == 0))
	{
		res += write(1, "%", 1);
		res += ft_print_width(' ', len - 1);
		return (res);
	}
	if (flag[1] == 0 && (flag[2] > 1 || flag[2] == 0))
	{
		if (flag[0] == 0)
			res += ft_print_width(' ', len - 1);
		if (flag[0] == 1)
			res += ft_print_width('0', len - 1);
		res += write(1, "%", 1);
		return (res);
	}
	else
		res += write(1, "%", 1);
	return (res);
}
