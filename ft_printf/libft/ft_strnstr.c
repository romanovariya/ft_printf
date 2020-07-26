/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:39:12 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/16 23:10:12 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t size)
{
	size_t	slen;

	slen = ft_strlen(small);
	if (slen == 0)
		return ((char *)big);
	if (size + 1 < slen)
		return (NULL);
	while (*big != '\0' && size >= slen)
	{
		if (ft_strncmp(big, small, slen) == 0)
			return ((char *)big);
		big++;
		size--;
	}
	return (NULL);
}
