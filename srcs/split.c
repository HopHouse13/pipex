/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:21:00 by pbret             #+#    #+#             */
/*   Updated: 2025/01/12 11:06:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_strncpy(char *str1, char *str2, int nb)
{
	int	i;

	i = 0;
	while (i < nb && str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return ;
}

int	ft_count_words(char *str, char separator)
{
	int		i;
	int		word;
	int		flag;

	i = 0;
	word = 0;
	flag = 0;
	while (str[i])
	{
		while (str[i] == separator)
			i++;
		while (str[i] != separator && str[i])
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
		{
			flag = 0;
			word += 1;
		}
	}
	return (word);
}

char	**ft_initialisation_tab(char **tab, char *str, char separator)
{
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		start = i;
		while (str[i] && str[i] != separator)
			i++;
		if (i > start)
		{
			tab[j] = malloc(sizeof(char) * (i - start + 1));
			ft_strncpy(tab[j], &str[start], (i - start));
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char *str, char separator)
{
	char	**tab;
	int		nb_words;

	nb_words = ft_count_words(str, separator);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	ft_initialisation_tab(tab, str, separator);
	return (tab);
}