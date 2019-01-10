/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:57:35 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/09 18:46:22 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		len_word(char *str, int *i)
{
	int len;

	len = 0;
	while (str[*i] != ' ' && !str[*i])
	{
		len++;
		(*i)++;
	}	
	return (len);
}

int		num_of_str(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			if (str[i + 1] != ' ')
				len++;
		i++;
		if (!str[i])
			len++;
	}
	return (len);
}

void	free_malloc(char ***words, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (*words[i])
			free(*words[i]);
		i++;
	}
	free(*words);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *str;
		char **words;
		int i;
		int j;
		int k;
		int len;

		str = ag[1];
		i = 0;
		j = 0;
		k = 0;
		len = num_of_str(str);
		if (!(words = (char **)malloc(len * sizeof(char *))))
			return (-1);
		while (i < len)
		{
			if (!(words[i] = (char *)malloc((len_word(str, &j) * sizeof(char)) + 1)))
				free_malloc(&words, i);
			i++;
		}
		i = 0;
		j = 0;
		while (i < len)
		{
			while (str[k] != ' ' && str[k])
			{
				words[i][j++] = str[k++];
				if (str[k] == ' ')
					words[i][j++] = '\0';
			}
			j = 0;
			k++;
			i++;
		}
		while (len--)
		{
			ft_putstr(words[len]);
			if (len)
				write(1, " ", 1);
		}
		free_malloc(&words, len);
	}
	write(1, "\n", 1);
	return (0);
}
