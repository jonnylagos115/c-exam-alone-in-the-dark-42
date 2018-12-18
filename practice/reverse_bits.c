/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:05:32 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 16:07:44 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char 	bit;

	i = 0;
	bit = 0;
	while (i < 8)
		bit = bit * 2 + (octet >> i++ & 1);
	return (bit);
}

int		main(void)
{
	int n = 65;
	unsigned char ret;

	ret = reverse_bits(n);
	printf("%d\n", ret);
	return (0);
}
