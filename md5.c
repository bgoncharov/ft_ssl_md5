/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:31:14 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/25 15:56:58 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			md5_init(t_fmd5 *fmd, char *str, int len)
{
	fmd->hash[0] = 0x67452301;
	fmd->hash[1] = 0xEFCDAB89;
	fmd->hash[2] = 0x98BADCFE;
	fmd->hash[3] = 0x10325476;
	fmd->hash[4] = 0;
	fmd->hash[5] = 0;
	fmd->hash[6] = 0;
	fmd->hash[7] = 0;
	if (len)
		fmd->len = len;
	else
		fmd->len = ft_strlen(str);
	fmd->bitlen = fmd->len * 8;
}

char			*get_block_md5(t_fmd5 *fmd, t_alp *al, char *arg)
{
	unsigned	*x;

	while (fmd->len >= BLOCK_SIZE - 8)
	{
		if (fmd->len < BLOCK_SIZE)
		{
			x = ft_memalloc(sizeof(unsigned int) * 64);
			ft_memset(x, 0, sizeof(x));
			ft_memcpy(x, arg, fmd->len);
			((char *)x)[fmd->len] = 0x80;
			stage_one(fmd, al, x);
			arg = arg + fmd->len;
			fmd->len = -1;
			free(x);
		}
		else
		{
			stage_one(fmd, al, (unsigned *)arg);
			arg = arg + BLOCK_SIZE;
			fmd->len -= BLOCK_SIZE;
		}
	}
	return (arg);
}

unsigned		*md5_update(t_fmd5 *fmd, unsigned *x)
{
	((char *)x)[BLOCK_SIZE - 5] = (fmd->bitlen & 0xFF000000) >> 24;
	((char *)x)[BLOCK_SIZE - 6] = (fmd->bitlen & 0x00FF0000) >> 16;
	((char *)x)[BLOCK_SIZE - 7] = (fmd->bitlen & 0x0000FF00) >> 8;
	((char *)x)[BLOCK_SIZE - 8] = (fmd->bitlen & 0x000000FF);
	return (x);
}

unsigned		*md5_final(t_fmd5 *fmd)
{
	unsigned	*hash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	hash = ft_memalloc(sizeof(unsigned int) * 16);
	while (i < 16)
	{
		hash[i] = (unsigned char)((fmd->hash[j]) & 0xFF);
		hash[i + 1] = (unsigned char)((fmd->hash[j] >> 8) & 0xFF);
		hash[i + 2] = (unsigned char)((fmd->hash[j] >> 16) & 0xFF);
		hash[i + 3] = (unsigned char)((fmd->hash[j] >> 24) & 0xFF);
		i = i + 4;
		j++;
	}
	return (hash);
}

void			ft_md5(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fmd5		fmd;
	unsigned	*x;

	md5_init(&fmd, arg, len);
	if (fmd.len >= BLOCK_SIZE - 8)
		arg = get_block_md5(&fmd, al, arg);
	printf("\nstr = %s\n", arg);
	x = ft_memalloc(sizeof(unsigned int) * 64);
	ft_memset(x, 0, sizeof(x));
	if (fmd.len >= 0)
	{
		ft_memcpy(x, arg, fmd.len);
		((char *)x)[fmd.len] = 0x80;
	}
	md5_update(&fmd, x);
	stage_one(&fmd, al, x);
	free(x);
	put_md5(flg, &fmd, arg);
}
