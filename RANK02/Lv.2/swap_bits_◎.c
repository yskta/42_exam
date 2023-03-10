//OK
/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/
unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));//octetの左右の4ビットを入れ替える
}

/*
| = OR
octet = 0b10101010
(octet >> 4) | (octet << 4)
= (0b1010) | (0b10100000)
= 0b10101000
*/

/*
a = 0b10101010
b = 0b11110000
a | b = 0b11111010
*/
