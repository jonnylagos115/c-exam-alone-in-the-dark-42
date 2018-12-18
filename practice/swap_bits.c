/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:07:52 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 16:37:02 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

unsigned char	swap_bits(unsigned char octet)
{
	int 			i;
	int				halves;
	unsigned char 	bit;

	i = 8;
	halves = 3;
	bit = 0;
	while (i--)
	{
		bit = bit * 2 + (octet >> halves-- & 1);
		if (halves < 0)
			halves += 8; 
	}
	return (bit);
}

int		main(void)
{
	int n = 38;
	unsigned char ret;

	ret = swap_bits(n);
	printf("%d\n", ret);
	return (0);
}

