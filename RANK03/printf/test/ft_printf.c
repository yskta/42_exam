/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:45 by yokitaga          #+#    #+#             */
/*   Updated: 2023/03/06 16:02:21 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_count(va_list ap, const char *fmt)
{
    size_t i;
    int    count;
    
    i = 0;
    count = 0;
    while (fmt[i] != '\0')
    {
        
    }

    return (count);
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int    count;

    va_start(ap, fmt);
    count= ft_count(ap, fmt);
    va_end(ap);
    return (count);
}