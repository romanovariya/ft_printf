/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:17:30 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/20 18:10:24 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	while (*s1)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	*s3 = '\0';
	s3 -= (len1 + len2);
	return (s3);
}
