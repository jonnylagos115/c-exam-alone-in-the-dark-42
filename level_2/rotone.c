/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:53:20 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/13 15:01:32 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char 	*str;
		int		i;

		str = ag[1];
		i = -1;
		while (str[++i])
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				if (str[i] == 'z' || str[i] == 'Z')
					str[i] -= 25;
				else
					str[i]++;
			}
			write(1, &str[i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
