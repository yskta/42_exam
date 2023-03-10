//長さを測って半分入れ替える
/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

/*
nullで終わる文字列sを受け取り、sを逆順にした文字列を返します。
具体的には、sの先頭と末尾を交換し、その後先頭と末尾+1、
さらにその後先頭+1と末尾-1を交換するという操作を、
文字列の長さの半分だけ繰り返すことで、sを逆順にした文字列を作ります。
*/

char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}