/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:21:15 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/03 16:00:55 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	if (i > 19 || res >= 9223372036854775808UL)
		return (sign == 1 ? -1 : 0);
	return (sign * res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	length;
	int		sublen;
	size_t	i;

	length = ft_strlen(s);
	if (start > length)
		return (ft_strdup(""));
	if (start + len > length)
		len = (length - start);
	sublen = len + 1;
	substr = malloc(sizeof(char) * sublen);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
