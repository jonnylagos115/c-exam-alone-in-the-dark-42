/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:39:15 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/17 17:51:22 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *lw = ag[1];
		int i = 0;
		int bookmark = 0;
		while (lw[i])
		{
			if (lw[i] == ' ' || lw[i] == '\t')
			{
				if (lw[i + 1] && lw[i + 1] != ' ' && lw[i + 1] != '\t')
					bookmark = i + 1;
			}
			i++;
		}
		while (lw[bookmark])
		{
			if (lw[bookmark] != ' ' && lw[bookmark] != '\t')
				write(1, &lw[bookmark], 1);
			bookmark++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
