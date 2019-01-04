/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:13:17 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/03 14:34:17 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_hidden(char *s1, char *s2)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (s2[i] && s1[j])
	{
		if (s1[j] == s2[i])
		{
			j++;
			if (!s1[j])
				return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		char	*s1;
		char	*s2;
		int		i;

		s1 = ag[1];
		s2 = ag[2];
		i = 0;
		if (is_hidden(s1, s2))
				write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
