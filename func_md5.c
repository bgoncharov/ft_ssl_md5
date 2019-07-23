/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:27:20 by bogoncha          #+#    #+#             */
/*   Updated: 2019/07/22 18:25:41 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned	fun_f(unsigned x, unsigned y, unsigned z)
{
	return ((x & y) | (~x & z));
}

unsigned	fun_g(unsigned x, unsigned y, unsigned z)
{
	return ((x & z) | (~z & y));
}

unsigned	fun_h(unsigned x, unsigned y, unsigned z)
{
	return (x ^ y ^ z);
}

unsigned	fun_i(unsigned x, unsigned y, unsigned z)
{
	return (y ^ (~z | x));
}
