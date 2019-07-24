/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:31:14 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/23 16:17:24 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			md5_init(t_fmd5 *fmd, char *str)
{
	fmd->hash[0] = 0x67452301;
	fmd->hash[1] = 0xEFCDAB89;
	fmd->hash[2] = 0x98BADCFE;
	fmd->hash[3] = 0x10325476;
	fmd->hash[4] = 0;
	fmd->hash[5] = 0;
	fmd->hash[6] = 0;
	fmd->hash[7] = 0;
	fmd->len = ft_strlen(str);
	fmd->bitlen = fmd->len * 8;
}

unsigned char	*md5_update(t_fmd5 *fmd, char *str)
{
	int				rem;
	int				size;
	int				i;
	unsigned char	*data;

	rem = fmd->len % 64;
	size = 0;
	if (rem < 56)
		size = fmd->len - rem + 64;
	else
		size = fmd->len - rem + 128;
	data = (unsigned char *)ft_strnew(16 * size * 4);
	data = (unsigned char *)ft_strncpy((char *)data, str, fmd->len);
	data[fmd->len] = 0x80;
	data = (unsigned char *)ft_strcat((char *)data,
		(char *)ft_memset(&data[fmd->len + 1], 0, size));
	i = 0;
	while (i < 8)
	{
		data[size - 8 + i] = (unsigned char)(fmd->bitlen >> i * 8);
		i++;
	}
	return (data);
}

unsigned		*md5_final(t_fmd5 *fmd)
{
	unsigned	*hash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	hash = (unsigned *)ft_strnew(16);
	while (i < 16)
	{
		hash[i] = (unsigned char)((fmd->hash[j]) & 0xff);
		hash[i + 1] = (unsigned char)((fmd->hash[j] >> 8) & 0xff);
		hash[i + 2] = (unsigned char)((fmd->hash[j] >> 16) & 0xff);
		hash[i + 3] = (unsigned char)((fmd->hash[j] >> 24) & 0xff);
		i = i + 4;
		j++;
	}
	return (hash);
}

void			put_hash(unsigned hash[], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%02x", hash[i]);
		i++;
	}
}

void	ft_md5(t_fmd5 *fmd, t_flg *flg, t_alp *al, char *arg)
{
	unsigned *x;

	md5_init(fmd, arg);
	x = (unsigned *)ft_strnew(16);
	x = (unsigned *)md5_update(fmd, arg);
	x[15] = 0;
	stage_one(fmd, al, x);
	if (flg->q == 0 && flg->r == 0)
	{
		ft_printf("MD5 (\"%s\") = ", arg);
		put_hash(md5_final(fmd), 16);
	}
	else if (flg->r)
	{
		put_hash(md5_final(fmd), 16);
		//printf(" \"%s\"", argv[flg.i]);
		ft_printf(" \"%s\" ", arg);
	}
	else if(flg->q)
		put_hash(md5_final(fmd), 16);
	printf("\n");
}
