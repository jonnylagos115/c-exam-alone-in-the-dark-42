/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:20:07 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/05 17:41:12 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <printf.h>

static int		num_of_strings(char const *s, int *x)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		(*x)++;
	}
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			if (s[i + 1] != ' ' && s[i + 1] != '\t' && s[i + 1] != '\n')
				len++;
		i++;
		if (s[i] == '\0' && (s[i - 1] != ' ' && s[i - 1] != '\t' && s[i - 1] != '\n'))
			len++;
	}
	return (len);
}

static int		len_str(char **s)
{
	int len;

	len = 0;
	while (**s == ' ' || **s == '\t' || **s == '\n')
		(*s)++;
	if (**s == '\0')
		return (1);
	while (**s != ' ' && **s == '\t' && **s == '\n')
	{
		len++;
		(*s)++;
	}
	return (len);
}

static void	assign_char(char **str, char const *s, int *read_s)
{
	int j;

	j = 0;
	while (s[*read_s] != ' ' && s[*read_s] != '\t' && s[*read_s] != '\n')
	{
		(*str)[j++] = s[*read_s];
		(*read_s)++;
	}
	(*str)[j] = '\0';
	while (s[*read_s] == ' ' || s[*read_s] == '\t' || s[*read_s] == '\n')
		(*read_s)++;
}

char 	**ft_split(char *str)
{
	char	**strsplit;
	char	*temp;
	int		read_s;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	temp = str;
	read_s = 0;
	i = -1;
	len = num_of_strings(str, &read_s);
	if (!(strsplit = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while (++i < len + 1)
		strsplit[i] = (char *)malloc(len_str(&temp) * sizeof(char));
	i = -1;
	while (++i < len)
		assign_char(&strsplit[i], str, &read_s);
	strsplit[i] = NULL;
	return (strsplit);

}

int		main(int ac, char **ag)
{
	if (ac == 1)
	{
		char **arr_str;
		int i;

		i = 0;
		arr_str = ft_split(ag[1]);
		while (i < 2)
			printf("%s\n", arr_str[i++]);
	}
	return (0);
}
