//要確認
/*
strspn関数は、文字列の先頭から、指定された文字集合に含まれる文字の連続部分を数えます。つまり、文字列が指定された文字集合の中の文字で構成されている最初の連続部分の長さを返します。
一方、strcspn関数は、文字列の先頭から、指定された文字集合に含まれる文字のいずれも含まない連続部分を数えます。つまり、文字列が指定された文字集合の中の文字を含まない最初の連続部分の長さを返します。
*/
/*
strspn()関数は、2つのnullで終わる文字列sとcharsetを受け取り、
sの先頭からcharsetに含まれる文字の連続部分を調べ、その文字列配列の長さを返します。
具体的には、sの先頭から文字を1つずつチェックし、charsetに含まれる文字が連続して
出現する部分の長さを数えます。sの先頭から連続して出現する文字がcharsetに含まれなくなった時点で、その文字列配列の長さを返します。
*/

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)//acceptに含まれない文字が出てきたら
			break;
		++i;
	}
	return (i);
}