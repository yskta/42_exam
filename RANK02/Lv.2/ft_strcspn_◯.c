//簡単だけど要確認
//strcspn：s2の文字列のうち1文字でも一致した場合、その文字のインデックスを返す
/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------
Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/
#include <stdio.h>
//#include <string.h>
/*
strcspn()関数は、2つのnullで終わる文字列s1とs2を受け取り、s1内の最初の文字列配列のインデックスを計算します。
この文字列は、s2内のいずれの文字も含まれていません。
具体的には、s1の先頭から文字を1つずつチェックし、
s2に含まれている文字が最初に現れた時点で、
その文字の文字列配列のインデックスを返します。
s2に含まれている文字が見つからなかった場合は、s1の長さを返します。
*/
size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        j = 0;
        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}