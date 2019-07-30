/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:39:32 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/29 17:04:32 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	put_sha(t_flg *flg, t_fsha *fsh, char *arg, void (*f_put)(t_fsha *))
{
	if (flg->in)
	{
		if (flg->p)
			ft_printf("%s", arg);
		(*f_put)(fsh);
	}
	else if (flg->q == 0 && flg->r == 0)
		put_sha_s(flg, fsh, arg, f_put);
	else if (flg->r)
	{
		(*f_put)(fsh);
		if (flg->s)
			ft_printf(" \"%s\"", arg);
		else
			ft_printf(" %s", flg->fdname);
	}
	else if (flg->q)
		(*f_put)(fsh);
	ft_putchar('\n');
}

void	ft_sha224(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha		fsh;
	unsigned	*w;
	char		*temp;

	temp = ft_strdup(arg);
	sha224_init(&fsh, arg, len);
	if (fsh.len >= BLOCK_SIZE - 8)
		arg = get_block_sha256(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned int) * 64);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	((char *)w)[fsh.round - 4] = (fsh.bitlen & 0xFF000000) >> 24;
	((char *)w)[fsh.round - 3] = (fsh.bitlen & 0x00FF0000) >> 16;
	((char *)w)[fsh.round - 2] = (fsh.bitlen & 0x0000FF00) >> 8;
	((char *)w)[fsh.round - 1] = (fsh.bitlen & 0x000000FF);
	sha_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, arg, put_hash_sha256);
}

void	ft_sha256(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha		fsh;
	unsigned	*w;
	char		*temp;

	temp = ft_strdup(arg);
	sha256_init(&fsh, arg, len);
	if (fsh.len >= BLOCK_SIZE - 8)
		arg = get_block_sha256(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned int) * 64);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	((char *)w)[fsh.round - 4] = (fsh.bitlen & 0xFF000000) >> 24;
	((char *)w)[fsh.round - 3] = (fsh.bitlen & 0x00FF0000) >> 16;
	((char *)w)[fsh.round - 2] = (fsh.bitlen & 0x0000FF00) >> 8;
	((char *)w)[fsh.round - 1] = (fsh.bitlen & 0x000000FF);
	sha_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, temp, put_hash_sha256);
}

void	ft_sha384(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha			fsh;
	unsigned long	*w;
	char			*temp;

	temp = ft_strdup(arg);
	sha384_init(&fsh, arg, len);
	if (fsh.len >= SIZE_SHA - 16)
		arg = get_block_sha512(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned long) * 80);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	sha512_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, arg, put_hash_sha512);
}

void	ft_sha512(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha			fsh;
	unsigned long	*w;
	char			*temp;

	temp = ft_strdup(arg);
	sha512_init(&fsh, arg, len);
	if (fsh.len >= SIZE_SHA - 16)
		arg = get_block_sha512(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned long) * 80);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	sha512_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, arg, put_hash_sha512);
}
