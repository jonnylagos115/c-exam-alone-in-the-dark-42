/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:40:35 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 17:19:40 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_doubles_1(char *str, char c, int i)
{
	int s;

	s = 0;
	while (s < i)
	{
		if (str[s] == c)
			return (1);
		s++;
	}
	return (0);
}

int		check_doubles_2(char *str, char *str2, int i)
{
	int s;

	s = 0;
	while (str[s])
	{
		if (str[s] == str2[i])
			return (1);
		s++;
	}
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		char 	*first_str;
		char	*second_str;
		int		i;

		first_str = ag[1];
		second_str = ag[2];
		i = 1;
		write(1, &(first_str[0]), 1);
		while (first_str[i])
		{
			if (!check_doubles_1(first_str, first_str[i], i))
				write(1, &first_str[i], 1);
			i++;
		}
		i = 0;
		while (second_str[i])
		{
			if (!check_doubles_1(second_str, second_str[i], i) && !check_doubles_2(first_str, second_str, i))
				write(1, &second_str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
