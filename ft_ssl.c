/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:50:59 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/22 18:26:42 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				main(void)
{
	t_fmd5 fmd;
	char *str = "hello1234567890asashdadl";
	unsigned *x;

	md5_init(&fmd, str);
	x = (unsigned *)ft_strnew(16);
	x = (unsigned *)md5_update(&fmd, str);
	x[15] = 0;
	stage_one(&fmd, x);
	printf("MD5 (""%s"") = ", str);
	print_md5(md5_final(&fmd));
	printf("\n");
	return (0);
}
