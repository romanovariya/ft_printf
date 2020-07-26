/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:46:39 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/16 01:43:41 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	res = 0;
	len = ft_strlen((char *)str);
	while (i != len && str)
	{
		if (*(str + i) == (char)c)
			res = (char *)(str + i);
		i++;
	}
	if (*(str + i) == (char)c)
		res = (char *)(str + i);
	return (res);
}
