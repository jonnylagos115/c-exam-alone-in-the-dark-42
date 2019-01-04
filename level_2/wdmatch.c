/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:05:03 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/20 14:27:15 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		char *str1;
		char *temp_s1;
		char *str2;

		str1 = ag[1];
		temp_s1 = ag[1];
		str2 = ag[2];
		while (*str2 && *str1)
		{
			if (*str1 == *str2)
				str1++;
			str2++;
		}
		if (!*str1)
			ft_putstr(temp_s1);
	}
	write(1, "\n", 1);
	return (0);
}
