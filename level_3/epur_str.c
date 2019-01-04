/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:18:51 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/20 18:33:44 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *str;
		int i;
		int len;

		str = ag[1];
		i = 0;
		len = ft_strlen(str) - 1;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[len] == ' ' || str[len] == '\t')
			len--;
		while (i <= len)
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				if (str[i + 1] != ' ' && str[i + 1] != '\t')
					write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
