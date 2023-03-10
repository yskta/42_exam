/*
具体的には、s1の先頭から文字を1つずつチェックし、s2に含まれている文字が現れた時点で、
その文字へのポインタを返します。s2に含まれている文字が見つからなかった場合は、NULLを返します。
*/
/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------
Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/
/*
strpbrk()関数は、2つのnullで終わる文字列s1とs2を受け取り、
s1内の最初のs2内のどれかの文字に一致する文字のポインタを返します。
具体的には、s1の先頭から文字を1つずつチェックし、s2に含まれている文字が現れた時点で、
その文字へのポインタを返します。s2に含まれている文字が見つからなかった場合は、NULLを返します。
*/

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
	
	if (!s1 || !s2)
	{
		return (0);
	}
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;	
	}
	return (0);
}