/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:45 by yokitaga          #+#    #+#             */
/*   Updated: 2023/03/11 08:43:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char *ft_itoa(int i)
{
    char *num;
    int   n;
    int   len;

    n = i;
    len = 0;
    while (n != 0)
    {
        n/=10;
        len++;
    }
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (num == NULL)
        return (NULL);
    num[len] = '\0';
    if (i < 0)
    {
        num[0] = '-';
        i *= -1;
    }
    while (len > 0)
    {
        num[len - 1] = i % 10 + '0';
        i /= 10;
        len--;
    }
    return (num);
}

int ft_count_and_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_count_and_putstr(char *s)
{
    if (s == NULL)
        s = "(null)";
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

int ft_count_and_putint(int i)
{
    int  add_count;
    char *num;

    num = ft_itoa(i);
    add_count = ft_count_and_putstr(num);
    free(num);
    return (add_count);
}

int ft_hex_len(size_t pointer)
{
    int len;
    len = 0;
    while (pointer != 0)
    {
        pointer /= 16;
        len++;
    }
    return (len);
}

char *ft_showhex_pointer(size_t pointer_value)
{
    char *num;
    int  len;

    len = 0;
    if (pointer_value == 0)
        return (ft_strdup("0"));
    len = ft_hex_plen(pointer_value);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (num == NULL)
        return (NULL);
    num[len] = '\0';
    while (len > 0)
    {
        if (pointer_value % 16 < 10)
            num[len - 1] = '0' + pointer_value % 16;
        else
            num[len - 1] = 'a' + (pointer_value % 16 - 10);
        pointer_value /= 16;
    }
    return (num);
}

int ft_count_and_putptr(size_t pointer_value)
{
    int  add_count;
    char *p;

    add_count = 0;
    add_count += ft_count_and_putstr("0x");
    p = ft_showhex_pointer(pointer_value);
    add_count += ft_count_and_putstr(p);
    return (add_count);
}

char *ft_showhex(unsigned int u, char fmt)
{
    char *num;
    int len;

    len = ft_hex_len(u);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (num == NULL)
        return (NULL);
    num[len] = '\0';
    while (len > 0)
    {
        if (u % 16 < 10)
            num[len - 1] = '0' + u % 16;
        else if (fmt == 'x')
            num[len - 1] = 'a' + (u % 16 - 10);
        else if (fmt == 'X')
            num[len - 1] = 'A' + (u % 16 - 10);
        u /= 16;
        len--;
    }
    return (num);
}
ft_count_and_puthex(unsigned int u, char fmt)
{
    int add_count;
    char *num;

    add_count = 0;
    num = ft_showhex(u, fmt);
    add_count = ft_count_and_putstr(num);
    free(num);
    return (add_count);
}

int ft_judge_and_output(va_list ap, char fmt)
{
    int add_count;

    add_count = 0;

    if (fmt == 'c')
        add_count = ft_count_and_putchat((char)va_arg(ap, int));
    else if (fmt == 's')
        add_count = ft_count_and_putstr((char *)va_arg(ap, char *));
    else if (fmt == 'd' || fmt == 'i')
        add_count = ft_count_and_putint((int)va_arg(ap, int));
    else if (fmt == 'p')
        add_count = ft_count_and_putptr((size_t)va_arg(ap, void *));
    else if (fmt == 'x' || fmt == 'X')
        add_count = ft_count_and_puthex((unsigned int)va_arg(ap, unsigned int), fmt);
    return (add_count);
}

int ft_count(char *fmt, va_list ap)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (fmt[i] != '\0')
    {
        if (fmt[i] != '%')
        {
            count ++;
            write(1, &fmt[i], 1);
        }
        else if (fmt[i] == '%')
        {
            count += ft_judge_and_output(ap, fmt[i+1]);
            i++;
        }
        i++;
    }

    return (count);
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    
    int count;

    count = 0;
    va_start(ap, fmt);
    count = ft_count(fmt, ap);
    va_end(ap);
    return (count);
}