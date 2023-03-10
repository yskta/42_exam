/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:44:51 by yokitaga          #+#    #+#             */
/*   Updated: 2023/03/10 22:51:22 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (c == '\0')
        return (s);
    return (NULL);
}

int ft_strlen(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_free(char *s)
{
    free(s);
    return (NULL);
}

char *ft_strjoin_with_free(char *s1, char *s2)
{
    char *result;
    int  len;
    int  i;
    int  j;

    if (s1 == NULL)
        return (ft_strdup(s2));
    if (s2 == NULL)
        return (ft_strdup(s1));
    result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (result == NULL)
        return (ft_free(s1));
    i = 0;
    while (i < ft_strlen(s1))
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < ft_strlen(s2))
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    free(s1);
    return (result);    
}

char *read_and_get_save(int fd, char *save)
{
    char *read_result;
    ssize_t read_size;

    read_result = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (read_result == NULL)
        return (NULL);
    read_size = 1;
    while (read_size != 0 && ft_strchr(save, '\n') == NULL)
    {
        read_size = read(fd, read_result, BUFFER_SIZE);
        if (read_size == -1)
        {
            free(read_result);
            return (ft_free(save));
        }
        read_result[read_size] = '\0';
        save = ft_strjoin_with_free(save, read_result);
        if (save == NULL)
            break;
    }
    free(read_result);
    return (save);   
}

char *get_output_line(char *save)
{
    char *output_line;
    int  i;
    i = 0;
    if (save[i] == '\0')//重要
        return (NULL);
    while (save[i] != '\0' || save[i] != '\n')
        i++;
    output_line = (char *)malloc(sizeof(char) * (i + 2));
    if (output_line == NULL)
        return (ft_free(save));
    i = 0;
    while (save[i] != '\0' && save[i] != '\n')
	{
		output_line[i] = save[i];
		i++;
	}
    if (save[i] == '\n')
    {
        output_line[i] = save[i];
        i++;
    }
    output_line[i] = '\0';
    return (output_line);
}

char *get_next_save(char *save)
{
    char *next_save;
    int  save_len;
    int  i;
    int  j;

    i = 0;
    while (save[i] != '\0' && save[i] != '\n')
        i++;
    if (save[i] == '\0')
        return (ft_free(save));
    next_save = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
    if (next_save == NULL)
        return (ft_free(save));
    i++;
	j = 0;
	while (save[i] != '\0')
    {
		next_save[j] = save[i];
        j++;
        i++;
    }
	next_save[j] = '\0';
    free(save);
    return (next_save);
}

char *get_next_line(int fd)
{
    static char *save;
    char        *output_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (save == NULL)
    {
        save = (char *)malloc(sizeof(char) * 1);
        if (save == NULL)
            return (NULL);
        *save = '\0';
    }
    save = read_and_get_save(fd, save);
    if (save == NULL)
        return (NULL);
    output_line = get_output_line(save);
    save = get_next_save(save);
    return (output_line);
}