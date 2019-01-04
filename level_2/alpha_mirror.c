/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:51:58 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 18:21:36 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *str = ag[1];
		char alpha_m;
		int i = 0;

		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				alpha_m = ('z' - str[i]) + 'a';
				write(1, &alpha_m, 1);
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				alpha_m = ('Z' - str[i]) + 'A';
				write(1, &alpha_m, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
