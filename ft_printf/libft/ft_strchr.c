/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:49:15 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/16 01:07:11 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*src;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			src = (char *)&str[i];
			return (src);
		}
		i++;
	}
	if (str[i] == c)
	{
		src = (char *)&str[i];
		return (src);
	}
	return (NULL);
}
