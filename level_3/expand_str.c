/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:30 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/06 16:51:25 by jlagos           ###   ########.fr       */
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
	while (str[i])
		i++;
	return (i);
}

void	expand_str(char *str)
{
	int i;
	int len;
	int spaces;

	i = 0;
	len = ft_strlen(str);
	spaces = 3;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[len] == ' ' || str[len] == '\t')
		len--;
	while (str[i] && i != len)
	{
		if (str[i] == ' ' && str[i + 1])
		{
			while (spaces--)
			{
				if (str[i] == ' ')
					ft_putchar(str[i++]);
				else
					ft_putchar(' ');
			}
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			spaces = 3;
		}
		if (str[i] != ' ')
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **ag)
{
	if (ac == 2)
		expand_str(ag[1]);
	write (1, "\n", 1);
	return (0);
}
