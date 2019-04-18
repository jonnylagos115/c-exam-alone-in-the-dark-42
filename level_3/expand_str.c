/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:46:35 by jlagos            #+#    #+#             */
/*   Updated: 2019/04/18 13:37:31 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print_spaces(char *str, int *index)
{
	int		i;

	i = -1;
	while (str[*index] == ' ' || str[*index] == '\t')
			(*index)++;
	if (str[*index])
		while (++i < 3)
			write(1, " ", 1);
}

int			main(int ac, char **ag)
{
	if (ac == 2)
	{
		char	*str;
		int		i;

		str = ag[1];
		i = 0;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
				print_spaces(str, &i);
			if (str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
