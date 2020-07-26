/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 00:55:48 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/24 01:08:24 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastelem;

	lastelem = lst;
	if (lastelem == NULL)
		return (NULL);
	while (lastelem->next != NULL)
		lastelem = lastelem->next;
	return (lastelem);
}
