/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:56:33 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/13 14:32:06 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int l;
	int g;
	int old_lcm1;
	int old_lcm2;
	int l_factor;
	int g_factor;

	old_lcm1 = 1;
	old_lcm2 = 2;
	l_factor = 2;
	g_factor = 2;
	if (!a || !b)
		return (0);
	if (a == b)
		return (a);
	if (a > b)
	{
		g = a;
		l = b;
	}
	else
	{
		l = a;
		g = b;
	}
	while (old_lcm1 != old_lcm2)
	{
		if (old_lcm1 < old_lcm2)
			old_lcm1 = l * l_factor++;
		else
			old_lcm2 = g * g_factor++;
	}
	return ((unsigned int)old_lcm1);
}
