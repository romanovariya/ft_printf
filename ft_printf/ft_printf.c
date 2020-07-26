/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:21:41 by mbabette          #+#    #+#             */
/*   Updated: 2020/07/26 20:47:02 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_checkflags(const char **str, int *flag)
{
	while (**str == '-' || **str == '0')
	{
	if (**str == '-')
		flag[0] = 1;
	if (**str == '0')
		flag[1] = 1;
	*str++;
	}
	if (flag[1] == 1)
		flag[0] == 0;
		
}
void	ft_initflags(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
}
void	ft_checkwidth (int *flag, const char **str, va_list vl)
{
	if (**str == '*')
	{
		flag[2] = va_arg(vl, int);
	}
	else
	{
		
	}
	
}
int		ft_parser(const char **str, va_list vl, int count)
{
	int flags[5];

	ft_initflags(flags);
	str++;
	ft_checkflags(str, flags);
	ft_checkwidth(str, flags,  vl);
	
}
int		ft_printf(const char *str, ...)
{
	va_list vl;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(vl, str);
	if (str == NULL)
		return (-1);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!ft_parser(&str, vl,  &count))
				return(-1);
		}
		else
			count = count + write(1, str++, 1);
		
	}
	va_end(vl);
	return (count);
}