/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:47:11 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/12 16:01:02 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int num)
{
	if (num > 9)
		ft_putnum(num / 10);
	ft_putchar(num % 10 + '0');
}

int		main(int ac, char **ag)
{
	if (ag[1])
	{
		int	num_ag;

		num_ag = 0;
		while (ac--)
			num_ag++;
		ft_putnum(num_ag - 1);
	}
	else
		write(1, "0", 1);
	write (1, "\n", 1);
	return (0);
}
