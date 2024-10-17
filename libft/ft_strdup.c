/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:09:01 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:59:52 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len + 1);
	return (dup);
}
