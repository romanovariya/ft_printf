/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:40:09 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/23 22:44:30 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_cwords(const char *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

size_t			ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**ft_delete(char **as, int i)
{
	while (i > 0)
		free(as[i--]);
	free(as);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char		**new;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (!s || !(new = (char**)malloc(sizeof(char*) * (ft_cwords(s, c) + 1))))
		return (NULL);
	while ((k = 0) || s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(new[j] = (char*)malloc(sizeof(char)
							* (ft_wordlen(s + i, c) + 1))))
				return (ft_delete(new, j));
			while (s[i] != '\0' && s[i] != c)
				new[j][k++] = s[i++];
			new[j++][k] = 0;
		}
	}
	new[j] = 0;
	return (new);
}
