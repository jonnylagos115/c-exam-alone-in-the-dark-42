/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:33:50 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/13 15:51:38 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		hidenp(char *str1, char *str2)
{
	int i;

	i = -1;
	while (str2[++i])
	{
		if (str2[i] == *str1)
			str1++;
		if (!*str1)
			return (1);
	}
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		if (hidenp(ag[1], ag[2]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
