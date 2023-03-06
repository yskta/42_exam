/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:51 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/27 18:46:54 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t			ft_strlen(const char *str);
int				cntdigit(long int n);
void			convert_int_to_char(long int n, char *num, int n_digit);
char			*ft_itoa(int n);
int				ucntdigit(unsigned int n);
void			convert_uint_to_char(unsigned int n, char *num, int n_digit);
char			*ft_unsigneditoa(unsigned int n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
unsigned int	ft_hex_len(unsigned int u);
char			*ft_showhex(unsigned int u, int fmt);
char			*ft_showhex_forull(unsigned long long pointer);
unsigned int	ft_hex_plen(unsigned long long pointer);
int				ft_count_and_putchar(char c);
int				ft_count_and_putstr(char *s);
int				ft_count_and_putint(int i);
int				ft_cntputunsigned(unsigned int u);
int				ft_cntputhexa(unsigned int u, int fmt);
int				ft_cntputpointer(unsigned long long pointer);
int				ft_judge_and_output(va_list ap, int fmt);
int				ft_count(va_list ap, const char *fmt);
int				ft_printf(const char *fmt, ...);

#endif
