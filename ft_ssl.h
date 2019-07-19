/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:54:46 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/18 17:58:18 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h> //DELETE

unsigned		fun_f(unsigned x, unsigned y, unsigned z);
unsigned		fun_g(unsigned x, unsigned y, unsigned z);
unsigned		fun_h(unsigned x, unsigned y, unsigned z);
unsigned		fun_i(unsigned x, unsigned y, unsigned z);

typedef struct	s_fmd5
{
	unsigned	hash[4];
	unsigned	bits[2];
}   			t_fmd5;

void			stage_one(t_fmd5 *fmd);
void			stage_two(t_fmd5 *fmd);
void			stage_three(t_fmd5 *fmd);
void			stage_four(t_fmd5 *fmd);
#endif
