/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:20:55 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 17:35:17 by jlagos           ###   ########.fr       */
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

int		check_both_strings(char *str2, char c)
{
	int s;

	s = 0;
	while (str2[s])
	{
		if (str2[s] == c)
			return (0);
		s++;
	}
	return (1);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		char *first_str;
		char *second_str;
		int i;

		first_str = ag[1];
		second_str = ag[2];
		i = 0;
		while (first_str[i])
		{
			if (!check_doubles_1(first_str, first_str[i], i) && !check_both_strings(second_str, first_str[i]))
				write(1, &first_str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
