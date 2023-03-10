//OK。mallocの使えるようにstdlib.hをインクルードすること。
/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
#include  <stdlib.h>//malloc用

size_t ft_strlen(char *str)
{
    size_t len = 0;
    while (*str++)
        len++;
    return (len);
}

char    *ft_strdup(char *src)
{
    char *dup;

    dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (dup == NULL)
        return (NULL);
    while (*src != '\0')
        *dup++ = *src++;
    *dup = '\0';
    return (dup - ft_strlen(src));
}