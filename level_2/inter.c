/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:03:59 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/13 15:32:02 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_for_doubles1(char *str, char c, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (str[i] == c)
			return (0);
	return (1);
}

int		check_for_doubles2(char *str2, char c)
{
	int i;

	i = -1;
	while (str2[++i])
		if (str2[i] == c)
			return (1);
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		char 	*str1;
		char 	*str2;
		int		i;

		str1 = ag[1];
		str2 = ag[2];
		i = -1;
		while (str1[++i])
			if (check_for_doubles1(str1, str1[i], i) && check_for_doubles2(str2, str1[i]))
				write(1, &str1[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
