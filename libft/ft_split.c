/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:42:37 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:59:07 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cal_wordlen(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_cal_word(const char *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_all_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	str = (char **)malloc(sizeof(char *) * (ft_cal_word(s, c) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[++i] = (char *)malloc(sizeof(char) * ft_cal_wordlen(s, c) + 1);
			if (!str[i])
				return (ft_all_free(str));
			j = 0;
			while (*s && *s != c)
				str[i][j++] = *s++;
			str[i][j] = '\0';
		}
	}
	str[++i] = NULL;
	return (str);
}
