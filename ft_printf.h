/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 00:14:31 by mbabette          #+#    #+#             */
/*   Updated: 2020/08/03 15:57:31 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_parser(const char **str, va_list vl, int *count);
void	ft_initflags(int *flag);
void	ft_checkwidth(int *flag, const char **str, va_list vl);
int		ft_checktype(int *flag, const char **str, va_list vl, int *count);
void	ft_checkprecision(int *flag, const char **str, va_list vl);
void	ft_checkflags(const char **str, int *flag);
int		ft_printchar(int *flag, va_list vl);
int		ft_printstr(int *flag, va_list vl);
char	*ft_cutstr(int *flag, char *str);
int		ft_print_width(char c, int width);
int		ft_printnum(int *flag, va_list vl);
int		ft_number_len(int number);
int		ft_num_prec(int num, int len, int *flag);
int		ft_num_zero(int num, int len, int *flag);
int		ft_num_min(int num, int len, int *flag);
int		ft_num_w(int num, int len, int *flag);
int		ft_print_nbr(int n);
int		ft_print_chars(char c, int width);
int		ft_printunsigned(int *flag, va_list vl);
int		ft_print_upx(size_t number, int reg, size_t base);
int		ft_unsigned_prec(size_t num, int len, int *flag);
int		ft_unsigned_zero(size_t num, int len, int *flag);
int		ft_unsigned_min(size_t num, int len, int *flag);
int		ft_unsigned_w(size_t num, int len, int *flag);
int		ft_pu_len(size_t num, int base, char c);
int		ft_print_ptr(int *flag, va_list vl);
int		ft_ptr(int *flag, char *s, int len);
int		ft_ptr_minus(int *flag, char *s, int len);
char	*ft_itoa_base(unsigned long num, int base);
int		ft_get_len(unsigned long num, int base);
int		ft_print_width(char c, int width);
int		ft_printhex(int *flag, va_list vl, char c);
int		ft_hex_prec(size_t num, int len, int *flag, int registr);
int		ft_hex_min(size_t num, int len, int *flag, int registr);
int		ft_hex_zero(size_t num, int len, int *flag, int registr);
int		ft_hex_w(size_t num, int len, int *flag, int registr);
int		ft_print_upx(size_t number, int reg, size_t base);
int		ft_printpercent(int *flag);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
