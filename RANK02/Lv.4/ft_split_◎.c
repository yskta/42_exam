#include <stdlib.h>
//今回cは' ' (スペース)または'\t' (タブ)または'\n' (改行)。

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))//スペース、タブ、改行を飛ばす
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}
/*
static size_t	ft_cnt(const char *s, char c);
static char		**ft_split_str(const char *s, char c, char **split_str, size_t split_cnt);
static char		**ft_free(char **list);

static size_t	ft_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*(char *)s == c)//cの場合はスキップ
			s++;
		else//cでない場合はカウント
		{
			while (*s != '\0' && *(char *)s != c)//cでない間はスキップ
				s++;
			cnt++;
		}
	}
	return (cnt);
}

char	**ft_split_str(const char *s, char c, \
		char **split_str, size_t split_cnt)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i] != '\0' && index < split_cnt)
	{
		if (s[i] != c)
		{
			j = i + 1;
			while (s[j] != '\0' && s[j] != c)
				j++;
			split_str[index] = ft_substr(s, i, j - i);
			if (split_str[index] == NULL)
				return (ft_free(split_str));
			index++;
			i = j + 1;
		}
		if (s[i] == c)
			i++;
	}
	split_str[split_cnt] = NULL;
	return (split_str);
}

static char	**ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	size_t	split_cnt;

	if (s == NULL)
		return (NULL);
	split_cnt = ft_cnt(s, c);
	split_str = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (split_str == NULL)
		return (NULL);
	split_str = ft_split_str(s, c, split_str, split_cnt);
	return (split_str);
}
*/