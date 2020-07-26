/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:00:49 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/25 22:19:13 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char			*temps;
	unsigned int	sum;

	sum = num * size;
	temps = (char *)malloc(sum);
	if (!temps)
		return (NULL);
	ft_bzero(temps, sum);
	return (temps);
}
