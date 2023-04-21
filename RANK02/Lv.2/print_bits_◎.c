//OK
/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

/*
このコードは、1バイト（8ビット）の符号なし整数を受け取り、そのビットパターンをビットごとに出力する関数です。

具体的には、ビット演算子を使用して、最も左側のビットから最も右側のビットまでの各ビットを1つずつ取り出し、
ビットパターンを反転させながら順番に出力します。これを行うために、8から1までのループが使用されています。ループの各イテレーションで、octet変数のi番目のビットを取り出し、1または0の文字に変換して、標準出力に書き込みます。

ビット演算子の動作：
octetをiビット右にシフトします。
シフトされたoctetに1を論理積演算子(&)で適用します。この結果は、iビット目が1であるかどうかを表します。
1を'0'に加算することにより、1または0の文字に変換します。
*/

/*
右にシフトすることは、二進数表記された値のビットを指定された数だけ右にずらす操作です。
ビットを右に1つずつずらすと、値は2で割られ、小数部が切り捨てられます。
つまり、右にnビットシフトすると、元の値は2のn乗で割られることになります。

右シフトはビット単位での除算に使われ、左シフトはビット単位での乗算に使われます。
*/

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)//8から1までのループ
	{
		bit = (octet >> i & 1) + '0';//i番目のビットを取り出し、1または0の文字に変換
		write(1, &bit, 1);//左から順に出力
	}
}

/*
void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while (i != 0)
	{
		bit = (octet >> (i - 1) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
*/