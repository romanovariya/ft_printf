/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:22:40 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/03 23:45:07 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cutstr(int *flag, char *str)
{
	char *copy;

	if (flag[3] > -1 && str)
	{
		copy = ft_substr(str, 0, flag[3]);
		return (copy);
	}
	else if (flag[3] == -1 && str)
		return (ft_strdup(str));
	else if (flag[3] == -1 && !str)
		return (ft_strdup("(null)"));
	else if (flag[3] > -1 && !str)
	{
		copy = ft_strdup("(null)");
		str = copy;
		ft_strlcpy(copy, str, flag[3] + 1);
		return (copy);
	}
	return (str);
}

int		ft_printstr(int *flag, va_list vl)
{
	int		strlen;
	char	*s;
	int		res;

	s = va_arg(vl, char *);
	s = ft_cutstr(flag, s);
	strlen = ft_strlen(s);
	res = 0;
	if (flag[1] == 0)
	{
		if (flag[0] == 1)
			res += ft_print_width('0', flag[2] - strlen);
		else
			res += ft_print_width(' ', flag[2] - strlen);
	}
	res += ft_putstr_fd(s, 1);
	if (flag[1] == 1)
		res += ft_print_width(' ', flag[2] - strlen);
	free(s);
	return (res);
}
