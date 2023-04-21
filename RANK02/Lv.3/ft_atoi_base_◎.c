//大文字を小文字に変換する関数。
char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
    
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';//0~9 char cと比較
	else
		max_digit = 'a' + (digits_in_base - 10);//a~f 10~15

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (c - 'a' + 10);//10~15。16進数→10進数
	else
		return (-1);
}

//int(10進数)に変換する関数。
int ft_atoi_base(const char *str, int str_base)//str_baseは基数
{
	int result = 0;
	int sign = 1;
	int digit;//各桁の数字

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;//一個位を上げる
		result = result + (digit * sign);
		++str;
	}
	return (result);
}