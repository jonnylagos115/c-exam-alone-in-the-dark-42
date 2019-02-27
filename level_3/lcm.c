/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:56:33 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/27 14:17:13 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int 	multiple1;
	unsigned int 	multiple2;
	unsigned int	i;
	unsigned int	j;

	multiple1 = a;
	multiple2 = b;
	i = 2;
	j = 2;
	if (!a || !b)
		return (0);
	if (a == b)
		return (a);
	while (multiple1 != multiple2)
	{
		if (multiple1 < multiple2)
		{
			multiple1 = i * a;
			i++;
		}
		else if (multiple1 > multiple2)
		{
			multiple2 = j * b;
			j++;
		}
	}
	return (multiple1);
}
