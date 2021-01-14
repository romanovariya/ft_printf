/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:42:02 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 00:56:59 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initflags(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = -1;
	flag[4] = 0;
}

int		ft_parser(const char **str, va_list vl, int *count)
{
	int flags[5];

	ft_initflags(flags);
	ft_checkflags(str, flags);
	ft_checkwidth(flags, str, vl);
	if (**str == '.')
		ft_checkprecision(flags, str, vl);
	return (ft_checktype(flags, str, vl, count));
}

int		ft_printf(const char *str, ...)
{
	va_list	vl;
	int		count;

	count = 0;
	va_start(vl, str);
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str += 1;
			if (!ft_parser(&str, vl, &count))
				return (-1);
			str++;
		}
		else
			count = count + write(1, str++, 1);
	}
	va_end(vl);
	return (count);
}
