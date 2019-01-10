/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:28:05 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/09 16:56:18 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <printf.h>

int		num_of_strings(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || !str[i])
		{
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			len++;
		}
		i++;
	}
	return (len);
}

int		ft_strlen(char *str, int *i)
{
	int len;

	len = 0;
	if (!str[*i])
		return (0);
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n' && str[*i])
	{
		len++;
		(*i)++;
	}
	return (len);
}

char	**ft_split(char *str)
{
	char 	**arr_str;
	int		i;
	int		j;
	int		k;
	int		arr_len;
	int		len;

	arr_len = num_of_strings(str) + 1;
	arr_str = (char **)malloc(arr_len * sizeof(char *));
	if (!arr_str)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	len = 0;
	while (i < arr_len)
		arr_str[i++] = (char *)malloc((ft_strlen(str, &len) * sizeof(char)) + 1);
	i = 0;
	while (i < arr_len)
	{
		while (str[k] != ' ' && str[k] != '\t' && str[k] != '\n' && str[k])
		{
			arr_str[i][j++] = str[k++];
			if (!str[k] || str[k] == ' ' || str[k] == '\n' || str[k] == '\t') 
				arr_str[i][j] = '\0';
		}
		j = 0;
		i++;
		while (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
			k++;
	}
	return (arr_str);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char **arr_str;
		int i;

		i = 0;
		arr_str = ft_split(ag[1]);
		while (i < 3)
			printf("%s\n", arr_str[i++]);
	}
	return (0);
}
