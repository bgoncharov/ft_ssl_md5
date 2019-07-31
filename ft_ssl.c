/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:50:59 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/30 19:53:53 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		check_err(t_flg *flg, char *arg, int fd)
{
	struct stat	statbuf;

	fstat(fd, &statbuf);
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_printf("%s: %s: Is a directory\n", g_name[flg->index], arg);
		return (-1);
	}
	if (fd < 0)
	{
		ft_printf("%s: ", g_name[flg->index]);
		ft_printf("%s: No such file or directory\n", arg);
	}
	return (fd);
}

int		file_parse(t_flg *flg, t_alp *al, char *arg)
{
	char		line[BLOCK_SIZE + 1];
	char		*str;
	char		*temp;
	int			ret;
	int			fd;

	fd = open(arg, O_RDONLY);
	if (check_err(flg, arg, fd) < 0)
		return (1);
	else
	{
		flg->fdname = arg;
		str = ft_strnew(1);
		while ((ret = read(fd, line, BLOCK_SIZE)) > 0)
		{
			line[ret] = '\0';
			temp = ft_strjoin(str, line);
			ft_strdel(&str);
			str = temp;
		}
		close(fd);
		g_disp[flg->index](flg, al, str);
		ft_strdel(&temp);
	}
	return (0);
}

void	stdin_parse(t_flg *flg, t_alp *al)
{
	char	line[BLOCK_SIZE + 1];
	char	*str;
	char	*temp;
	int		ret;

	flg->in = 1;
	str = ft_strnew(1);
	ret = read(0, line, BLOCK_SIZE);
	while (ret > 0)
	{
		line[ret] = '\0';
		temp = ft_strjoin(str, line);
		ft_strdel(&str);
		str = temp;
		ret = read(0, line, BLOCK_SIZE);
	}
	g_disp[flg->index](flg, al, str);
	ft_strdel(&temp);
	flg->in = 0;
}

void	str_parse(t_flg *flg, t_alp *al, char **argv)
{
	if (argv[flg->i])
	{
		g_disp[flg->index](flg, al, argv[flg->i]);
		flg->s = 0;
		flg->i++;
	}
	else
	{
		ft_printf("%s: option requires an argument -- s\n", g_name[flg->index]);
		ft_printf("usage: ./ft_ssl command [-pqr] [-s string] [files ...]\n");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_flg	flg;
	t_alp	al;

	if (argc < 2)
	{
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
		exit(1);
	}
	else
	{
		alg_parse(&flg, &al, argc, argv);
		if (flg.p || argc == 2)
			stdin_parse(&flg, &al);
		if (flg.s)
			str_parse(&flg, &al, argv);
		if (flg.fd)
		{
			while (flg.i < argc)
			{
				file_parse(&flg, &al, argv[flg.i]);
				flg.i++;
			}
		}
	}
	return (0);
}
