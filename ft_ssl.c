/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:50:59 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/25 15:58:00 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	parse_file(t_flg *flg, t_alp *al, char *arg)
{
	char	*line;
	char	*str;
	int		fd;
	int		len;

	len = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		if (errno == 21)
			ft_printf("%s: %s: Is a directory\n", flg->alg, arg);
		else
			ft_printf("%s: %s: No such file or directory\n", flg->alg, arg);
		exit(1);
	}
	else
	{
		flg->fdname = arg;
		str = ft_strdup("");
		line = ft_strnew(BLOCK_SIZE);
		while ((len = read(fd, line, BLOCK_SIZE)) > 0)
		{
			line[len] = '\0';
			str = ft_strjoin(str, line);
			ft_strdel(&line);
			if (len == BLOCK_SIZE)
				line = ft_strnew(BLOCK_SIZE);
		}
		if (line)
			ft_strdel(&line);
		close(fd);
		if (!ft_strcmp(flg->alg, "md5"))
			ft_md5(flg, al, str, len);
		else
			ft_sha(flg, al, str, len);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_flg	flg;
	t_alp	al;

	if (argc < 2)
	{
		ft_putstr("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
		exit(1);
	}
	else
	{
		parse_alg(&flg, argv[1]);
		flag_init(&flg, argv[2]);
		parse_flag(&flg, argv[3]);
		alphabet_init(&al);
		if (flg.s && argv[flg.i])
		{
			if (!ft_strcmp(flg.alg, "md5"))
				ft_md5(&flg, &al, argv[flg.i], 0);
			else
				ft_sha(&flg, &al, argv[flg.i], 0);
		}
		else if (flg.s && !argv[flg.i])
		{
			ft_printf("%s: option requires an argument -- s\n", flg.alg);
			ft_printf("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
		else if (flg.fd)
			parse_file(&flg, &al, argv[flg.i]);
		else
		{
			ft_printf("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
	}
	//while (1);
	return (0);
}
