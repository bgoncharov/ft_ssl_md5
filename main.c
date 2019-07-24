/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:23:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/24 15:24:17 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	char *line;
	int fd;
	int i;

	i = 1;
	if (argc == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("%s\n", line);
			ft_strdel(&line);
		}
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				return (-1);
			else
			{
				while (get_next_line(fd, &line) > 0)
				{
					printf("%s\n", line);
					ft_strdel(&line);
				}
			}
			i++;
		}
	}
	//system("leaks a.out");
	return (0);
}