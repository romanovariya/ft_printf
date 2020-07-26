/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:34:41 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/11 23:55:37 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *array, int c, size_t n)
{
	size_t		i;
	const char	*arr;

	i = 0;
	arr = (char *)array;
	while (i < n)
	{
		if (*(arr + i) == (char)c)
			return ((void*)(array + i));
		i++;
	}
	return (NULL);
}
