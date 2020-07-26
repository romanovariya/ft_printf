/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:25:04 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/21 23:54:47 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int x)
{
	int	i;

	i = 0;
	if (x < 0)
		x = -1 * x;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		i++;
		x /= 10;
	}
	return (i);
}

int			ft_sign(int c)
{
	if (c < 0)
		return (2);
	else
		return (1);
}

char		*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	num;

	num = n;
	len = ft_intlen(num) + ft_sign(num);
	s = (char *)malloc(len);
	if (!s)
		return (NULL);
	if (num == 0)
		s[0] = '0';
	if (num < 0)
	{
		s[0] = '-';
		num = -1 * num;
	}
	while (num)
	{
		len--;
		s[len - 1] = (num % 10) + '0';
		num = num / 10;
	}
	len = ft_intlen(n) + ft_sign(n);
	s[len - 1] = '\0';
	return (s);
}
