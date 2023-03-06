/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:26 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/27 18:46:28 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	cntdigit(long int n)
{
	if (n < 0)
		return (1 + cntdigit(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + cntdigit(n / 10));
}

void	convert_int_to_char(long int n, char *num, int n_digit)
{
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		convert_int_to_char((n / 10), num, (n_digit - 1));
	num[n_digit] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		n_digit;

	n_digit = cntdigit((long int)n);
	num = (char *)malloc(sizeof(char) * (n_digit + 1));
	if (num == NULL)
		return (NULL);
	num[n_digit] = '\0';
	n_digit -= 1;
	convert_int_to_char((long int)n, num, n_digit);
	return (num);
}
