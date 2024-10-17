/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:17:31 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:02:58 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_chrchacker(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*ptr;
	size_t	end;
	size_t	i;

	while (str && ft_chrchacker(set,*str))
		str++;
	end = ft_strlen(str);
	while (end > 0 && str[end - 1] && ft_chrchacker(set, str[end - 1]))
		end--;
	ptr = (char *)malloc(sizeof(char) * (end + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < end)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[end] = '\0';
	return (ptr);
}
