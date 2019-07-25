/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:49:09 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/25 16:25:02 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			put_md5(t_flg *flg, t_fmd5 *fmd, char *arg)
{
	if (flg->q == 0 && flg->r == 0)
	{
		if (flg->fd)
			ft_printf("MD5(%s)= ", flg->fdname);
		else
			ft_printf("MD5(\"%s\")= ", arg);
		put_hash(md5_final(fmd));
	}
	else if (flg->r)
	{
		put_hash(md5_final(fmd));
		ft_printf(" \"%s\"", arg);
	}
	else if (flg->q)
		put_hash(md5_final(fmd));
	ft_putchar('\n');
}

void			put_hash(unsigned *hash)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

void		put_sha(t_flg *flg, t_fsha *fsh, char *arg)
{
	if (flg->q == 0 && flg->r == 0)
	{
		if (flg->fd)
			ft_printf("SHA256(%s)= ", flg->fdname);
		else
			ft_printf("SHA256(\"%s\")= ", arg);
		put_hash_sha(flg, fsh);
	}
	else if (flg->r)
	{
		put_hash_sha(flg, fsh);
		ft_printf(" \"%s\"", arg);
	}
	else if (flg->q)
		put_hash_sha(flg, fsh);
	ft_putchar('\n');
}

void		put_hash_sha(t_flg *flg, t_fsha *fsh)
{
	int i;

	i = 0;
	if (!ft_strcmp(flg->alg, "sha256"))
	{
		while (i < 8)
		{
			ft_printf("%08x", fsh->hash[i]);
			i++;
		}
	}
	else
	{
		while (i < 8)
		{
			ft_printf("%016lx", fsh->hash[i]);
			i++;
		}
	}
}
