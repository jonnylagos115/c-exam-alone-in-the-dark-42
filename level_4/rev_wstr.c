/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:57:35 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/27 15:59:50 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		write(1, &str[i++], 1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	rev_wstr(char *str)
{
	char 	*temp;
	int 	len;

	len = ft_strlen(str) - 1;
	while (len--)
	{
		if(str[len] == ' ')
		{
			temp = str + (len + 1);
			ft_putstr(temp);
			write(1, " ", 1);
		}
	}
	len = 0;
	while (str[len] != ' ' && str[len])
		write(1, &str[len++], 1);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *str;

		str = ag[1];
		rev_wstr(str);
	}
	write(1, "\n", 1);
	return (0);
}
