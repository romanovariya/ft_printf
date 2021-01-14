/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:25:20 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/04 14:54:17 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len(unsigned long num, int base)
{
	int len;

	len = 1;
	while ((num /= base) > 0)
		len++;
	return (len);
}

char	*ft_itoa_base(unsigned long num, int base)
{
	char	*res;
	int		len;
	char	*basic_str;

	basic_str = "0123456789abcdef";
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_get_len(num, base);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (num)
	{
		res[--len] = basic_str[num % base];
		num /= base;
	}
	return (res);
}

int		ft_ptr_minus(int *flag, char *s, int len)
{
	int	res;

	res = 0;
	res += ft_putstr_fd("0x", 1);
	res += ft_putstr_fd(s, 1);
	res += ft_print_width(' ', flag[2] - (len + 2));
	return (res);
}

int		ft_ptr(int *flag, char *s, int len)
{
	int res;

	res = 0;
	res += ft_print_width(' ', flag[2] - (len + 2));
	res += ft_putstr_fd("0x", 1);
	res += ft_putstr_fd(s, 1);
	return (res);
}

int		ft_print_ptr(int *flag, va_list vl)
{
	unsigned long int	num;
	char				*str;
	int					len;
	int					res;

	res = 0;
	num = va_arg(vl, unsigned long int);
	str = ft_itoa_base(num, 16);
	if (!str)
		return (0);
	if (!num && flag[3] != -1)
		*str = '\0';
	len = ft_strlen(str);
	if (flag[1] == 1)
		res = ft_ptr_minus(flag, str, len);
	else if (flag[1] == 0)
		res = ft_ptr(flag, str, len);
	free(str);
	return (res);
}
