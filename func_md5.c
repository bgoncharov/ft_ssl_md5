#include "ft_ssl.h"

unsigned funF(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]));
}

unsigned funG(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[3] & abcd[2]));
}

unsigned funH(unsigned abcd[])
{
	return (abcd[1] ^ abcd[2] ^ abcd[3]);
}

unsigned funI(unsigned abcd[])
{
	return (abcd[2] ^ (~abcd[3] | abcd[1]));
}