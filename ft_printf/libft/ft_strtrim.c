/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:04:25 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/21 16:54:59 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	while (i < length)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int		ft_last(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	while (i < length)
	{
		if (ft_strchr(set, s1[length]) == 0)
			break ;
		length--;
	}
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		last;
	int		first;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	first = ft_first(s1, set);
	last = ft_last(s1, set);
	if (first >= last)
		return (ft_strdup(""));
	s2 = ft_substr(s1, first, last - first + 1);
	return (s2);
}
