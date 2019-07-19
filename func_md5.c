/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:27:20 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/18 17:27:40 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned	fun_f(unsigned x, unsigned y, unsigned z)
{
	return ((x & y) | (~x & z));
}

unsigned	fun_g(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[3] & abcd[2]));
}

unsigned	fun_h(unsigned abcd[])
{
	return (abcd[1] ^ abcd[2] ^ abcd[3]);
}

unsigned	fun_i(unsigned abcd[])
{
	return (abcd[2] ^ (~abcd[3] | abcd[1]));
}
