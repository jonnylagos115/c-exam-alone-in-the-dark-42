/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:13:17 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/12 13:21:00 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		int		i;
		char 	*s1;
		char 	*s2;

		i = -1;
		s1 = ag[1];
		s2 = ag[2];
		while (s2[++i] && *s1)
		{
			if (s2[i] == *s1)
				s1++;
		}
		if (*s1)
			write(1, "0", 1);
		else
			write(1, "1", 1);
	}
	write(1, "\n", 1);
	return (0);
}
