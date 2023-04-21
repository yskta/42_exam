#include "get_next_line.h"

char *get_next_line(int fd)
{
    if (BUFFER_SIZE <= 0)
        return (NULL);
    
    int     i = 0;
    int     rd = 0;
    char    character;
    char    *buffer = malloc(100000);

    //read関数の引数は、fd, バッファ, バッファサイズ
    //https://linuxjm.osdn.jp/html/LDP_man-pages/man2/read.2.html
    while (rd = read(fd, &character, 1) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break ;
    }
    buffer[i] =  '\0';
    if (rd == -1 || i == 0 || (buffer[i - 1] != '\n' && rd != 0))//!buffer[i - 1] && !rdは、最後の行が改行で終わっていない場合
        return (free(buffer), NULL);
    return (buffer);
}