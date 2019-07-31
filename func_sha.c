/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:46:47 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/30 18:16:51 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned		rotr(unsigned x, unsigned n)
{
	return ((x >> n) | (x << (32 - n)));
}

unsigned long	r_64(unsigned long x, unsigned long n)
{
	return ((x >> n) | (x << (64 - n)));
}

unsigned		rev_bits(unsigned w)
{
	return ((w >> 24) | ((w & 0xFF0000) >> 8) |
	((w & 0xFF00) << 8) | (w << 24));
}

unsigned long	rev_bits_64(unsigned long w)
{
	return (((w & 0xFF00000000000000) >> 56)) |
	((w & 0x00FF000000000000) >> 40) |
	((w & 0x0000FF0000000000) >> 24) |
	((w & 0x000000FF00000000) >> 8) |
	((w & 0x00000000FF000000) << 8) |
	((w & 0x0000000000FF0000) << 24) |
	((w & 0x000000000000FF00) << 40) |
	((w & 0x00000000000000FF) << 56);
}
