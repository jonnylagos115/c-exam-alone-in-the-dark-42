/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:49:05 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/06 16:56:23 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	print_rstr_cap(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i + 1] == ' ' || !str[i + 1]) //checks to see if last letter is uppercase
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z') //checks to see if letters before last are lowercase
				str[i] += 32;
		}
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **ag)
{
	if (ac >= 2)
	{
		int i;

		i = 1;
		while (i < ac)
		{
			print_rstr_cap(ag[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
