/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:12:23 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 01:02:10 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkwidth(int *flag, const char **str, va_list vl)
{
	if (**str == '*')
	{
		flag[2] = va_arg(vl, int);
		*str += 1;
	}
	else
	{
		flag[2] = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			*str += 1;
	}
	if (flag[2] < 0)
	{
		flag[2] *= (-1);
		flag[1] = 1;
		flag[0] = 0;
	}
}

int		ft_checktype(int *flag, const char **str, va_list vl, int *count)
{
	int res;

	res = 0;
	if (**str == 'c')
		res = ft_printchar(flag, vl);
	else if (**str == 's')
		res = ft_printstr(flag, vl);
	else if (**str == 'd' || **str == 'i')
		res = ft_printnum(flag, vl);
	else if (**str == 'u')
		res = ft_printunsigned(flag, vl);
	else if (**str == 'p')
		res = ft_print_ptr(flag, vl);
	else if (**str == 'x')
		res = ft_printhex(flag, vl, 'x');
	else if (**str == 'X')
		res = ft_printhex(flag, vl, 'X');
	else if (**str == '%')
		res = ft_printpercent(flag);
	else
		return (0);
	*count += res;
	return (1);
}

void	ft_checkprecision(int *flag, const char **str, va_list vl)
{
	int	i;

	i = 0;
	*str += 1;
	if (**str == '*')
	{
		flag[3] = va_arg(vl, int);
		*str += 1;
	}
	else
	{
		flag[3] = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			*str += 1;
	}
	if (flag[3] < 0)
	{
		flag[3] = -1;
	}
}

void	ft_checkflags(const char **str, int *flag)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			flag[1] = 1;
		if (**str == '0')
			flag[0] = 1;
		*str += 1;
	}
	if (flag[1] == 1)
		flag[0] = 0;
}
