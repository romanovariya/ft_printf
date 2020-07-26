/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 00:36:26 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/24 01:07:12 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int				count;
	struct s_list	*temp;

	count = 0;
	temp = list;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
