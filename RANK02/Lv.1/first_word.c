//確認済み
/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

#include <unistd.h>

int main (int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)
	{
		//タブとスペースはスキップ。 
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while ((argv[1][i] != 32 && argv[1][i] != 9) && argv[1][i])
		{
			write(1, &argv[1][i], 1);//write関数の引数はchar型のポインタなので、&をつける。 
			i++;
		}
	}
	write(1, "\n", 1);//改行を忘れない。
}
